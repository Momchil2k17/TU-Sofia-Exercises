
def checkPerfectNum(nums):

    for num in nums:
        sumOfDeliteli=0
        for i in range(1,num):
            if num%i==0:
                sumOfDeliteli+=i
        if(sumOfDeliteli==num):
         print(f"{num} - {True}")
        else:
           print(f"{num} - {False}")


nums=[28,6,7,1,5]
checkPerfectNum(nums)