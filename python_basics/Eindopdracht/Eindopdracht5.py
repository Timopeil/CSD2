##################################################
## User input time signature and amount of bars ##
##################################################
import os
import math

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
            print("input error: number in argument 3 can not be less then 1, math error")
        elif not math.log(int(user_parameters[2]), 2).is_integer():
            print("input error: number in argument 3 is illigal")
        elif not user_parameters[3].isnumeric() and not int(user_parameters[3]) < 1:
            print("input error: number in argument 4 is illigal")
        else: break
    print(user_parameters)
    return user_parameters



print("uuuuh")
ask_user_parameters()

#print("Good or bad?")

#user_input_GorB = input()

#while not user_input_GorB == 'good' or not user_input_GorB == 'bad' or not user_input_GorB == 'Good' or not user_input_GorB =='Bad':
#    print("Good or bad?")
#    user_input_GorB = input()
#else:
#    if user_input_GorB == 'good' or user_input_GorB == 'Good':
#        marcov_to_midi(mchain) #TODO make this function
#        print("Well done")
#    elif user_input_GorB == "bad" or user_input_GorB == "Bad":
#        ask_user_parameters()
