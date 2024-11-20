n=int(input('n= '))
t1=()
t2=()
digits=[]
while(n>0):
    digits.append(n%10)
    n=n//10
t1=tuple(digits)
digits.reverse()
t2=tuple(digits)
print(t2)
print(t1)
    