// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	China01,	// pointer to sample array
	China01_SIZE,	// size of the sample array
	China01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"China01",	// sample name

	Cl,	// pointer to sample array
	Cl_SIZE,	// size of the sample array
	Cl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cl",	// sample name

	Clap01,	// pointer to sample array
	Clap01_SIZE,	// size of the sample array
	Clap01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clap01",	// sample name

	Clhat01,	// pointer to sample array
	Clhat01_SIZE,	// size of the sample array
	Clhat01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat01",	// sample name

	Clhat02,	// pointer to sample array
	Clhat02_SIZE,	// size of the sample array
	Clhat02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat02",	// sample name

	Clhat12,	// pointer to sample array
	Clhat12_SIZE,	// size of the sample array
	Clhat12_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat12",	// sample name

	Clhat13,	// pointer to sample array
	Clhat13_SIZE,	// size of the sample array
	Clhat13_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat13",	// sample name

	Clhat15,	// pointer to sample array
	Clhat15_SIZE,	// size of the sample array
	Clhat15_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Clhat15",	// sample name

	Cowbell01,	// pointer to sample array
	Cowbell01_SIZE,	// size of the sample array
	Cowbell01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cowbell01",	// sample name

	Crash01,	// pointer to sample array
	Crash01_SIZE,	// size of the sample array
	Crash01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash01",	// sample name

	Crash02,	// pointer to sample array
	Crash02_SIZE,	// size of the sample array
	Crash02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash02",	// sample name

	Crash11,	// pointer to sample array
	Crash11_SIZE,	// size of the sample array
	Crash11_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash11",	// sample name

	Cy0000,	// pointer to sample array
	Cy0000_SIZE,	// size of the sample array
	Cy0000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy0000",	// sample name

	Cy2525,	// pointer to sample array
	Cy2525_SIZE,	// size of the sample array
	Cy2525_SIZE,	//sampleindex. if at end of sample array sound is not playing
	48,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy2525",	// sample name

	Flam03,	// pointer to sample array
	Flam03_SIZE,	// size of the sample array
	Flam03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	49,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Flam03",	// sample name

	Fx01,	// pointer to sample array
	Fx01_SIZE,	// size of the sample array
	Fx01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	50,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Fx01",	// sample name

	Fx02,	// pointer to sample array
	Fx02_SIZE,	// size of the sample array
	Fx02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	51,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Fx02",	// sample name

	Fx03,	// pointer to sample array
	Fx03_SIZE,	// size of the sample array
	Fx03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	52,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Fx03",	// sample name

	Hfhat,	// pointer to sample array
	Hfhat_SIZE,	// size of the sample array
	Hfhat_SIZE,	//sampleindex. if at end of sample array sound is not playing
	53,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hfhat",	// sample name

	Kick05,	// pointer to sample array
	Kick05_SIZE,	// size of the sample array
	Kick05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	54,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick05",	// sample name

	Kick01,	// pointer to sample array
	Kick01_SIZE,	// size of the sample array
	Kick01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	55,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick01",	// sample name

	Kick02,	// pointer to sample array
	Kick02_SIZE,	// size of the sample array
	Kick02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	56,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick02",	// sample name

	Kick07,	// pointer to sample array
	Kick07_SIZE,	// size of the sample array
	Kick07_SIZE,	//sampleindex. if at end of sample array sound is not playing
	57,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick07",	// sample name

	Kick1050,	// pointer to sample array
	Kick1050_SIZE,	// size of the sample array
	Kick1050_SIZE,	//sampleindex. if at end of sample array sound is not playing
	58,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick1050",	// sample name

	Kick11,	// pointer to sample array
	Kick11_SIZE,	// size of the sample array
	Kick11_SIZE,	//sampleindex. if at end of sample array sound is not playing
	59,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick11",	// sample name

	Kick12,	// pointer to sample array
	Kick12_SIZE,	// size of the sample array
	Kick12_SIZE,	//sampleindex. if at end of sample array sound is not playing
	60,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick12",	// sample name

	Kick13,	// pointer to sample array
	Kick13_SIZE,	// size of the sample array
	Kick13_SIZE,	//sampleindex. if at end of sample array sound is not playing
	61,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick13",	// sample name

	Kick14,	// pointer to sample array
	Kick14_SIZE,	// size of the sample array
	Kick14_SIZE,	//sampleindex. if at end of sample array sound is not playing
	62,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick14",	// sample name

	Kick2510,	// pointer to sample array
	Kick2510_SIZE,	// size of the sample array
	Kick2510_SIZE,	//sampleindex. if at end of sample array sound is not playing
	63,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick2510",	// sample name

	Kick41,	// pointer to sample array
	Kick41_SIZE,	// size of the sample array
	Kick41_SIZE,	//sampleindex. if at end of sample array sound is not playing
	64,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick41",	// sample name

	Kick42,	// pointer to sample array
	Kick42_SIZE,	// size of the sample array
	Kick42_SIZE,	//sampleindex. if at end of sample array sound is not playing
	65,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick42",	// sample name

	Kick43,	// pointer to sample array
	Kick43_SIZE,	// size of the sample array
	Kick43_SIZE,	//sampleindex. if at end of sample array sound is not playing
	66,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Kick43",	// sample name

	Marmb01,	// pointer to sample array
	Marmb01_SIZE,	// size of the sample array
	Marmb01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	67,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Marmb01",	// sample name

	Oh50,	// pointer to sample array
	Oh50_SIZE,	// size of the sample array
	Oh50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	68,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh50",	// sample name

	Ophat03,	// pointer to sample array
	Ophat03_SIZE,	// size of the sample array
	Ophat03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	69,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat03",	// sample name

	Ophat04,	// pointer to sample array
	Ophat04_SIZE,	// size of the sample array
	Ophat04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	70,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat04",	// sample name

	Ophat01,	// pointer to sample array
	Ophat01_SIZE,	// size of the sample array
	Ophat01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	71,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ophat01",	// sample name

	Pdhat01,	// pointer to sample array
	Pdhat01_SIZE,	// size of the sample array
	Pdhat01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	72,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Pdhat01",	// sample name

	Pdhat02,	// pointer to sample array
	Pdhat02_SIZE,	// size of the sample array
	Pdhat02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	73,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Pdhat02",	// sample name

	Perc11,	// pointer to sample array
	Perc11_SIZE,	// size of the sample array
	Perc11_SIZE,	//sampleindex. if at end of sample array sound is not playing
	74,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Perc11",	// sample name

	Perc12,	// pointer to sample array
	Perc12_SIZE,	// size of the sample array
	Perc12_SIZE,	//sampleindex. if at end of sample array sound is not playing
	75,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Perc12",	// sample name

	Revcrash,	// pointer to sample array
	Revcrash_SIZE,	// size of the sample array
	Revcrash_SIZE,	//sampleindex. if at end of sample array sound is not playing
	76,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Revcrash",	// sample name

	Ride01,	// pointer to sample array
	Ride01_SIZE,	// size of the sample array
	Ride01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	77,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ride01",	// sample name

	Ride12,	// pointer to sample array
	Ride12_SIZE,	// size of the sample array
	Ride12_SIZE,	//sampleindex. if at end of sample array sound is not playing
	78,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ride12",	// sample name

	Ride13,	// pointer to sample array
	Ride13_SIZE,	// size of the sample array
	Ride13_SIZE,	//sampleindex. if at end of sample array sound is not playing
	79,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ride13",	// sample name

	Rim03,	// pointer to sample array
	Rim03_SIZE,	// size of the sample array
	Rim03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	80,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Rim03",	// sample name

	Rs,	// pointer to sample array
	Rs_SIZE,	// size of the sample array
	Rs_SIZE,	//sampleindex. if at end of sample array sound is not playing
	81,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Rs",	// sample name

	Sd1025,	// pointer to sample array
	Sd1025_SIZE,	// size of the sample array
	Sd1025_SIZE,	//sampleindex. if at end of sample array sound is not playing
	82,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd1025",	// sample name

	Sd5010,	// pointer to sample array
	Sd5010_SIZE,	// size of the sample array
	Sd5010_SIZE,	//sampleindex. if at end of sample array sound is not playing
	83,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd5010",	// sample name

	Sdst01,	// pointer to sample array
	Sdst01_SIZE,	// size of the sample array
	Sdst01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	84,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst01",	// sample name

	Sdst03,	// pointer to sample array
	Sdst03_SIZE,	// size of the sample array
	Sdst03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	85,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sdst03",	// sample name

	Shkr03,	// pointer to sample array
	Shkr03_SIZE,	// size of the sample array
	Shkr03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	86,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shkr03",	// sample name

	Snr05,	// pointer to sample array
	Snr05_SIZE,	// size of the sample array
	Snr05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	87,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr05",	// sample name

	Snr01,	// pointer to sample array
	Snr01_SIZE,	// size of the sample array
	Snr01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	88,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr01",	// sample name

	Snr02,	// pointer to sample array
	Snr02_SIZE,	// size of the sample array
	Snr02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	89,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr02",	// sample name

	Snr04,	// pointer to sample array
	Snr04_SIZE,	// size of the sample array
	Snr04_SIZE,	//sampleindex. if at end of sample array sound is not playing
	90,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr04",	// sample name

	Snr07,	// pointer to sample array
	Snr07_SIZE,	// size of the sample array
	Snr07_SIZE,	//sampleindex. if at end of sample array sound is not playing
	91,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr07",	// sample name

	Snr18,	// pointer to sample array
	Snr18_SIZE,	// size of the sample array
	Snr18_SIZE,	//sampleindex. if at end of sample array sound is not playing
	92,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr18",	// sample name

	Snr21,	// pointer to sample array
	Snr21_SIZE,	// size of the sample array
	Snr21_SIZE,	//sampleindex. if at end of sample array sound is not playing
	93,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr21",	// sample name

	Snr41,	// pointer to sample array
	Snr41_SIZE,	// size of the sample array
	Snr41_SIZE,	//sampleindex. if at end of sample array sound is not playing
	94,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr41",	// sample name

	Snr42,	// pointer to sample array
	Snr42_SIZE,	// size of the sample array
	Snr42_SIZE,	//sampleindex. if at end of sample array sound is not playing
	95,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr42",	// sample name

	Snr43,	// pointer to sample array
	Snr43_SIZE,	// size of the sample array
	Snr43_SIZE,	//sampleindex. if at end of sample array sound is not playing
	96,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snr43",	// sample name

	Snrbuzz,	// pointer to sample array
	Snrbuzz_SIZE,	// size of the sample array
	Snrbuzz_SIZE,	//sampleindex. if at end of sample array sound is not playing
	97,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snrbuzz",	// sample name

	Snroff08,	// pointer to sample array
	Snroff08_SIZE,	// size of the sample array
	Snroff08_SIZE,	//sampleindex. if at end of sample array sound is not playing
	98,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Snroff08",	// sample name

	Tamb02,	// pointer to sample array
	Tamb02_SIZE,	// size of the sample array
	Tamb02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	99,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tamb02",	// sample name

	Tom01,	// pointer to sample array
	Tom01_SIZE,	// size of the sample array
	Tom01_SIZE,	//sampleindex. if at end of sample array sound is not playing
	100,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom01",	// sample name

	Tom02,	// pointer to sample array
	Tom02_SIZE,	// size of the sample array
	Tom02_SIZE,	//sampleindex. if at end of sample array sound is not playing
	101,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom02",	// sample name

	Tom03,	// pointer to sample array
	Tom03_SIZE,	// size of the sample array
	Tom03_SIZE,	//sampleindex. if at end of sample array sound is not playing
	102,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom03",	// sample name

	Tom05,	// pointer to sample array
	Tom05_SIZE,	// size of the sample array
	Tom05_SIZE,	//sampleindex. if at end of sample array sound is not playing
	103,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom05",	// sample name

	Tom08,	// pointer to sample array
	Tom08_SIZE,	// size of the sample array
	Tom08_SIZE,	//sampleindex. if at end of sample array sound is not playing
	104,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom08",	// sample name

	Tom09,	// pointer to sample array
	Tom09_SIZE,	// size of the sample array
	Tom09_SIZE,	//sampleindex. if at end of sample array sound is not playing
	105,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom09",	// sample name

	Tom11,	// pointer to sample array
	Tom11_SIZE,	// size of the sample array
	Tom11_SIZE,	//sampleindex. if at end of sample array sound is not playing
	106,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom11",	// sample name

	Tom12,	// pointer to sample array
	Tom12_SIZE,	// size of the sample array
	Tom12_SIZE,	//sampleindex. if at end of sample array sound is not playing
	107,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom12",	// sample name

	Tom75,	// pointer to sample array
	Tom75_SIZE,	// size of the sample array
	Tom75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	108,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom75",	// sample name

	Tomhc00,	// pointer to sample array
	Tomhc00_SIZE,	// size of the sample array
	Tomhc00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	109,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tomhc00",	// sample name

	Tomht10,	// pointer to sample array
	Tomht10_SIZE,	// size of the sample array
	Tomht10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	110,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tomht10",	// sample name

	Tomlc50,	// pointer to sample array
	Tomlc50_SIZE,	// size of the sample array
	Tomlc50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	111,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tomlc50",	// sample name

};
