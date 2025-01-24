class numList:
    def __init__(self,list):
        self.numList=list


l1=numList([1,2,3,4,5,6,7,8])
l2=numList([1,2,3,4,5,6,7])

def sumOfClassObjects(l1,l2):
    sum=[]
    minL=min(len(l1.numList),len(l2.numList))
    for i in range(minL):
        sum.append(l1.numList[i]+l2.numList[i])
    if (len(l1.numList)>minL):
        for i in range(minL,len(l1.numList)):
            sum.append(l1.numList[i])
    if (len(l2.numList)>minL):
        for i in range(minL,len(l2.numList)):
            sum.append(l2.numList[i])
    return numList(sum)

print(sumOfClassObjects(l1,l2).numList)