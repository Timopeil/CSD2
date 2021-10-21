###############################
## Value list to time stamps ##
###############################

#Based on:
#https://github.com/ciskavriezenga/CSD_21-22/blob/master/csd2a/theorie/eindopdracht_snippets/1_while_with_timestamps.py
#all credits to it's creator

mchain = [0.284375, 0.284375, 0.569375, 0.569375, 0.141875, 0.141875, 0.839375, 0.141875, 0.094375, 0.18937500000000002, 0.7109393958333332, 0.7109393958333332, 2.1359431958333333]


import time
import simpleaudio as sa


# list with a rhythmic sequence in quarter notes
note_dur_seq = mchain
bpm = 40

# function to transform a sequence with durations in quarter notes into
# a sequence with durations in time (sec.)
def to_time_dur(src_seq, bpm):
    dst_seq = []
    dur_multiplyer = 60.0 / bpm

    # iterate through the source sequence, add duration values to destiation seq
    for note_dur in src_seq:
        dst_seq.append(note_dur * dur_multiplyer)

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
time_dur_seq = to_time_dur(note_dur_seq, bpm)
# transform the list with note duration into a list with timestamps
timestamp_seq = to_timestamp_seq(time_dur_seq)

print("Sequence with quarter note values:", note_dur_seq)
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
print("time zero:", time_zero)

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    if(now > ts):
        playmidinote(noteline[0])
        if timestamp_seq:
            ts = timestamp_seq.pop(0)
            noteline.pop(0)
        else:
            break

    time.sleep(0.001)
