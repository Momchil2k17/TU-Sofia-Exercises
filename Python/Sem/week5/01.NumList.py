class Nums:
    def __init__(self,numList):
        self.numList=self.validateList(numList)
    def validateList(self,numList):
        validatedList=[]
        for i in range(len(numList)):
            if (type(numList[i]) is int):
                validatedList.append(numList[i])
        return validatedList
    def showList(self):
        print(f"{self.numList}")
    def avg(self):
        print(f"{sum(self.numList)/len(self.numList):.2f}")
    
l=Nums([1,4,"fgas",5,"fasd"])

l.showList()
l.avg()