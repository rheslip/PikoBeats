// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	Clhat01,	// pointer to sample array
	Clhat01_SIZE,	// size of the sample array
	Clhat01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat01",	// sample name

	Clhat02,	// pointer to sample array
	Clhat02_SIZE,	// size of the sample array
	Clhat02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat02",	// sample name

	Clhat03,	// pointer to sample array
	Clhat03_SIZE,	// size of the sample array
	Clhat03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat03",	// sample name

	Clhat04,	// pointer to sample array
	Clhat04_SIZE,	// size of the sample array
	Clhat04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat04",	// sample name

	Crash01,	// pointer to sample array
	Crash01_SIZE,	// size of the sample array
	Crash01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash01",	// sample name

	Crash02,	// pointer to sample array
	Crash02_SIZE,	// size of the sample array
	Crash02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash02",	// sample name

	Crash03,	// pointer to sample array
	Crash03_SIZE,	// size of the sample array
	Crash03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash03",	// sample name

	Crash04,	// pointer to sample array
	Crash04_SIZE,	// size of the sample array
	Crash04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash04",	// sample name

	Crash05,	// pointer to sample array
	Crash05_SIZE,	// size of the sample array
	Crash05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash05",	// sample name

	Crash06,	// pointer to sample array
	Crash06_SIZE,	// size of the sample array
	Crash06_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash06",	// sample name

	Crash07,	// pointer to sample array
	Crash07_SIZE,	// size of the sample array
	Crash07_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash07",	// sample name

	Hfhat,	// pointer to sample array
	Hfhat_SIZE,	// size of the sample array
	Hfhat_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hfhat",	// sample name

	Kick01,	// pointer to sample array
	Kick01_SIZE,	// size of the sample array
	Kick01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick01",	// sample name

	Kick02,	// pointer to sample array
	Kick02_SIZE,	// size of the sample array
	Kick02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	48,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick02",	// sample name

	Kick03,	// pointer to sample array
	Kick03_SIZE,	// size of the sample array
	Kick03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	49,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick03",	// sample name

	Ophat01,	// pointer to sample array
	Ophat01_SIZE,	// size of the sample array
	Ophat01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	50,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat01",	// sample name

	Ophat02,	// pointer to sample array
	Ophat02_SIZE,	// size of the sample array
	Ophat02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	51,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat02",	// sample name

	Ophat03,	// pointer to sample array
	Ophat03_SIZE,	// size of the sample array
	Ophat03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	52,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat03",	// sample name

	Rim01,	// pointer to sample array
	Rim01_SIZE,	// size of the sample array
	Rim01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	53,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Rim01",	// sample name

	Sdst01,	// pointer to sample array
	Sdst01_SIZE,	// size of the sample array
	Sdst01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	54,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst01",	// sample name

	Sdst02,	// pointer to sample array
	Sdst02_SIZE,	// size of the sample array
	Sdst02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	55,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst02",	// sample name

	Sdst03,	// pointer to sample array
	Sdst03_SIZE,	// size of the sample array
	Sdst03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	56,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst03",	// sample name

	Sdst04,	// pointer to sample array
	Sdst04_SIZE,	// size of the sample array
	Sdst04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	57,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst04",	// sample name

	Sdst05,	// pointer to sample array
	Sdst05_SIZE,	// size of the sample array
	Sdst05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	58,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst05",	// sample name

	Sdst06,	// pointer to sample array
	Sdst06_SIZE,	// size of the sample array
	Sdst06_SIZE,	//sampleindex. if at end of sample array sound is not playing
	59,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst06",	// sample name

	Sdst07,	// pointer to sample array
	Sdst07_SIZE,	// size of the sample array
	Sdst07_SIZE,	//sampleindex. if at end of sample array sound is not playing
	60,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst07",	// sample name

	Snr01,	// pointer to sample array
	Snr01_SIZE,	// size of the sample array
	Snr01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	61,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr01",	// sample name

	Snr02,	// pointer to sample array
	Snr02_SIZE,	// size of the sample array
	Snr02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	62,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr02",	// sample name

	Snr03,	// pointer to sample array
	Snr03_SIZE,	// size of the sample array
	Snr03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	63,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr03",	// sample name

	Snr04,	// pointer to sample array
	Snr04_SIZE,	// size of the sample array
	Snr04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	64,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr04",	// sample name

	Snr05,	// pointer to sample array
	Snr05_SIZE,	// size of the sample array
	Snr05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	65,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr05",	// sample name

	Snr06,	// pointer to sample array
	Snr06_SIZE,	// size of the sample array
	Snr06_SIZE,	//sampleindex. if at end of sample array sound is not playing
	66,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr06",	// sample name

	Snr07,	// pointer to sample array
	Snr07_SIZE,	// size of the sample array
	Snr07_SIZE,	//sampleindex. if at end of sample array sound is not playing
	67,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr07",	// sample name

	Snr08,	// pointer to sample array
	Snr08_SIZE,	// size of the sample array
	Snr08_SIZE,	//sampleindex. if at end of sample array sound is not playing
	68,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr08",	// sample name

	Snr09,	// pointer to sample array
	Snr09_SIZE,	// size of the sample array
	Snr09_SIZE,	//sampleindex. if at end of sample array sound is not playing
	69,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr09",	// sample name

	Snr10,	// pointer to sample array
	Snr10_SIZE,	// size of the sample array
	Snr10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	70,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr10",	// sample name

	Tom01,	// pointer to sample array
	Tom01_SIZE,	// size of the sample array
	Tom01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	71,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom01",	// sample name

	Tom04,	// pointer to sample array
	Tom04_SIZE,	// size of the sample array
	Tom04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	72,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom04",	// sample name

	Tom05,	// pointer to sample array
	Tom05_SIZE,	// size of the sample array
	Tom05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	73,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom05",	// sample name

};
