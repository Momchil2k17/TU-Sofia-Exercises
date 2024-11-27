def median(nums):
    nums=sorted(nums)
    count=len(nums)
    if count%2==1:
        print(f"Median: {nums[count//2+1]}")
    else:
        median=round((nums[count//2+1]+nums[count//2-1])/2,1)
        print(f"Median: {median}")

median([1,2,3,4.2,5,6,7,8])
median([1,2,3,4,5])
median([2,4,5,3,1])