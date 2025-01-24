import math
       
def validate_number(num):
    while True:
        try:
            number = int(num)
            if number <= 0:
                raise ArithmeticError("The number must be greater than zero.")
            else:
                return number
        except ValueError:
            print("Error: Invalid input. Please enter a valid integer.")
        except ArithmeticError as e:
            print(f"Arithmetic Error: {e}")  
        num = input("Enter a valid number: ")

class Shape:
    def __init__(self,type):
        self.type=type
    def area(self):
        print("Area is 0")

class Circle(Shape):
    def __init__(self, type,radius):
        super().__init__(type)
        self.radius=validate_number(radius)
    def area(self):
        print(f"Area is {self.radius*self.radius*math.pi:.2f}")

class Square(Shape):
    def __init__(self, type,a):
        super().__init__(type)
       
        self.a=validate_number(a)
    def area(self):
        print(f"Area is {self.a*self.a}")

figure=input("Please enter a shape (s/c/sq): ")
if figure=="s":
    s=Shape("Shape")
    s.area()
elif figure=="c":
    r=input("Please enter the radius of the circle: ")
    c=Circle("Circle",r)
    c.area()
elif figure=="sq":
    a=input("Please enter the side of the square: ")
    sq=Square("Square",a)
    sq.area()

