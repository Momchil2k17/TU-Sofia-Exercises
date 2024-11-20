n=int(input("Enter n= " ))
sumOfEven=0
proizvedenieOdd=1
for i in range(0,n):
    num=int(input("Enter num= " ))
    if num%2==0:
        sumOfEven+=num
    else:
        proizvedenieOdd*=num
print(f"Sum of even: {sumOfEven}")
print(f'Proizvedenie odd: {proizvedenieOdd}')
