for i in range(1,11):
    print(i)

result=''
for letter in range(ord('a'), ord('f')+1):
    print(chr(letter), end=' ')
print()
for n in range(1,20):
    if n==5:
        continue
    if n==11:
        break
    print(n,end=" ")

print()
for n in range(20,10,-2):
    print(n,end=" ")