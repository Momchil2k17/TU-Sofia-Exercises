peopleCount=int(input("Count: "))
children=[]
adult=[]
for i in range(peopleCount):
    age=int(input())
    if(age<18):
        children.append(age)
    else:
        adult.append(age)
adultSum=0
for i in range(len(adult)):
    adultSum+=adult[i]
print(children)
print(adult)
print(f"Count of children: {len(children)}")
print(f"Count of adults: {len(adult)}")
print(f"Average age of adults: {round(adultSum/len(adult))}")