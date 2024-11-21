# class MyFirstClass:
#     x=5
# MyFirstObject=MyFirstClass()
# print(MyFirstObject.x)

# class Person:
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
#     def grreetings(self):
#         print(f"Hello, my name is {self.name}")
# MyPerson=Person("Ivan",35)
# MyPerson.grreetings()
# MyPerson.name="Momo"
# print(MyPerson.name,MyPerson.age)
# print(MyPerson.age)
# MyPerson.grreetings()
# del MyPerson.name

# class Car:
#     #class attribute
#     car_type="sports"
#     def __init__(self,color):
#         #instance attribute
#         self.__color=color
#     def print_car(self):
#         print(self.__color,'\t',self.car_type)
#     def get_color(self):
#         return self.__color
#     def set_color(self,color):
#         self.__color=color
# car2=Car("yellow")
# car2.print_car()
# car2.__color="black" #can't change private attribute calue
# car2.print_car()
# print(car2.__color) #can't read private attribute outside in the class
# car2.set_color("green") #setter
# print(car2.get_color()) #getter
# car2.print_car()

class Person:
    def __init__(self,firstname,lastname):
        self.firstname=firstname
        self.lastname=lastname
    def printname(self):
        print(self.firstname,self.lastname)
p=Person("Momchil","Yankov")

class Student(Person):
    def __init__(self,firstname,lastname,year):
        super().__init__(firstname,lastname)
        self.grad=year
    def welcome(self):
        print(f"Welcome {self.firstname} {self.lastname} to the class of {self.grad}")
    def __str__(self):
        return f"{self.firstname} {self.lastname}"
s=Student("Student","Stidentov",2020)

s.welcome()
print(s)