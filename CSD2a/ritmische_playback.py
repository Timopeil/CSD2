# imports
import time
import simpleaudio as sa
import soundfile as sf

#definements

def Playsample():
                wave_obj = sa.WaveObject.from_wave_file("../ressound/Shakeup.wav")
                play_obj = wave_obj.play()

##Learn music
bpm = 60
def Note_len(x):
    return float(bpm)/float(x)/60
def Tuplet(x,y):
    return float(x)/float(y)
def Dotted(x):
    return x + 0.5 * x

#calc lengt file
f = sf.SoundFile("../ressound/Shakeup.wav")

audio_dur = (format(len(f) / f.samplerate))

#code
measure = [Dotted(1),1,Tuplet(1,3),0.5,Tuplet(1,3),1,0.5,Tuplet(1,3)]

for t in measure:
    note_dur = Note_len(t)
    if float(note_dur) > float(audio_dur):
        Playsample()
        time.sleep(float(note_dur) - float(audio_dur))
    else:
        Playsample()
        time.sleep(note_dur)
