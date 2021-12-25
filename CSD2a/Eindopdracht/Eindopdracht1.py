#####################
## Markov's Brain! ##
#####################

import random as ra

debug = "true"

#set data
# This list will be constructed in Marcov_schets3.py
LearnMusic = [
    {"Main":4, "variables":[
        {"value":1,"chance_up":0.5,"chance_dwn":0},
        {"value":2,"chance_up":1,"chance_dwn":0.5},
     ]
    },
    {"Main":3,"variables":[
        {"value":1,"chance_up":0.5,"chance_dwn":0},
        {"value":2,"chance_up":1,"chance_dwn":0.5},
     ]
    },
    {"Main":2,"variables":[
        {"value":0.5,"chance_up":0.5,"chance_dwn":0},
        {"value":2,"chance_up":1,"chance_dwn":0.5},
     ]
    },
    {"Main":1,"variables":[
        {"value":3,"chance_up":0.5,"chance_dwn":0},
        {"value":2,"chance_up":1,"chance_dwn":0.5},
     ]
    },
    {"Main":0.5,"variables":[
        {"value":1,"chance_up":0.5,"chance_dwn":0},
        {"value":2,"chance_up":1,"chance_dwn":0.5},
     ]
    }
    ]

#definements
## Sets Markov starting point
mchain = []
def SetMSP(x):
    mchain.append(x)
    if debug:
        print("debug_MSP: Markov startingpoint set to", x)

##Tableroll rolls a value in the array by its corrospondong chance

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
SetMSP(4)
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
        Tableroll(LearnMusic)
        if debug:
            print("debug_user_int:",user_int)
        user_int -= 1
    else:
        print('Well done')
