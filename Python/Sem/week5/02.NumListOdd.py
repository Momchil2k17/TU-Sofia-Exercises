import random

class Num:
    def __init__(self,num):
        self.num=num
    
def createObjects(count):
    nums=[]
    for i in range(count):
        nums.append(Num(random.randint(-100,100)*2))
    for num in nums:
        print(num.num)
createObjects(6)