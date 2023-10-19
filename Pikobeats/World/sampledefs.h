// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	Thumb_piano13120bpm,	// pointer to sample array
	Thumb_piano13120bpm_SIZE,	// size of the sample array
	Thumb_piano13120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano13120bpm",	// sample name

	Thumb_piano14120bpm,	// pointer to sample array
	Thumb_piano14120bpm_SIZE,	// size of the sample array
	Thumb_piano14120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano14120bpm",	// sample name

	Thumb_piano15120bpm,	// pointer to sample array
	Thumb_piano15120bpm_SIZE,	// size of the sample array
	Thumb_piano15120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano15120bpm",	// sample name

	Thumb_piano16120bpm,	// pointer to sample array
	Thumb_piano16120bpm_SIZE,	// size of the sample array
	Thumb_piano16120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano16120bpm",	// sample name

	Thumb_piano17120bpm,	// pointer to sample array
	Thumb_piano17120bpm_SIZE,	// size of the sample array
	Thumb_piano17120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano17120bpm",	// sample name

	Thumb_piano18120bpm,	// pointer to sample array
	Thumb_piano18120bpm_SIZE,	// size of the sample array
	Thumb_piano18120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Thumb_piano18120bpm",	// sample name

	Udu_28120bpm,	// pointer to sample array
	Udu_28120bpm_SIZE,	// size of the sample array
	Udu_28120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_28120bpm",	// sample name

	Udu_29120bpm,	// pointer to sample array
	Udu_29120bpm_SIZE,	// size of the sample array
	Udu_29120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_29120bpm",	// sample name

	Udu_30120bpm,	// pointer to sample array
	Udu_30120bpm_SIZE,	// size of the sample array
	Udu_30120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_30120bpm",	// sample name

	Udu_31120bpm,	// pointer to sample array
	Udu_31120bpm_SIZE,	// size of the sample array
	Udu_31120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_31120bpm",	// sample name

	Udu_32120bpm,	// pointer to sample array
	Udu_32120bpm_SIZE,	// size of the sample array
	Udu_32120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_32120bpm",	// sample name

	Udu_33120bpm,	// pointer to sample array
	Udu_33120bpm_SIZE,	// size of the sample array
	Udu_33120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_33120bpm",	// sample name

	Udu_34120bpm,	// pointer to sample array
	Udu_34120bpm_SIZE,	// size of the sample array
	Udu_34120bpm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Udu_34120bpm",	// sample name

};
