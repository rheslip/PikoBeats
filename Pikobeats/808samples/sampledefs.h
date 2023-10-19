// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	Bd0000,	// pointer to sample array
	Bd0000_SIZE,	// size of the sample array
	Bd0000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bd0000",	// sample name

	Bd1000,	// pointer to sample array
	Bd1000_SIZE,	// size of the sample array
	Bd1000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bd1000",	// sample name

	Bd2550,	// pointer to sample array
	Bd2550_SIZE,	// size of the sample array
	Bd2550_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bd2550",	// sample name

	Cb,	// pointer to sample array
	Cb_SIZE,	// size of the sample array
	Cb_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cb",	// sample name

	Ch,	// pointer to sample array
	Ch_SIZE,	// size of the sample array
	Ch_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ch",	// sample name

	Cl,	// pointer to sample array
	Cl_SIZE,	// size of the sample array
	Cl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cl",	// sample name

	Cp,	// pointer to sample array
	Cp_SIZE,	// size of the sample array
	Cp_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cp",	// sample name

	Cy0000,	// pointer to sample array
	Cy0000_SIZE,	// size of the sample array
	Cy0000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy0000",	// sample name

	Cy0025,	// pointer to sample array
	Cy0025_SIZE,	// size of the sample array
	Cy0025_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy0025",	// sample name

	Cy1000,	// pointer to sample array
	Cy1000_SIZE,	// size of the sample array
	Cy1000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy1000",	// sample name

	Cy1025,	// pointer to sample array
	Cy1025_SIZE,	// size of the sample array
	Cy1025_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy1025",	// sample name

	Cy7525,	// pointer to sample array
	Cy7525_SIZE,	// size of the sample array
	Cy7525_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cy7525",	// sample name

	Hc00,	// pointer to sample array
	Hc00_SIZE,	// size of the sample array
	Hc00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hc00",	// sample name

	Hc10,	// pointer to sample array
	Hc10_SIZE,	// size of the sample array
	Hc10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	48,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hc10",	// sample name

	Hc25,	// pointer to sample array
	Hc25_SIZE,	// size of the sample array
	Hc25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	49,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hc25",	// sample name

	Hc50,	// pointer to sample array
	Hc50_SIZE,	// size of the sample array
	Hc50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	50,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hc50",	// sample name

	Hc75,	// pointer to sample array
	Hc75_SIZE,	// size of the sample array
	Hc75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	51,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hc75",	// sample name

	Ht00,	// pointer to sample array
	Ht00_SIZE,	// size of the sample array
	Ht00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	52,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ht00",	// sample name

	Ht10,	// pointer to sample array
	Ht10_SIZE,	// size of the sample array
	Ht10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	53,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ht10",	// sample name

	Ht25,	// pointer to sample array
	Ht25_SIZE,	// size of the sample array
	Ht25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	54,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ht25",	// sample name

	Ht50,	// pointer to sample array
	Ht50_SIZE,	// size of the sample array
	Ht50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	55,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ht50",	// sample name

	Ht75,	// pointer to sample array
	Ht75_SIZE,	// size of the sample array
	Ht75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	56,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ht75",	// sample name

	Lc00,	// pointer to sample array
	Lc00_SIZE,	// size of the sample array
	Lc00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	57,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lc00",	// sample name

	Lc10,	// pointer to sample array
	Lc10_SIZE,	// size of the sample array
	Lc10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	58,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lc10",	// sample name

	Lc25,	// pointer to sample array
	Lc25_SIZE,	// size of the sample array
	Lc25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	59,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lc25",	// sample name

	Lc50,	// pointer to sample array
	Lc50_SIZE,	// size of the sample array
	Lc50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	60,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lc50",	// sample name

	Lc75,	// pointer to sample array
	Lc75_SIZE,	// size of the sample array
	Lc75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	61,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lc75",	// sample name

	Lt00,	// pointer to sample array
	Lt00_SIZE,	// size of the sample array
	Lt00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	62,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lt00",	// sample name

	Lt10,	// pointer to sample array
	Lt10_SIZE,	// size of the sample array
	Lt10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	63,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lt10",	// sample name

	Lt25,	// pointer to sample array
	Lt25_SIZE,	// size of the sample array
	Lt25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	64,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lt25",	// sample name

	Lt50,	// pointer to sample array
	Lt50_SIZE,	// size of the sample array
	Lt50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	65,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lt50",	// sample name

	Lt75,	// pointer to sample array
	Lt75_SIZE,	// size of the sample array
	Lt75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	66,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lt75",	// sample name

	Ma,	// pointer to sample array
	Ma_SIZE,	// size of the sample array
	Ma_SIZE,	//sampleindex. if at end of sample array sound is not playing
	67,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ma",	// sample name

	Mt00,	// pointer to sample array
	Mt00_SIZE,	// size of the sample array
	Mt00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	68,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mt00",	// sample name

	Mt10,	// pointer to sample array
	Mt10_SIZE,	// size of the sample array
	Mt10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	69,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mt10",	// sample name

	Mt25,	// pointer to sample array
	Mt25_SIZE,	// size of the sample array
	Mt25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	70,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mt25",	// sample name

	Mt50,	// pointer to sample array
	Mt50_SIZE,	// size of the sample array
	Mt50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	71,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mt50",	// sample name

	Mt75,	// pointer to sample array
	Mt75_SIZE,	// size of the sample array
	Mt75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	72,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mt75",	// sample name

	Oh00,	// pointer to sample array
	Oh00_SIZE,	// size of the sample array
	Oh00_SIZE,	//sampleindex. if at end of sample array sound is not playing
	73,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh00",	// sample name

	Oh10,	// pointer to sample array
	Oh10_SIZE,	// size of the sample array
	Oh10_SIZE,	//sampleindex. if at end of sample array sound is not playing
	74,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh10",	// sample name

	Oh25,	// pointer to sample array
	Oh25_SIZE,	// size of the sample array
	Oh25_SIZE,	//sampleindex. if at end of sample array sound is not playing
	75,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh25",	// sample name

	Oh50,	// pointer to sample array
	Oh50_SIZE,	// size of the sample array
	Oh50_SIZE,	//sampleindex. if at end of sample array sound is not playing
	76,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh50",	// sample name

	Oh75,	// pointer to sample array
	Oh75_SIZE,	// size of the sample array
	Oh75_SIZE,	//sampleindex. if at end of sample array sound is not playing
	77,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Oh75",	// sample name

	Rs,	// pointer to sample array
	Rs_SIZE,	// size of the sample array
	Rs_SIZE,	//sampleindex. if at end of sample array sound is not playing
	78,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Rs",	// sample name

	Sd0000,	// pointer to sample array
	Sd0000_SIZE,	// size of the sample array
	Sd0000_SIZE,	//sampleindex. if at end of sample array sound is not playing
	79,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd0000",	// sample name

	Sd0010,	// pointer to sample array
	Sd0010_SIZE,	// size of the sample array
	Sd0010_SIZE,	//sampleindex. if at end of sample array sound is not playing
	80,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd0010",	// sample name

	Sd0025,	// pointer to sample array
	Sd0025_SIZE,	// size of the sample array
	Sd0025_SIZE,	//sampleindex. if at end of sample array sound is not playing
	81,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd0025",	// sample name

	Sd0050,	// pointer to sample array
	Sd0050_SIZE,	// size of the sample array
	Sd0050_SIZE,	//sampleindex. if at end of sample array sound is not playing
	82,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd0050",	// sample name

	Sd7525,	// pointer to sample array
	Sd7525_SIZE,	// size of the sample array
	Sd7525_SIZE,	//sampleindex. if at end of sample array sound is not playing
	83,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd7525",	// sample name

	Sd7550,	// pointer to sample array
	Sd7550_SIZE,	// size of the sample array
	Sd7550_SIZE,	//sampleindex. if at end of sample array sound is not playing
	84,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd7550",	// sample name

	Sd7575,	// pointer to sample array
	Sd7575_SIZE,	// size of the sample array
	Sd7575_SIZE,	//sampleindex. if at end of sample array sound is not playing
	85,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Sd7575",	// sample name

};
