numbers=[]
for i in range(101):
    if(i%2==0 or i%5==0):
        numbers.append(i)
numbers.reverse()
print(numbers)