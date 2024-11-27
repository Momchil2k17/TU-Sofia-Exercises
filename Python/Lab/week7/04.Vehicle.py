class Vehicle:
    def __init__(self,wheels,model,color):
        self.wheels=wheels
        self.model=model
        self.color=color
    def printInfo(self):
        return f"Wheels: {self.wheels} Model: {self.model} Color: {self.color}"

class LuxCar(Vehicle):
    def __init__(self,wheels,model,color,passengers):
        super().__init__(wheels,model,color)
        self.passengers=passengers
    def printInfo(self):
        return super().printInfo()+ f" Passengers: {self.passengers}"    
    
    
class SportsCar(Vehicle):
    def __init__(self,wheels,model,color,loadlimit):
        super().__init__(wheels,model,color)
        self.loadlimit=loadlimit
    def printInfo(self):
        return super().printInfo()+ f" Loadlimit: {self.loadlimit} kg"    
    
l1=LuxCar(4,"Lamborghini","green",2)
l2=LuxCar(4,"Ferrari","red",3)

print(l1.printInfo())
print(l2.printInfo())

s1=SportsCar(4,"Ford","yellow",1000)
s2=SportsCar(4,"Renault","black",2000)

print(s1.printInfo())
print(s2.printInfo())
