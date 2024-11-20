num=int(input("Enter n= " ))
if num<=1:
    print("Простите числа започват от 2")
    exit()
for i in range(2,num):
    if num%i==0:
        print("Съставно число")
        exit()
print('Просто число')