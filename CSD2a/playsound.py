#Imports

import simpleaudio as sa

#define

def Playsample():
                wave_obj = sa.WaveObject.from_wave_file("../ressound/Chime.wav")
                play_obj = wave_obj.play()
                play_obj.wait_done()



#code

print('What shoud thou be called?')

username = input()

print("Give me a number")

user_input = input()

while not str.isnumeric(user_input):
    print('Thou must enter a number')
    user_input = input()

else:
    user_int = int(user_input)
    while user_int > 0:
        Playsample()
        user_int = user_int - 1
        print(user_int)
    else:
        print('Well done')
