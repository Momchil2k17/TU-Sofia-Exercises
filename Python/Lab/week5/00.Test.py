def f(qty,item,price=0):
    print(f'{qty} {item} cost {price:.2f}')

f(6,"bananas",)


def psum(*k):
    result=0
    for i in k:
        result+=i
    return result


s=psum(1,2,3,4)
print(s)

num=10
L=lambda n:n*2+1

print("Нечети числа:")
for i in range(num):
    print(L(i),end=" ")

print('\nКвадрати на числата:')
for i in range(num):
    print((lambda x:x*x)(i+1),end=" ")