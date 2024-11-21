class Arithmetic:
    def __init__(self,num1,num2):
        self.num1=num1
        self.num2=num2
    def printNums(self):
        print(f"The numbers are: {self.num1} and {self.num2}")
    def printSum(self):
        print(f"{self.num1}+{self.num2}={self.num1+self.num2}")
    def printRazlika(self):
        print(f"{self.num1}-{self.num2}={self.num1-self.num2}")
    def printMultiplication(self):
        print(f"{self.num1}*{self.num2}={self.num1*self.num2}")
    def printDivide(self):
        if(self.num2==0):
            while(self.num2==0):
                self.num2=int(input("Cannot divide by zero, please enter a valid num:"))
        print(f"{self.num1}/{self.num2}={self.num1/self.num2:.2f}")
ar=Arithmetic(int(input("Num1:")),int(input("Num2:")))

ar.printNums()
ar.printSum()
ar.printRazlika()
ar.printMultiplication()
ar.printDivide()
    