
numList=[1,4,"fgas",5,"fasd"]
numList=[numList[x] for x in range(len(numList)) if type(numList[x]) is int]
print(numList)