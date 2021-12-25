#############################################
## Make a midi file from the played mchain ##
#############################################

from midiutil import MIDIFile

#autofill some data in the midifile, i cant make a system for everything right now. < Fun #TODO if time_alive_left == Infinite:
midifile = MIDIFile(1)
midifile.addTrackName(0, 0, "Track")
midifile.addTempo(0, 0, 120)


drum_note_line=  [42, 36, 42, 38, 42, 36, 42, 38, 42, 38, 42, 38, 42, 36,]
mchain = [0.49895833333333334, 0.9979166666666667, 0.9979166666666667, 1.496875, 1.496875, 1.9958333333333333, 1.9958333333333333, 2.4947916666666665, 2.4947916666666665, 2.99375, 2.99375, 3.2427083333333333, 3.4916666666666667, 3.740625]
print("len drum_note_line:",len(drum_note_line),"len mchain:",len(mchain))

#Ultra dictionary unpacker to midi file

def marcov_to_midi(notelist,notevaluelist):
    to_midi_dictionary = []
    index = 0
    for note in notelist: #we are making a listnested dictionary, linking midinote and noteduration : for every note {"note":midinote,"duration":noteduration}
        dictionary = {"note":note,"duration":notevaluelist[index]}
        to_midi_dictionary.append(dictionary)
        index += 1
        print(dictionary)
    print(to_midi_dictionary)
    newtime = 0
    for note in to_midi_dictionary: #writing note to de midifile format in python using midiutil's MIDIFILE
        midifile.addNote(0, 9, note["note"] , newtime, note["duration"] , 100)
        newtime = newtime + note["duration"]
    print(newtime)
    with open("midiout.mid","wb") as fileout: #writing midifile to path
        midifile.writeFile(fileout)



marcov_to_midi(drum_note_line, mchain)
print(midifile)
