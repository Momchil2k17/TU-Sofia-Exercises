class Person:
    def __init__(self,name,family,age,nationality):
        self.name=name
        self.family=family
        self.age=age
        self.nationality=nationality
    def printInfo(self):
        print(f"{self.name} {self.family} - Nationality: {self.nationality}")
p1=Person("Momchil","Yankov",19,"Bulgarian")
p2=Person("Bruce","Wayne",53,"American")
p3=Person("Kitodar","Todorov",47,"Bulgarian")

p1.printInfo()
p2.printInfo()
p3.printInfo()

#-------------------------

class Student(Person):
    def __init__(self,name,family,age,nationality,university,yearofstudy):
        super().__init__(name,family,age,nationality)
        self.university=university
        self.yearsofstudy=yearofstudy
    def printInfo(self):
        super().printInfo()
        print(f"University: {self.university} - {self.yearsofstudy}")
s1=Student("Momchil","Yankov",19,"Bulgarian","TU Sofia",2024)
s2=Student("Milcho","Angelov",23,"Austrian","AUBG",2020)
s3=Student("Lenche","Todorova",19,"German","SU Sofia",2024)

s1.printInfo()
s2.printInfo()
s3.printInfo()

#-------------------------
class Lecturer(Person):
    def __init__(self,name,family,age,nationality,university,experience):
        super().__init__(name,family,age,nationality)
        self.university=university
        self.experience=experience
    def printInfo(self):
        super().printInfo()
        print(f"University: {self.university} - Experience: {self.experience} years")

l1=Lecturer("Ivan","Koprinkov",61,"Bulgarian","TU Sofia",27)
l2=Lecturer("Dekan","Dekanov",52,"Romanian","MU Sofia",19)
l3=Lecturer("Rektor","Rektorov",48,"Serbian","TU Sofia",16)

l1.printInfo()
l2.printInfo()
l3.printInfo()