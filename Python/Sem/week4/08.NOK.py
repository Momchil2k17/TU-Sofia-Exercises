def NOD(num1,num2):
    nod=1
    for i in range(1,min(num1,num2)):
        if num1%i==0 and num2%i==0:
            nod=i
    return nod

def NOK(num1,num2):
    print((num1*num2)/NOD(num1,num2))
    
NOK(16,18)