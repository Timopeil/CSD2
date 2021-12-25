#############################
## Annalisser de midi file ##
#############################

LearnMusic = []

#TODO: This list is constructed in Marcov_schets2.py
notevalue_line = [0.284375, 0.284375, 0.569375, 0.569375, 0.141875, 0.141875, 0.839375, 0.141875, 0.094375, 0.18937500000000002, 0.7109393958333332, 0.7109393958333332, 2.1359431958333333]

notevalue_line_count = list(dict.fromkeys(notevalue_line)) #remove upes
print(notevalue_line_count)


#we're making a list with dictionaries, in the dictionary ther's a vale Main,
#main will be the previous markov value. in variables is a table of possibilities for the next markov value in the chain with their corrosponding table of chances.

for Main_NvLc in notevalue_line_count:
        LearnMusic.append({"Main":Main_NvLc,"variables":[]})

print("LearnMusic After Main set:",LearnMusic)

#for every dictionary in the list "LearnMusic" this loop will creat list called baby, in this list their will be all the possibilities that were in the original midi file.
for dix_main in LearnMusic:
    beta = None
    baby = []
    for alpha in notevalue_line: #building the baby
        if beta == None:
           beta = alpha
        else:
           print("dixmain / beta / alpha",dix_main["Main"],beta,alpha)
           if dix_main["Main"] == beta:
              baby.append(alpha)
           beta = alpha
           print("baby:",baby)
           babydictionary = {}
    chance_up_past = 0
    for value in baby: #building the table
        babysplice = 1/len(baby)
        chance_dwn = chance_up_past
        chance_up = chance_up_past + babysplice
        table_dict = {"value":value,"chance_up":chance_up,"chance_dwn":chance_dwn}
        dix_main["variables"].append(table_dict)
        chance_up_past = chance_up


print("LearnMusic After Variables inclusion:",LearnMusic)
