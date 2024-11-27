class Building:
    def __init__(self,height,area,adress):
        self.height=height
        self.area=area
        self.adress=adress
    def printInfo(self):
        return f"Adress: {self.adress} Height: {self.height} Area: {self.area}"

class House(Building):
    def __init__(self,height,area,adress,floors,owner):
        super().__init__(height,area,adress)
        self.floors=floors
        self.owner=owner

    def printInfo(self):
        super().printInfo()
        return super().printInfo()+ f" Floors: {self.floors} Owner: {self.owner}"

h1=House(100,321.4,"Opulchenska 5",15,"Doncho Kirilov")
h2=House(50,241.5,"Lesovska 13",7,"Gabriel Bari")
h3=House(120,350.2,"Manastirska 3",17,"Laplaz Peev")

print(h1.printInfo())
print(h2.printInfo())
print(h3.printInfo())

houses=[h1,h2,h3]

def widestHouse(houses):
    widest=0
    houseInfo=""
    for house in houses:
       if(house.height/house.floors>widest):
           widest=house.height/house.floors
           houseInfo=house.printInfo()
    print(f"The widest house is with height/floor {widest:.2f}")
    print(f"{houseInfo}")

widestHouse(houses)
