#############################################
## Make a midi file from the played mchain ##
#############################################

from midiutil import MIDIFile

#autofill some data in the midifile, i cant make a system for everything right now. < Fun #TODO if time_alive_left == Infinite:
midifile = MIDIFile(1)
midifile.addTrackName(0, 0, "Track")
midifile.addTempo(0, 0, 120)


#Ultra dictionary unpacker to midi file
def marcov_to_midi(notelist,notevaluelist):
    newtime = 0
    for note in notelist and duration in notevaluelist:
        midifile.addNote(0, 10, note , newtime, duration , 100)
        newtime = newtime + duration
