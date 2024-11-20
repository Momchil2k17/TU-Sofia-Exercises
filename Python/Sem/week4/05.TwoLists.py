def findSumOfMiltiplication(nums1Copy,nums2Copy):
    sum=0
    nums1=nums1Copy
    nums2=nums2Copy
    len1=len(nums1)
    len2=len(nums2)
    if(len2>len1):
        for i in range(len2-len1):
            nums1.append(nums1[i])
    elif(len1>len2):
        for i in range(len1-len2):
            nums2.append(nums2[i])
    for i in range(len(nums1)):
        sum+=(nums1[i]*nums2[i])
    print(sum)

findSumOfMiltiplication([1,1,1,1,1,1],[4,5,6])