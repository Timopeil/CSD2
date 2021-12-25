######################################################################
## Load samples and link midi note to sample file and play the file ##
######################################################################
import simpleaudio as sa
import time

## Created in Eindopdracht2
note_line = [72, 74, 67, 69, 71, 72]

#Load the files:
snare = sa.WaveObject.from_wave_file("../../ressound/snare.wav")
kick = sa.WaveObject.from_wave_file("../../ressound/kick.wav")
hihat = sa.WaveObject.from_wave_file("../../ressound/hihat.wav")


#Easy algorhytm for chosing what sample to play per midinote, the numbers are chosen on general midi kick = 36 snare = 38 and hihat = 42.
#it will create biases based on key signtare if melodic material is inputed, however thats ok; since melodic material input is experimental use of this system.
drum_note_line = [] #we create this list so we can export to midi later.
def playmidinote(midinote):
    if midinote%12 > 5:
        hihat.play()
        drum_note_line.append(42)
    elif midinote%12 == 0 or midinote%12 == 1 or midinote%12 == 3:
        kick.play()
        drum_note_line.append(36)
    elif midinote%12 == 2 or midinote%12 == 4 or midinote%12 == 5:
        drum_note_line.append(38)
        snare.play()


for midinote in note_line:
    playmidinote(midinote)
    time.sleep(0.5)
