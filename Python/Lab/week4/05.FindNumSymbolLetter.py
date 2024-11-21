s=input("Enter string: ")
numbers=[]
letters=[]
symbols=[]

for i in range(len(s)):
    if(s[i].isdigit()):
        numbers.append(s[i])
    elif(s[i].isalpha()):
        letters.append(s[i])
    else:
        symbols.append(s[i])
print(numbers)
print(letters)
print(symbols)