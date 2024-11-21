def removeBiggerThanNum(numbers,num):
    for i in range(len(numbers)):
        if(numbers[i]>num):
            numbers[i]=0
    print(numbers)


numbers=[]
for i in range(5):
    currentNum=int(input("Enter num: "))
    numbers.append(currentNum)

biggerNum=int(input("Enter bigger num: "))
removeBiggerThanNum(numbers,biggerNum)

