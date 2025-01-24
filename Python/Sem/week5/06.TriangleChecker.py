
def is_triangle(a,b,c):
            try:
                a=int(a)
                b=int(b)
                c=int(c)
                if a <= 0 or b<=0 or c<=0:
                    raise ArithmeticError("Нищо няма да стане с отрицателни числа!")
                elif(c>=a+b or b>=a+c or a>=b+c):
                    raise Exception("Жалко, не можете да направите триъгълник от това!")
                else:
                    print("Ура можете да направите триъгълник от това!")
                    return [a,b,c]
            except ValueError:
                print("Трябва да въведете само числа!")
            except ArithmeticError as e:
                print(f"{e}")  
            except Exception as e:
                print(f"{e}")
class TriangleChecker:
    def __init__(self,sides):
        sides=is_triangle(sides[0],sides[1],sides[2])
        self.a=sides[0]
        self.b=sides[1]
        self.c=sides[2]
t=TriangleChecker([4,2,3])
t=TriangleChecker([-4,2,3])
t=TriangleChecker([1,2,3])
t=TriangleChecker(["d",2,3])


