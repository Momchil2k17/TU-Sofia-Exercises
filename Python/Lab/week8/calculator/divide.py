def divide(a,b):
    try:
        a=int(a)
        b=int(b)
    except TypeError:
        print("Invalid numbers")
    try:
        print(f"{a}/{b}={a/b}")
    except ZeroDivisionError:
        print("Can't divide by zero")