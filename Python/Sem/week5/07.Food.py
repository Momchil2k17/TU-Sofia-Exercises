def validate_number(num):
    while True:
        try:
            number = int(num)
            if number <= 0:
                raise ArithmeticError("Стойността тряба да е по-голяма от 0")
            else:
                return number
        except ValueError:
            print("Трябва да се въведат само числа")
        except ArithmeticError as e:
            print(f"{e}")  
        num = input("Въведете валидно число: ")

class Food:
    def __init__(self,carbs,protein,fat):
        self.carbs=validate_number(carbs)
        self.protein=validate_number(protein)
        self.fat=validate_number(fat)
    def calories(self):
        return (self.carbs+self.protein)*4+self.fat*9

# class Recipe:
#     def __init__(self) -> None:
        