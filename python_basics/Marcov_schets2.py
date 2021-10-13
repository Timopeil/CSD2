##########################################
# Schets voor Midi naar Markov Algoritme #
##########################################

#imports
import os
from mido import MidiFile

##Code
print("Give me any file")
input_file = input()

#check if input = a file
while not os.path.isfile(input_file):
    print('Thou must enter a file')
    input_file = input()

else:
    input_file = MidiFile(input_file , clip=True)
    print("debug_input_file:", input_file)
