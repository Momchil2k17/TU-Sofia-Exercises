import random
while True:
    try:
        n=int(input())
        if(n<=20 or n>=30):
            raise Exception("N should be between 20 and 30")
        else:
            break
    except ValueError:
        print("Invalid type")
    except Exception as e:
        print(e)
print(n)
list1=[random.randint(-100,100) for i in range(n)]

oddIndexSum=0
for i in range(len(list1)):
    if(i%2==0):
        oddIndexSum+=list1[i]

count2=0
multiplyEven=1
for x in list1:
    if(x%2==0 and x%10!=0):
        count2+=1
    if(x<0 and x%2==0):
        multiplyEven*=x

list2=[x for x in list1 if x>n]
print(list2)
    
if(len(list2)==0):
    print("Вторият списък е празен")
else:
    minMax=max(list2)-min(list2)
    
    oddNums=[x for x in list2 if x%2!=0]
    print(oddNums)
    print(len(oddNums))
    list2.remove(min(list2))