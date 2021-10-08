
import random as ra

user_input = input()

while not str.isnumeric(user_input):
    print('Thou must enter a number')
    user_input = input()

else:
    user_int = int(user_input)
    while user_int > 0:
        print('Rannumber', ra.randint(0, 5))
        user_int = user_int - 1
        print('count' , user_int)
    else:
        print('Well done')

mchain = []
x = [
    {
        "value":1,
        "chance":0.5
    },
    {
        "value":2,
        "chance":1
    }
]

for table in x :
    roll = ra.random
    if table["chance"] < roll:
        append.mchain(table["value"])
    else:

print(mchain)
