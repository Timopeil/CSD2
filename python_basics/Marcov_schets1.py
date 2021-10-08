
import random as ra

mchain = []
x = [
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

roll = ra.random()

for table in x :
    print("Roll", roll)
    if table["chance_up"] > roll and table["chance_dwn"] < roll:
        mchain.append(table["value"])




print(mchain)
