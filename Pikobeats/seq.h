// sequencer related definitions and structures
#define NTRACKS 8   // we have 8 track sequences
#define MAX_SEQ_STEPS 16 // up to 16 step sequencer
#define DEFAULT_SEQ_STEPS 16 // up to 16 step sequencer

#define TEMPO    120 // default tempo
#define PPQN 24  // clocks per quarter note
#define NOTE_DURATION (PPQN/6) // sixteenth note duration
int16_t bpm = TEMPO;
int32_t lastMIDIclock; // timestamp of last MIDI clock
int16_t MIDIclocks=PPQN*2; // midi clock counter
int16_t MIDIsync = 16;  // number of clocks required to sync BPM
int16_t useMIDIclock = 0; // true if we are using MIDI clock
long clocktimer = 0; // clock rate in ms


// all of the sequencers use the same data structure even though the data may be different in each case
// this simplifies the code somewhat
// clocks are setup for 24ppqn MIDI clock
// note that there are two threads of execution running on the two Pico cores - UI and note handling
// must be careful about editing items that are used by the 2nd Pico core for note timing etc

struct sequencer {
  uint16_t trigger;  // bit map of triggers MSB first
  int16_t index;    // index of step we are on
  int16_t state;    // state  - unused
  int16_t euclen;   // euclidean length - not used at the moment, done inline in the UI
  int16_t eucbeats;   // euclidean beats - ""
  int16_t eucoffset;   // euclidean offset - ""
};

// notes are stored as offsets from the root 
sequencer seq[NTRACKS] = {
  0b1000100010001000, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index
  0,     // state - used for step modes
  DEFAULT_SEQ_STEPS, // euclidean length
  1, //  euclidean beats
  0,   // euclidean offset
 
};

// clock all the sequencers
// clockperiod is the period of the 24ppqn clock - used for calculating gate times etc - not used as yet
// it loops thru all tracks looking for trigger events to process
void clocktick (long clockperiod) {

  for (uint8_t track=0; track<NTRACKS;++track) { // note that triggers are stored MSB first
    if (bitRead(seq[track].trigger,seq[track].index)) {
      sample[voice[track].sample].sampleindex=0; // trigger sample for this track
      sample[voice[track].sample].play_volume=127*voice[track].level/1000;     // default volume level to play
    }
    if ((--seq[track].index) <0) seq[track].index=DEFAULT_SEQ_STEPS-1; // restart the sequence at end
  }

}
 

// must be called regularly for sequencer to run
// hard wired to 16th notes at the moment
void do_clocks(void) {
  //long clockperiod= (long)(((60.0/(float)bpm)/PPQN)*1000);
  long clockperiod= (long)(((60.0/(float)bpm)/NOTE_DURATION)*1000);
  if ((millis() - clocktimer) > clockperiod) {
    clocktimer=millis(); 
    clocktick(clockperiod);
  }
}


// Euclidean calculation functions from http://clsound.com/euclideansequenc.html

/*Function to right rotate n by d bits*/

uint16_t rightRotate(int shift, uint16_t value, uint8_t pattern_length) {
  uint16_t mask = ((1 << pattern_length) - 1);
  value &= mask;
  return ((value >> shift) | (value << (pattern_length - shift))) & mask;
}

// Function to find the binary length of a number by counting bitwise
int findlength(unsigned int bnry) {
  boolean lengthfound = false;
  int length = 1; // no number can have a length of zero - single 0 has a length of one, but no 1s for the sytem to count
  for (int q = 32; q >= 0; q--) {
    int r = bitRead(bnry, q);
    if (r == 1 && lengthfound == false) {
      length = q + 1;
      lengthfound = true;
    }
  }
  return length;
}

// Function to concatenate two binary numbers bitwise
unsigned int ConcatBin(unsigned int bina, unsigned int binb) {
  int binb_len = findlength(binb);
  unsigned int sum = (bina << binb_len);
  sum = sum | binb;
  return sum;
}

uint16_t euclid(int n, int k, int o) { // inputs: n=total, k=beats, o = offset
  int pauses = n - k;
  int pulses = k;
  int offset = o;
  int steps = n;
  int per_pulse = pauses / k;
  int remainder = pauses % pulses;
  unsigned int workbeat[n];
  unsigned int outbeat;
  uint16_t outbeat2;
  unsigned int working;
  int workbeat_count = n;
  int a;
  int b;
  int trim_count;

  for (a = 0; a < n; a++) { // Populate workbeat with unsorted pulses and pauses
    if (a < pulses) {
      workbeat[a] = 1;
    }
    else {
      workbeat[a] = 0;
    }
  }

  if (per_pulse > 0 && remainder < 2) { // Handle easy cases where there is no or only one remainer
    for (a = 0; a < pulses; a++) {
      for (b = workbeat_count - 1; b > workbeat_count - per_pulse - 1; b--) {
        workbeat[a] = ConcatBin(workbeat[a], workbeat[b]);
      }
      workbeat_count = workbeat_count - per_pulse;
    }

    outbeat = 0; // Concatenate workbeat into outbeat - according to workbeat_count
    for (a = 0; a < workbeat_count; a++) {
      outbeat = ConcatBin(outbeat, workbeat[a]);
    }

    if (offset > 0) {
      outbeat2 = rightRotate(offset, outbeat, steps); // Add offset to the step pattern
    }
    else {
      outbeat2 = outbeat;
    }

    return outbeat2;
  }

  else {
    if (pulses == 0) {
      pulses = 1;  //	Prevent crashes when k=0 and n goes from 0 to 1
    }
    int groupa = pulses;
    int groupb = pauses;
    int iteration = 0;
    if (groupb <= 1) {
    }

    while (groupb > 1) { //main recursive loop
      /*Serial.print("Pulses: ");		//	Help debug crash
        Serial.println(pulses);
        Serial.print("Pauses: ");
        Serial.println(pauses);
        Serial.print("Iterations: ");
        Serial.println(iteration);*/
      if (groupa > groupb) { // more Group A than Group B
        int a_remainder = groupa - groupb; // what will be left of groupa once groupB is interleaved
        trim_count = 0;
        for (a = 0; a < groupa - a_remainder; a++) { //count through the matching sets of A, ignoring remaindered
          workbeat[a] = ConcatBin(workbeat[a], workbeat[workbeat_count - 1 - a]);
          trim_count++;
        }
        workbeat_count = workbeat_count - trim_count;

        groupa = groupb;
        groupb = a_remainder;
      }

      else if (groupb > groupa) { // More Group B than Group A
        int b_remainder = groupb - groupa; // what will be left of group once group A is interleaved
        trim_count = 0;
        for (a = workbeat_count - 1; a >= groupa + b_remainder; a--) { //count from right back through the Bs
          workbeat[workbeat_count - a - 1] = ConcatBin(workbeat[workbeat_count - a - 1], workbeat[a]);

          trim_count++;
        }
        workbeat_count = workbeat_count - trim_count;
        groupb = b_remainder;
      }

      else if (groupa == groupb) { // groupa = groupb
        trim_count = 0;
        for (a = 0; a < groupa; a++) {
          workbeat[a] = ConcatBin(workbeat[a], workbeat[workbeat_count - 1 - a]);
          trim_count++;
        }
        workbeat_count = workbeat_count - trim_count;
        groupb = 0;
      }

      else {
        //Serial.println("ERROR");
      }
      iteration++;
    }

    outbeat = 0; // Concatenate workbeat into outbeat - according to workbeat_count
    for (a = 0; a < workbeat_count; a++) {
      outbeat = ConcatBin(outbeat, workbeat[a]);
    }

    if (offset > 0) {
      outbeat2 = rightRotate(offset, outbeat, steps); // Add offset to the step pattern
    }
    else {
      outbeat2 = outbeat;
    }

    return outbeat2;
  }
}

//------------------end euclidian math-------------------------
