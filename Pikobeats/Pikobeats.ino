// Copyright 2023 Rich Heslip
//
// Author: Rich Heslip 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// 
// sample player inspired by Jan Ostman's ESP8266 drum machine http://janostman.wordpress.com
// completely rewritten for the Motivation Radio Eurorack module
// plays samples in response to gate/trigger inputs and MIDI note on messages
// will play any 22khz sample file converted to a header file in the appropriate format
// Feb 3/19 - initial version
// Feb 11/19 - sped up encoder/trigger ISR so it will catch 1ms pulses from Grids
// Jan 2023 - ported code to Pi Pico so I can use it on a 16mb flash version
// oct 2023 - ported to Pikocore Hardware and converted to a simple beatbox


#include <Arduino.h> 
#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"
#include "hardware/structs/ioqspi.h"
#include "hardware/structs/sio.h"
//#include "MIDI.h"
#include <PWMAudio.h>
#include "io.h"
#include "drumpatterns.h"

//#define MONITOR_CPU  // define to monitor Core 2 CPU usage on pin CPU_USE

#define SAMPLERATE 22050
//#define SAMPLERATE 44100 // VCC-GND 16mb flash boards won't overclock fast enough for 44khz ?

PWMAudio DAC(PWMOUT);  // 16 bit PWM audio

/* no MIDI for now
// MIDI stuff
uint8_t MIDI_Channel=10;  // default MIDI channel for percussion
struct SerialMIDISettings : public midi::DefaultSettings
{
  static const long BaudRate = 31250;
};


// must use HardwareSerial for extra UARTs
HardwareSerial MIDISerial(2);

// instantiate the serial MIDI library
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, MIDISerial, MIDI, SerialMIDISettings);
*/

#define NPOTS 3 // number of pots
uint16_t potvalue[NPOTS]; // pot readings
uint16_t lastpotvalue[NPOTS]; // old pot readings
bool potlock[NPOTS]; // when pots are locked it means they must change by MIN_POT_CHANGE to register
uint32_t pot_timer; // reading pots too often causes noise
#define POT_SAMPLE_TIME 30 // delay time between pot reads
#define MIN_POT_CHANGE 25 // locked pot reading must change by this in order to register
#define MIN_COUNTS 8  // unlocked pot must change by this in order to register
#define POT_AVERAGING 20 // analog sample averaging count 
#define POT_MIN 4   // A/D may not read min value of 0 so use a bit larger value for map() function
#define POT_MAX 1019 // A/D may not read max value of 1023 so use a bit smaller value for map() function

// flag all pot values as locked ie they have to change more than MIN_POT_CHANGE to register
void lockpots(void) {
  for (int i=0; i<NPOTS;++i) potlock[i]=1;
}

// sample analog pot input and do filtering. 
// if pots are locked, change value only if movement is greater than MIN_POT_CHANGE
uint16_t readpot(uint8_t potnum) {
    int val=0;
    int input;
    switch (potnum) { // map potnum to RP2040 pin
      case 0:
        input=AIN0;
        break;
      case 1:
        input=AIN1;
        break;
      case 2:
      default:   // shouldn't happen
        input=AIN2;
        break;     
    }
    // note that Pikocore pots are wired "backwards" - max voltage is full ccw
    for (int j=0; j<POT_AVERAGING;++j) val+=(1024-analogRead(input)); // read the A/D a few times and average for a more stable value
    val=val/POT_AVERAGING;
    if (potlock[potnum]) {
      int delta=lastpotvalue[potnum]-val;  // this needs to be done outside of the abs() function - see arduino abs() docs
      if (abs(delta) > MIN_POT_CHANGE) {
        potlock[potnum]=0;   // flag pot no longer locked
        potvalue[potnum]=lastpotvalue[potnum]=val; // save the new reading
      }
      else val=lastpotvalue[potnum];
    }
    else {
      if (abs(lastpotvalue[potnum]-val) > MIN_COUNTS) lastpotvalue[potnum]=val; // even if pot is unlocked, make sure pot has moved at least MIN_COUNT counts so values don't jump around
      else val=lastpotvalue[potnum];
      potvalue[potnum]=val; // pot is unlocked so save the reading
    }
    return val;
}

int current_track=0; // track we are working on

// we have 8 voices that can play any sample when triggered
// this structure holds the settings for each voice

#define NUM_VOICES 8
struct voice_t {
  int16_t sample;   // index of the sample structure in sampledefs.h
  int16_t level;   // 0-1000 for legacy reasons
  uint32_t sampleindex; // 20:12 fixed point index into the sample array
  uint16_t sampleincrement; // 1:12 fixed point sample step for pitch changes 
  bool isPlaying;  // true when sample is playing
} voice[NUM_VOICES] = {
  0,      // default voice 0 assignment - typically a kick but you can map them any way you want
  250,  // initial level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing
  
  1,      // default voice 1 assignment 
  250,
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  2,    // default voice 2 assignment 
  250, // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  3,    // default voice 3 assignment 
  250, // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  4,    // default voice 4 assignment 
  250,  // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  5,    // default voice 5 assignment 
  250,  // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  6,    // default voice 6 assignment 
  250,  // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch
  false, // sample not playing

  10,    // default voice 7 assignment 
  250,   // level
  0,    // sampleindex
  4096, // initial pitch step - normal pitch 
  false, // sample not playing
};  


// we can have an arbitrary number of samples but you will run out of memory at some point
// sound sample files are 22khz 16 bit signed PCM format - see the sample include files for examples
// you can change the sample rate to whatever you want but most testing was done at 22khz. 44khz probably works but not much testing was done

// use the wave2header22khz.exe utility to automagically batch convert all the .wav files in a directory into the required header files
// put your 22khz or 44khz PCM wav files in a sample subdirectory with a copy of the utility, run the utility and it will generate all the required header files
// wave2header creates a header file containing the signed PCM values for each sample - note that it may change the name of the file if required to make it "c friendly"
// wave2header also creates sampledefs.h which is an array of structures containing information about each sample file 
// the samples are arranged in alphabetical order to facilitate grouping samples by name - you can manually edit this file to change the order of the samples as needed
// sampledefs.h contains other information not used by this program e.g. the name of the sample file - I wrote it for another project
// wave2header also creates "samples.h" which #includes all the generated header files


//include "808samples/samples.h" // 808 sounds
//#include "Angular_Jungle_Set/samples.h"   // Jungle soundfont set - great!
#include "Angular_Techno_Set/samples.h"   // Techno
//#include "Acoustic3/samples.h"   // acoustic drums
//#include "Pico_kit/samples.h"   // assorted samples
//#include "testkit/samples.h"   // small kit for testing
//#include "Trashrez/samples.h"
//#include "world/samples.h"

#define NUM_SAMPLES (sizeof(sample)/sizeof(sample_t)) 

// sample and debounce the keys

#define NUM_BUTTONS 9 // 8 buttons plus USR button on VCC-GND board
#define SHIFT 8 // index of "shift" USR button 
uint8_t debouncecnt[NUM_BUTTONS] = {0,0,0,0,0,0,0,0,0}; // debounce counters
bool button[NUM_BUTTONS]={0,0,0,0,0,0,0,0,0};  // key active flags

 // scan buttons
bool scanbuttons(void)
{
  bool pressed;
  for (int i=0; i< NUM_BUTTONS;++i) {
    switch (i) { // sample gate inputs
      case 0:
        pressed=!digitalRead(BUTTON0); // active low key inputs
        break;
      case 1:
        pressed=!digitalRead(BUTTON1);
        break; 
      case 2:
        pressed=!digitalRead(BUTTON2);
        break;
      case 3:
        pressed=!digitalRead(BUTTON3);
        break;
      case 4:
        pressed=!digitalRead(BUTTON4);
        break;
      case 5:
        pressed=!digitalRead(BUTTON5);
        break;
       case 6:
        pressed=!digitalRead(BUTTON6);
        break;
      case 7:
        pressed=!digitalRead(BUTTON7);
        break;
      case 8:
        pressed=!digitalRead(SHIFTBUTTON);
        break;
    }
    
    if (pressed) { 
      if (debouncecnt[i]<=3) ++debouncecnt[i];
      if (debouncecnt[i]==2) { // trigger on second sample of key active
        button[i]=1;
      }
    }
    else {
      debouncecnt[i]=0;
      button[i]=0;
    }
  }
  if (pressed) return true;
  else return false;
}


/* no MIDI for now
// serial MIDI handler

void HandleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel==MIDI_Channel) {
      for (int i=0; i< NUM_SAMPLES;++i) {  // 
        if (sample[i].MIDINOTE == note) {
          sample[i].play_volume=velocity;  // use MIDI volume
          sample[i].sampleindex=0;  // if note matches sample MIDI note number, start it playing 
        }
      }
  }
}
*/

// include here to avoid forward references - I'm lazy :)
#include "seq.h"

#define DISPLAY_TIME 2000 // time in ms to display numbers on LEDS
int32_t display_timer;

// show a number in binary on the LEDs 
void display_value(int16_t value){
  for (int i=LED7; i>=LED0;--i) { // can loop this way because port assignments are sequential
    digitalWrite(i,value&1);
    value=value>>1;
  }
  display_timer=millis();
}

// rotate trigger pattern
uint16_t rightRotate(int shift, uint16_t value, uint8_t pattern_length) {
  uint16_t mask = ((1 << pattern_length) - 1);
  value &= mask;
  return ((value >> shift) | (value << (pattern_length - shift))) & mask;
}

// main core setup
void setup() {      

 Serial.begin(115200);

// Serial.print("Number of Samples ");
// Serial.println(NUM_SAMPLES);      

#ifdef MONITOR_CPU
  pinMode(CPU_USE, OUTPUT); // for monitoring CPU usage
#endif

  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);
  pinMode(BUTTON6, INPUT_PULLUP);
  pinMode(BUTTON7, INPUT_PULLUP);
  pinMode(SHIFTBUTTON, INPUT_PULLUP);

  pinMode(AIN0, INPUT);
  pinMode(AIN1, INPUT);
  pinMode(AIN2, INPUT);

  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);


// set up Pico PWM audio output
	DAC.setBuffers(4, 128); // DMA buffers 
	DAC.begin(SAMPLERATE);

/* no MIDI for now	
//  Set up serial MIDI port
  MIDISerial.begin(31250, SERIAL_8N1, MIDIRX,MIDITX ); // midi port

  // set up serial MIDI library callbacks
  MIDI.setHandleNoteOn(HandleNoteOn);  // 

  // Initiate serial MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);
  */

  seq[0].trigger=0b1000100010001000;

  display_value(NUM_SAMPLES); // show number of samples on the display

}




// main core handles UI
void loop() {
  bool anybuttonpressed;

  // UI handler 
  anybuttonpressed=false;
  for (int i=0;i<=SHIFT;++i) { // scan all the buttons
    if (button[i]) {
      anybuttonpressed=true;
      if (i==SHIFT) {  // shift button is pressed
        int newbpm=map(potvalue[0],POT_MIN,POT_MAX,50,305); // precalculate possible new BPM
        if(!potlock[0] && (bpm !=newbpm)) {
          bpm=newbpm; // set BPM
          display_value(bpm-50); // show BPM Pikocore style
        }
        if(!potlock[1]) voice[current_track].sampleincrement=(uint16_t)(map(potvalue[1],POT_MIN,POT_MAX,2048,8192)); // change sample pitch if pot has moved enough  
        if(!potlock[2]) voice[current_track].level=(int16_t)(map(potvalue[2],POT_MIN,POT_MAX,0,1000)); // change sample volume level if pot has moved enough   
      }
      else { // a track button is pressed
        current_track=i; // keypress selects track we are working on
        //if ((!potlock[1]) || (!potlock[2])) seq[i].trigger=euclid(16,map(potvalue[1],POT_MIN,POT_MAX,0,MAX_SEQ_STEPS),map(potvalue[2],POT_MIN,POT_MAX,0,MAX_SEQ_STEPS-1)); // set track euclidean triggers if either pot has moved enough
        if (!potlock[1]) seq[i].trigger= drumpatterns[map(potvalue[1],POT_MIN,POT_MAX,0,NUMPATTERNS-1)]; // look up drum trigger pattern
        if (!potlock[2]) seq[i].trigger= rightRotate(map(potvalue[2],POT_MIN,POT_MAX,0,MAX_SEQ_STEPS-1),seq[i].trigger,16); // rotate trigger pattern
        if(!potlock[0]) { // change sample if pot has moved enough
          int16_t newsample=(int16_t) map(potvalue[0],POT_MIN,POT_MAX,0,NUM_SAMPLES-1); // precompute new sample
          if (voice[i].sample != newsample) { 
            rp2040.idleOtherCore(); // don't mess with sample parameters while other core is running
            //voice[i].sample].sampleindex=sample[voice[i].sample].samplesize; // stop old one if its playing
            voice[i].sample = newsample;
            rp2040.resumeOtherCore(); // enable sample processing again
          }
        }
      }
    }
  }

  // lock pot settings when no keys are pressed so it requires more movement to change value
  // this is so when we change tracks we don't immediately change the settings on the new track 
  if (!anybuttonpressed) lockpots();  

// MIDI.read();  // do serial MIDI

  do_clocks();  // process sequencer clocks
  scanbuttons();

// reading A/D seems to cause noise in the audio so don't do it too often
  if ((millis()-pot_timer) > POT_SAMPLE_TIME) {
    readpot(0); readpot(1); readpot(2); // sample pots.
    pot_timer=millis();
  }

// if display is not busy show track triggers on leds
  if ((millis()-display_timer) > DISPLAY_TIME) {
    for (int i=LED0;i<=LED7;++i) { // LED port numbers are sequential on the Pikocore
      if (bitRead(seq[i-LED0].trigger,seq[i-LED0].index)) digitalWrite(i,1);
      else digitalWrite(i,0);
    }
  }
}

// second core setup
// second core dedicated to sample processing
void setup1() {
  delay (1000); // wait for main core to start up perhipherals
}

// second core calculates samples and sends to DAC
void loop1(){
  int32_t newsample,samplesum=0;
  uint32_t index;
  int16_t samp0,samp1,delta,tracksample;

 // oct 22 2023 resampling code
// to change pitch we step through the sample by .5 rate for half pitch up to 2 for double pitch
// sample.sampleindex is a fixed point 20:12 fractional number
// we step through the sample array by sampleincrement - sampleincrement is treated as a 1 bit integer and a 12 bit fraction
// for sample lookup sample.sampleindex is converted to a 20 bit integer which limits the max sample size to 2**20 or about 1 million samples, about 45 seconds 
  // oct 24/2023 - scan through voices instead of sample array
  // faster because there are only 8 voices vs typically 45 or more samples
/*
  for (int track=0; track< NTRACKS;++track) {  // look for samples that are playing, scale their volume, and add them up
    tracksample=voice[track].sample; // precompute for a little more speed below
    index=sample[tracksample].sampleindex>>12; // get the integer part of the sample increment
    if (index < sample[tracksample].samplesize) { // if sample is playing, do interpolation   
      samp0=sample[tracksample].samplearray[index]; // get the first sample to interpolate
      samp1=sample[tracksample].samplearray[index+1];// get the second sample
      delta=samp1-samp0;
      newsample=(int32_t)samp0+((int32_t)delta*((int32_t)sample[tracksample].sampleindex & 0x0fff))/4096; // interpolate between the two samples
      //samplesum+=((int32_t)samp0+(int32_t)delta*(sample[i].sampleindex & 0x0fff)/4096)*sample[i].play_volume;
      samplesum+=newsample*sample[tracksample].play_volume;
      sample[tracksample].sampleindex+=voice[track].sampleincrement; // add step increment
    }
  }
  */
  for (int track=0; track< NTRACKS;++track) {  // look for samples that are playing, scale their volume, and add them up
    tracksample=voice[track].sample; // precompute for a little more speed below
    index=voice[track].sampleindex>>12; // get the integer part of the sample increment
    if (index >= sample[tracksample].samplesize) voice[track].isPlaying=false; // have we played the whole sample?
    if (voice[track].isPlaying) { // if sample is still playing, do interpolation   
      samp0=sample[tracksample].samplearray[index]; // get the first sample to interpolate
      samp1=sample[tracksample].samplearray[index+1];// get the second sample
      delta=samp1-samp0;
      newsample=(int32_t)samp0+((int32_t)delta*((int32_t)voice[track].sampleindex & 0x0fff))/4096; // interpolate between the two samples
      //samplesum+=((int32_t)samp0+(int32_t)delta*(sample[i].sampleindex & 0x0fff)/4096)*sample[i].play_volume;
      samplesum+=(newsample*(127*voice[track].level))/1000;
      voice[track].sampleindex+=voice[track].sampleincrement; // add step increment
    }
  }

  samplesum=samplesum>>7;  // adjust for play_volume multiply above
  if  (samplesum>32767) samplesum=32767; // clip if sample sum is too large
  if  (samplesum<-32767) samplesum=-32767;



#ifdef MONITOR_CPU  
  digitalWrite(CPU_USE,0); // low - CPU not busy
#endif
 // write samples to DMA buffer - this is a blocking call so it stalls when buffer is full
	DAC.write(int16_t(samplesum)); // left

#ifdef MONITOR_CPU
  digitalWrite(CPU_USE,1); // hi = CPU busy
#endif
}


