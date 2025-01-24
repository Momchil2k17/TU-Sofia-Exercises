n=10
list_10=[]
for i in range(n):
    while True:
        try:
            currentNum=int(input("Моля въведете число: "))
            if currentNum<=0:
                raise Exception("Въведеното число трябва да е положително")
            else:
                list_10.append(currentNum)
                break
        except ValueError:
            print("Невалиден формат данни")
        except Exception as e:
            print(e)
oddCount=0
for i in range(len(list_10)):
    if(list_10[i]%2!=0):
        oddCount+=1
print(oddCount)
average=sum(list_10)/len(list_10)
print(average)
list_10.sort()
list_10.reverse()
list_5=[]
for i in range(len(list_10)):
    if(list_10[i]%2==0 and len(list_5)<5):
        list_5.append(list_10[i])

if(len(list_5)==0):
    print("Вторият списък е празен!")
else:
    print(list_5)
    list_5.sort()
    list_5.reverse()
    print(list_5)
    for i in range(len(list_5)-1,0,-1):
        print(i)
        if(i%2==0):
            list_5.remove(list_5[i])
    print(list_5)
    