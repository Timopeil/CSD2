############################
## Eindopdracht Timo Peil ##
############################

#imports
import random as ra
import os
from mido import MidiFile
import time
import simpleaudio as sa
import math
from midiutil import MIDIFile

##set debug mode
debug = True

#############################################
## Make a midi file from the played mchain ##
#############################################

#autofill some data in the midifile, i cant make a system for everything right now. < Fun #TODO if time_alive_left == Infinite:
midifile = MIDIFile(1)
midifile.addTrackName(0, 0, "Track")
midifile.addTempo(0, 0, 120)

#Ultra dictionary make and unpacker to midi file

def marcov_to_midi(notelist,notevaluelist):
    to_midi_dictionary = []
    index = 0
    for note in notelist: #we are making a listnested dictionary, linking midinote and noteduration : for every note {"note":midinote,"duration":noteduration}
        dictionary = {"note":note,"duration":notevaluelist[index]}
        to_midi_dictionary.append(dictionary)
        index += 1
        print(dictionary)
    print(to_midi_dictionary)
    temp_time = 0
    for note in to_midi_dictionary: #writing note to de midifile format in python using midiutil's MIDIFILE
        midifile.addNote(0, 9, note["note"] , temp_time , round(note["duration"]*100)/100 , 100)
        temp_time = temp_time + round(note["duration"]*128)/128
        print("temp_time:",temp_time)
    with open("midiout.mid","wb") as fileout: #writing midifile to path
        midifile.writeFile(fileout)

#ask the user for the input parameters, they must work with the program, so its filtered heavily to do so.
def ask_user_parameters():
    user_parameters = None

    while True:
        print("Difine parameters for the algorhytm <File.mid> <Numerator> <Denominator> <Amount of bars>")
        user_parameters = list(map(str,input().split()))
        if len(user_parameters) < 4:
            print("input error: not enough arguments")
        elif len(user_parameters) > 4:
            print("input error: too many arguments")
        elif not str(user_parameters[0]).endswith(".mid") or not str(user_parameters[0]).endswith(".MID") and not os.path.isfile(str(user_parameters[0])):
            print("input error: argument 1 is not a midi file or incorrect path")
        elif not user_parameters[1].isnumeric():
            print("input error: argument 2 is not a number")
        elif int(user_parameters[1]) < 0:
            print("input error: number in argument 2 is illigal")
        elif int(user_parameters[2]) < 0:
            print("input error: number in argument 3 can not be or be less then 0, math error")
        elif not math.log(int(user_parameters[2]), 2).is_integer():
            print("input error: number in argument 3 is illigal")
        elif not user_parameters[3].isnumeric() and not int(user_parameters[3]) < 1:
            print("input error: number in argument 4 is illigal")
        else: break
    if debug:
        print("user paramets:", user_parameters)
    return user_parameters


#ask user if the drumbeat is good or bad, if good it exports to midi and closes program, if bad the program stops without exporting midi.
def user_GorB():
    user_input_GorB = None
    while not user_input_GorB == 'good' or not user_input_GorB == 'bad' or not user_input_GorB == 'Good' or not user_input_GorB =='Bad':
        print("Good or bad?")
        user_input_GorB = input()
        if user_input_GorB == 'good' or user_input_GorB == 'Good':
            print("Well done!")
            marcov_to_midi(drum_note_line, mchain)
            break
        elif user_input_GorB == "bad" or user_input_GorB == "Bad":
            print("Verry sad.")
            break

user_parameters = ask_user_parameters()
max_bar_value = int(user_parameters[1])*1/int(user_parameters[2])*4 #set the maximum bar value, the 4 is because we count in quarternotes

##Midifile to python, also cut off all data in the midifile thats goes unused
input_file = MidiFile(user_parameters[0] , clip=True)
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
        notevalue_line.append(round(i["time"]*16)/16) # we round it here, just afer its extracted from the midifile
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

#Set markov's startingpoint
SetMSP(LearnMusic[0]["Main"])
if debug:
    print("debug_mchain", mchain)
    print("debug_markov value" , mchain[0])


##Tableroll rolls a value in the list by its corrospondong chance this is the markovchain
bar_count = int(user_parameters[3])
bar_value = 0
while not bar_count == 0:
    roll = ra.random()
    if debug:
        print('debug_roll:' , roll)
    for section in LearnMusic :
        mchain.reverse()
        if section["Main"] == mchain[0] :
            if debug: print("debug_reversemchain", mchain)
            storetable = section["variables"]
            for table in storetable :
                if table["chance_up"] > roll and table["chance_dwn"] < roll:
                    if round(bar_value) + table["value"] > max_bar_value: #basic math, if the bar would be full or overflow,
                        print("we did the code")                          #fill up the remaining (if any) and break out of the for loop to go back to the while loop
                        mchain.reverse()
                        if not round(max_bar_value-bar_value) == 0: #rounding is difficult! please.
                            mchain.append(round(max_bar_value-bar_value))
                        print(mchain)
                        bar_count -= 1
                        bar_value = 0
                        break
                    else:
                        print("Barvalue",bar_value + table["value"] , "<", "max_bar_value", max_bar_value)
                        mchain.reverse()
                        mchain.append(table["value"])
                        bar_value = bar_value + table["value"]
                        if debug:
                            print("debug_mchain", mchain)
                            print("debug_markov value" , mchain[0])
        else:
            mchain.reverse()
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

user_GorB()
