def sqroot():
    while True:
        num=input()
        try:
            num=int(num)
            if(num<0):
                raise ArithmeticError("Number must be greater or equal to zero")
            else:
                print(num**0.5)
                break
        except ValueError:
            print("Input must be a number")
        except ArithmeticError as e:
            print(e)
  

sqroot()