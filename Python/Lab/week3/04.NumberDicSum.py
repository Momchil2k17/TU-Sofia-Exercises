n=int(input('n= '))
numbers=[x for x in range(1,n+1)]
numbers.reverse()
d=dict()
for i in range(1,len(numbers)+1):
    d[i]=numbers[i-1]
print(d)