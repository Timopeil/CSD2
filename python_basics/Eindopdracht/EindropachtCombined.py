########################################
## Schets voor Midi naar Python Lijst ##
########################################

#imports
import random as ra
import os
from mido import MidiFile
import time
import simpleaudio as sa

##set debug mode
debug = True

##Code
print("Give me a midi file")
input_file = input()
print(input_file)
#check if input = a midi file
while not input_file.endswith(".mid") or not input_file.endswith(".MID") and not os.path.isfile(input_file):
    print('Thou must enter a midi file')
    input_file = input()
else:
    input_file = MidiFile(input_file , clip=True)
    if debug:
        print("debug_input_file:", input_file)

## Put all note on in midinote as dictionary

note_line_dict = []
note_line = []

#Turn midi file into python dictionary
for i in input_file:
    if i.type == 'note_on':
        note_line_dict.append(i.dict())

#Extract note_on pitch information
for i in note_line_dict:
    if i["velocity"] > 0 and not i["type"] == "note_off":
        note_line.append(i["note"])
if debug:
    print("Debug_note_Line", note_line)

#Extract notevalue

notevalue_line = []
notevalue_line_mem = 0.

for i in note_line_dict:    #if note value is 0 it means it was a polyphonic paralel so it can count as the last notevalue input
    if i["velocity"] == 0 or i["type"] == "note_off":
        notevalue_line.append(i["time"])
if debug:
    print("debug_notevalue_line:", notevalue_line)

#########################
## Annalyse  midi file ##
#########################

LearnMusic = []

notevalue_line_count = list(dict.fromkeys(notevalue_line)) #remove upes
print(notevalue_line_count)


#we're making a list with dictionaries, in the dictionary ther's a vale Main,
#main will be the previous markov value. in variables is a table of possibilities for the next markov value in the chain with their corrosponding table of chances.

for Main_NvLc in notevalue_line_count:
        LearnMusic.append({"Main":Main_NvLc,"variables":[]})
if debug:
    print("LearnMusic After Main set:",LearnMusic)

#for every dictionary in the list "LearnMusic" this loop will creat list called baby, in this list their will be all the possibilities that were in the original midi file.
for dix_main in LearnMusic:
    beta = None
    baby = []
    for alpha in notevalue_line: #building the baby
        if beta == None:
           beta = alpha

        else:
           if debug:
                print("dixmain / beta / alpha",dix_main["Main"],beta,alpha)
           if dix_main["Main"] == beta:
              baby.append(alpha)
           beta = alpha
           if debug:
               print("baby:",baby)
    if len(baby) == 0: #baby cant be empty due to devide by 0 later in code, but it might be because the last note value in the midi file is unique to the midi file.
                       #to fix this it will go on as if the last note came before the first note.
        baby.append(LearnMusic[1]["Main"])
    chance_up_past = 0
    for value in baby: #building the table
        print("we went to the for loop")
        babysplice = 1/len(baby)
        chance_dwn = chance_up_past
        chance_up = chance_up_past + babysplice
        table_dict = {"value":value,"chance_up":chance_up,"chance_dwn":chance_dwn}
        dix_main["variables"].append(table_dict)
        chance_up_past = chance_up

if debug:
    print("LearnMusic After Variables inclusion:",LearnMusic)

#####################
## Markov's Brain! ##
#####################

## Sets Markov starting point
mchain = []
def SetMSP(x):
    mchain.append(x)
    if debug:
        print("debug_MSP: Markov startingpoint set to", x)

##Tableroll rolls a value in the list by its corrospondong chance

def Tableroll(x):

    roll = ra.random()
    if debug:
        print('debug_roll:' , roll)

    for section in x :
        mchain.reverse()
        if section["Main"] == mchain[0] :
            if debug: print("debug_reversemchain", mchain)
            storetable = section["variables"]
            for table in storetable :
                if table["chance_up"] > roll and table["chance_dwn"] < roll:
                    mchain.reverse()
                    mchain.append(table["value"])
                    if debug:
                        print("debug_mchain", mchain)
                        print("debug_markov value" , mchain[0])
        else:
            mchain.reverse()

#Code
SetMSP(LearnMusic[0]["Main"])
if debug:
    print("debug_mchain", mchain)
    print("debug_markov value" , mchain[0])

print("Give me a number")

user_input = input()

while not str.isnumeric(user_input):
    print('Thou must enter a number')
    user_input = input()

else:
    user_int = int(user_input) - 1 #asks the user for amount of mchain repetitions #TODO change this to bars in combination with Eindopdacht 5
    while user_int > 0:
        Tableroll(LearnMusic)
        if debug:
            print("debug_user_int:",user_int)
        user_int -= 1
    else:
        print('Well done')

###############################
## Value list to time stamps ##
###############################

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

#Based on:
#https://github.com/ciskavriezenga/CSD_21-22/blob/master/csd2a/theorie/eindopdracht_snippets/1_while_with_timestamps.py
#all credits to it's creator


# function to transform a sequence with durations in quarter notes into
# a sequence with durations in time (sec.)
def to_time_dur(src_seq):
    dst_seq = []
    # iterate through the source sequence, add duration values to destiation seq
    for note_dur in src_seq:
        dst_seq.append(note_dur)

    return dst_seq


# function to transform a sequence with durations in time (sec.) into
# a sequence with timestamps
def to_timestamp_seq(src_seq):
    dst_seq = []
    timestamp = 0
    # iterate through the source sequence, sum durations and store these as
    # timestamp in the destination Sequence
    for time_dur in src_seq:
        dst_seq.append(timestamp)
        timestamp = timestamp + time_dur

    return dst_seq

# call the to_time function and store the restulting sequence
time_dur_seq = to_time_dur(mchain)
# transform the list with note duration into a list with timestamps
timestamp_seq = to_timestamp_seq(time_dur_seq)

if debug:
    print("Sequence with quarter note values:", mchain)
    print("Sequence with duration values in seconds:", time_dur_seq)
    print("Sequence with timestamp values in seconds:", timestamp_seq)


# retrieve the first time stamp
if timestamp_seq:
    ts = timestamp_seq.pop(0)
else:
    # list contains no items
    exit()

# store the current time
time_zero = time.time()
if debug:
    print("time zero:", time_zero)

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    if(now > ts):
        if debug:
            print(note_line)
        playmidinote(note_line[ra.randint(1,len(note_line)-1)])
        if timestamp_seq:
            ts = timestamp_seq.pop(0)
            print("timestamp_seq_after_pop:",timestamp_seq)
        else:
            time.sleep(1)
            break

    time.sleep(0.001)

if debug:
    print(drum_note_line)
#end based on
#https://github.com/ciskavriezenga/CSD_21-22/blob/master/csd2a/theorie/eindopdracht_snippets/1_while_with_timestamps.py
#all credits to it's creator
