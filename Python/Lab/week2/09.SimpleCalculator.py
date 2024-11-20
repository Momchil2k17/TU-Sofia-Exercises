num1=float(input("Enter num1: "))
num2=float(input("Enter num2: "))
operation=input("Type of operation: ")
if operation=='+':
    print(f'Sum of {num1} and {num2} = {num1+num2}')
elif operation=='-':
    print(f'Subtraction of {num1} and {num2} = {num1-num2}')
elif operation=='*':
    print(f'Multiplication of {num1} and {num2} = {num1*num2}')
elif operation=='/':
    if num2==0:
        print('Cant divide by zero')
    else:
        print(f'Divide of {num1} and {num2} = {num1/num2:.2f}')