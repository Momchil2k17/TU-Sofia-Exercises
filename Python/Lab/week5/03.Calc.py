def calc(num1,num2,operator):
    if(operator=="+"):
        print(f"{num1}+{num2}={num1+num2}")
    elif(operator=="-"):
        print(f"{num1}-{num2}={num1-num2}")
    elif(operator=="*"):
        print(f"{num1}*{num2}={num1*num2}")
    elif(operator=="/"):
        if(num2==0):
            num2=int(input("Cant divide by zero, please enter a new num: "))
        print(f"{num1}/{num2}={num1/num2}")

num1=int(input("num1: "))
num2=int(input("num2: "))
operator=input("operator: ")

calc(num1,num2,operator)