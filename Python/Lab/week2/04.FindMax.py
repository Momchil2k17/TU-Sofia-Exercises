
n=int(input("Enter n= " ))
if n<=0:
    n=int(input("Please enter a num greater than 0: " ))

import sys
max_size = sys.maxsize
min_size = -sys.maxsize - 1
max=min_size

for i in range(n):
    currentNum=int(input("Entern num: "))
    if currentNum>max:
        max=currentNum
print(max)
