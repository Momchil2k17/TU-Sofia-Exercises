import random
while True:
    try:
        n=int(input())
        if (n<=20 or n>=80):
            raise Exception("n trqbva da e mevdu 20 i 80")
        else:
            break
    except ValueError:
        print("nevaliden format danni")
    except Exception as e:
        print(e)

list1=[]
for i in range(n):
    list1.append(random.randint(-800,1000))

print(list1)
count3=0
for i in range(len(list1)):
    checkNum=list1[i]
    if((checkNum//100)%3==0 and checkNum//100!=0):
        count3+=1
print(count3)

maxOtr=-801
maxIndex=-1
minPol=1001
minIndex=-1

for i in range(len(list1)):
    if(list1[i]<0 and list1[i]>maxOtr):
        maxOtr=list1[i]
        maxIndex=i

if maxIndex==-1:
    print("Ne bqha otkriti otricatelni chisla")

for i in range(len(list1)):
    if(list1[i]>0 and list1[i]<minPol):
        minPol=list1[i]
        minIndex=i

if minIndex==-1:
    print("Ne bqha otkriti polojitelni chisla")

list2=[]
for i in range(len(list1)):
    if(list1[i]%7==0 and list1[i]%2!=0):
        list2.append(list1[i])

if len(list2)==0:
    print("vtoriqt spisuk e prazen")
else:
    print(list2)
    evenIndexsum=[]
    for i in range(len(list2)):
        if i%2==0:
            evenIndexsum.append(list2[i])
    print(evenIndexsum)
    evenAvg=sum(evenIndexsum)/len(evenIndexsum)
    for i in range(len(list2)):
        if(list2[i]>-100 and list2[i]<-9):
            print(list2[i],end=" ")
    print()
    max=-801
    ind=-1
    for i in range(len(list2)):
        if(list2[i]<0 and list2[i]>max):
            max=list2[i]
            ind=i

    if ind==-1:
        print("Ne bqha otkriti otricatelni chisla") 
    else:
        print(list2[ind])
        print(list2)
        list2.remove(list2[ind])
        print(list2)


