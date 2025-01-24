# num=13345
# sum=0
# while(num>0):
#     sum+=num%10
#     num=num//10
#     print(num)
# print(sum)
# print(type(''))
# print(f"d"*42)
# print(round(3.49))
# nums=[1,2,3,4,5,6,7,8,9]
# nums1=[num for num in nums if num>5]
# print(nums1)

# stringed="fdaf"
# print(stringed.upper().lower())
# text="very very very very"
# text=text.replace("very","not",3)
# print(text[::-1])

# fruits=["apple","banana","orange"]
# fruits.reverse()
# print(fruits)

# menu = {"pizza": 3.00,
#                "nachos": 4.50,
#                "popcorn": 6.00,
#                "fries": 2.50,
#                "chips": 1.00,
#                "pretzel": 3.50,
#                "soda": 3.00,
#                "lemonade": 4.25}
# cart = []
# total = 0

# print("--------- MENU ---------")
# for key, value in menu.items():
#     print(f"{key:10}: ${value:.2f}")
# print("------------------------")

# while True:
#     food = input("Select an item (q to quit): ").lower()
#     if food == "q":
#         break
#     elif food in menu:
#         cart.append(food)
#     else:
#         print(food)

# print("------ YOUR ORDER ------")
# for food in cart:
#     total += menu.get(food)
#     print(food, end=" ")

# print()
# print(f"Total is: ${total:.2f}")

# import random
# for i in range(5):
#     print(random.randint(1,10))
# thatdic={"name":"John", "age" : 36, "country" :"Norway"}
# thisdict = dict(name="John", age = 36, country = "Norway")
# print(thisdict)
# print(thatdic)

# for key in thatdic.keys():
#     print(f"{key}  {thisdict[key]}")
# import random
# nums=[random.randint(1,20) for i in range(10)]
# print(nums)

# import m 
# m.square(5)


# print("Lion" in "MomoLionKing")
# nums=[332,54,312,54,61,100,101,671,94]

# for i in range(len(nums)):
    # print(nums[i])
    # checkNum=nums[i]//10
    # print((nums[i]//100)%10%3==0 and (nums[i]//100)%10!=0)
    #     # print(checkNum%10%3)
    #     if(checkNum%10%3==0):
    # else:
    #     # print(checkNum%3)
    #     if(checkNum%3==0):
    #         print(nums[i])

# n=int(4.2)
# print(n)

# x=1
# if x is None:
#     print("no")
# else:
#     print("yes")

# list1=[4,3,2,42,4,4,5,7,94,4123]
# print(max(list1))
# list2=[x for x in list1 if x>5]
# print(list2)


# class Car:
#     def __init__(self,color,price):
#         self.color=color
#         self.price=price
#     def printInfo(self):
#         print(f"{self.color} {self.price}")
# c1=Car("green",1)
# c2=Car("green",45999)
# c3=Car("yellow",1   )
# c4=Car("green",32241234123)

# carList=[c1,c2,c3,c4]

# for car in carList:
#     car.printInfo()

# def searchColor(carList,color):
#     colorCars=[]
#     for car in carList:
#         if car.color==color:
#             colorCars.append(car)
#     colorCars.sort(key=lambda x:x.price)
#     return colorCars[-1].printInfo()
# print('fdasfas')
# searchColor(carList,"green")

# newCars=[car for car in carList if car.price==1]
# for car in newCars:
#     car.printInfo()


lis1=[1422,32,32,33,5,85,108,87,9]
minEl=1000000
minId=-1
for i in range(len(lis1)):
    if(lis1[i]<minEl and lis1[i]%2==0):
        minEl=lis1[i]
        minId=i
print(minId)
print(minEl)

minEven=[x for x in lis1 if x%2==0]
if(len(minEven)>0):
    print(min(minEven))
    print(lis1.index(min(minEven)))
# lis1.sort(reverse=True)
# for x in lis1:
#     print(x)
#     if x%2!=0:
#         break
# l1=sorted(lis1)
# print(l1)
# print(lis1)
# for i in range(len(lis1)-1,-1,-1):
#     if(lis1[i]%2!=0):
#         lis1.remove(lis1[i])
# print(lis1)
# lis1.append(max(lis1)-min(lis1))
# print(lis1)

# list2=[x for x in lis1 if x>99 and x%9==0]
# print(list2)

