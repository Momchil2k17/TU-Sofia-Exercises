str=input("Enter string of numbers: ")

dic=dict()

def count(str):
    for i in range(len(str)):
        num=int(str[i])
        if(num in dic):
            dic[num]+=1
        else:
            dic[num]=1
    sortedDic=dict(sorted(dic.items(), key=lambda item:item[1]))
    
    print(sortedDic)

    
count(str)