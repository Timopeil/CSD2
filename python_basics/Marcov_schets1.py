
import random as ra

debug = "true"

#set data
Wholenote = [
    {
        "value":1,
        "chance_up":0.5,
        "chance_dwn":0
    },
    {
        "value":2,
        "chance_up":1,
        "chance_dwn":0.5
    }
]

Halfnote = [
    {
        "value":2,
        "chance_up":1,
        "chance_dwn":0
    }


]

Quarternote = [
    {
        "value":0,
        "chance_up":0,
        "chance_dwn":0
    }
]

#definements
## Sets Markov starting point
mchain = []
def SetMSP(x):
    mchain.append(x)
    if debug:
        print("debug_MSP: Markov startingpoint set to", x)

##LearnMusic Translates note values to corrospondong datavalues
def LearnMusic(x):
    if x == 4:
        return Wholenote
    elif x == 2:
        return Halfnote
    elif x == 1:
        return Quarternote
    elif x == 1/5:
        return Tuplet1_5


##Tableroll rolls a value in the array by its corrospondong chance
def Tableroll(x):

    roll = ra.random()
    if debug:
        print('debug_roll' , roll)

    for table in x :

        if table["chance_up"] > roll and table["chance_dwn"] < roll:
            mchain.append(table["value"])
            if debug:
                print("debug_mchain", mchain)
                print("debug_markov value" , mchain[0])

#Code
SetMSP(2)
if debug:
    print("debug_mchain", mchain)
    print("debug_markov value" , mchain[0])
    print("Give me a number")

user_input = input()

while not str.isnumeric(user_input):
    print('Thou must enter a number')
    user_input = input()

else:
    user_int = int(user_input)
    while user_int > 0:
        Tableroll(LearnMusic(mchain[0]))
        if debug:
            print("debug_user_int:",user_int)
        user_int -= 1
    else:
        print('Well done')
