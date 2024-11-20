import random
numbers=[]
for i in range(10):
   numbers.append(random.randint(1,100))
print(numbers)
for num in range(0,len(numbers)*2-2,2):
    numbers.insert(num+1,numbers[num]+numbers[num+1])

print(numbers)