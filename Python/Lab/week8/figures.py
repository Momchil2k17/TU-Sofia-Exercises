def triangle(a,b,c):
    a=int(a)
    b=int(b)
    c=int(c)

    p=(a+b+c)/2

    area=(p*(p-a)*(p-b)*(p-c)**0.5)

    print(f"Area: {area}")

def square(a):
    a=int(a)
    print(f"Area: {a*a}")

def rectangle(a,b):
    a=int(a)
    b=int(b)
    print(f"Area: {a*b}")

def trapezoid(a,b,h):
    a=int(a)
    b=int(b)
    h=int(h)


    area=((a+b)*h/2)

    print(f"Area: {area}")

def romb(a,h):
    a=int(a)
    h=int(h)
    print(f"Area: {a*h}")
