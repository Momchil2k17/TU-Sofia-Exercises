def multiply(a,b):
    try:
        a=int(a)
        b=int(b)
    except TypeError:
        print("Invalid numbers")
    print(f"{a}*{b}={a*b}")