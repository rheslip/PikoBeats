# PikoBeats
 Drum sequencer for the Pikocore

Demo and tutorial https://youtu.be/xZunAcSZHI8
 
Alternate firmware for the Pikocore designed by Zack Scholl https://infinitedigits.co/wares/pikocore/
Please visit Zack's site to buy a Pikocore, a kit, or a PCB - its a really fun little sample glitcher.

This firmware is based on a couple of other projects - Pico Drums and Pico Sequencer. Its an 8 track sample player with a 16 beat Eulidean trigger sequencer per track.

This firmware requires an RP2040 board compatible with the one on the Pikocore which has larger flash and a USR button. The smaller images provided may run on a Raspberry Pi Pico board but you will not have access to some functions.

Controls:

To select a track - press and hold one of the 8 main buttons

While holding a track button, use the left pot to change the sample 

While holding a track button, use the 2nd from left left pot to change the Euclidean fill (number of triggers)

While holding a track button, use the 3rd from left left pot to rotate the trigger pattern

The "shift" button (USR button on the Pico processor board) provides some alternate functions for the pots:

While holding the shift button, use the left pot to set the BPM. BPM readout on the LEDs is the same as on the Pikocore.

While holding the shift button, use the 3rd from left pot to set the volume for the last track button pressed.

Right pot is master volume - same as Pikocore.

Written with Arduino 2.1 with Pico Arduino RP2040 board support package installed. See https://arduino-pico.readthedocs.io/en/latest/

See the tutorial video and notes in the code for instructions on how to change the sample set. A couple of sample UF2 binaries are provided in the build directory which can be installed as per the Pikocore instructions.

First version Oct 19 2023
