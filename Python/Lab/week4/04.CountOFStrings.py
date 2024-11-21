s=input("Enter string: ")

sArr=s.lower().split(" ")

for i in range(len(sArr)):
    print(sArr[i]*len(sArr), end="")
print('-----')
for i in range(len(sArr)):
    print(sArr[i]*len(sArr[i]), end="")
