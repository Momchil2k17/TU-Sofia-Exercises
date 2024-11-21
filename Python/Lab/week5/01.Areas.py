def squareArea(a):
    print(f"Area: {a*a}")
def rectangleArea(a,b):
    print(f"Area: {a*b}")
def triangleArea(a,b):
    print(f"Area: {a*b/2}")

figure=int(input("Type of figure: "))
a=int(input("a= "))
if(figure==1):
    squareArea(a)
elif(figure==2):
    b=int(input("b= "))
    rectangleArea(a,b)
elif(figure==3):
    b=int(input("b= "))
    triangleArea(a,b)
else:
    print("Invalid figure")
