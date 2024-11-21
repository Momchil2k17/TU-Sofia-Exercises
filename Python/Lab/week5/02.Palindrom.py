
def isPalindrome(num):
    storedNum=num
    reversedNum=""
    while(num>0):
        reversedNum+=str((num%10))
        num=num//10
      
    if(storedNum==int(reversedNum)):
        print(1)
    else:
        print(0)
num=int(input("num: "))

isPalindrome(num)

