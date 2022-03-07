nim2 = {}
with open("nim2.in", "r+") as f:
    for line in f:
        nims = line.split()
        for nim in nims:
            nim2[nim] = 1

notexist = {}
with open("nim1.in", "r+") as f:
    for line in f:
        nims = line.split()
        for nim in nims:
            if (nim not in nim2):
                notexist[nim] = 1
id = 1                
for k in notexist:
    print(str(id) + ". " + k)
    id += 1
