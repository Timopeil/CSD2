########################################
## Schets voor Midi naar Python Lijst ##
########################################

#imports
import os
from mido import MidiFile

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

print("Debug_note_Line", note_line)

#Extract notevalue

notevalue_line = []
notevalue_line_mem = 0.

for i in note_line_dict:    #if note value is 0 it means it was a polyphonic paralel so it can count as the last notevalue input
    if i["velocity"] == 0 or i["type"] == "note_off":
        if i["time"] == 0:
            notevalue_line.append(notevalue_line_mem)
        else:
            notevalue_line.append(i["time"])
            notevalue_line_mem = i["time"]

print("debug_notevalue_line:", notevalue_line)
