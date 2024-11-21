class Num:
    def __init__(self,num) :
        self.num=num
    def printNum(self):
        print(f"The number is: {self.num}")
    def pow(self):
        return self.num**2
    def naTreta(self):
        return self.num**3

num=Num(int(input("Num:")))
num.printNum()
print(num.pow())
print(num.naTreta())