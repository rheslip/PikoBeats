// sequencer related definitions and structures
#define NTRACKS 8   // we have 8 track sequences
#define MAX_SEQ_STEPS 16 // up to 16 step sequencer
#define DEFAULT_SEQ_STEPS 16 // up to 16 step sequencer

#define TEMPO    120 // default tempo
#define PPQN 24  // clocks per quarter note
#define NOTE_DURATION (PPQN/6) // sixteenth note duration
#define CLOCKPULSE 15 // duration of clock out pulse
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
};

// notes are stored as offsets from the root 
sequencer seq[NTRACKS] = {
  0b1000100010001000, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

  0, // triggers
  DEFAULT_SEQ_STEPS-1,   // step index

};

// clock all the sequencers
// clockperiod is the period of the 24ppqn clock - used for calculating gate times etc - not used as yet
// it loops thru all tracks looking for trigger events to process
void clocktick (long clockperiod) {

  for (uint8_t track=0; track<NTRACKS;++track) { // note that triggers are stored MSB first
    if (bitRead(seq[track].trigger,seq[track].index)) {
      voice[track].sampleindex=0; // trigger sample for this track
      voice[track].isPlaying=true;
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
    digitalWrite(CLOCKOUT,1); // external clock high
  }
  if ((millis() - clocktimer) > CLOCKPULSE) digitalWrite(CLOCKOUT,0); // external clock low
}

