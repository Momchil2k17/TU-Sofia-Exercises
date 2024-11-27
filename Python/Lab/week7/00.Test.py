def romanToInt(s: str) -> int:
        dic=dict()
        dic["I"]=1
        dic["IV"]=4
        dic["V"]=5
        dic["IX"]=9
        dic["X"]=10
        dic["XL"]=40
        dic["L"]=50
        dic["XC"]=90
        dic["C"]=100
        dic["CD"]=400
        dic["D"]=500
        dic["CM"]=900
        dic["M"]=1000
        sum=0
        skip=False
        for i in range(len(s)):
            if skip:
                skip=False
                continue
            if(s[i]=="I"):
                if(i<len(s)-1 and s[i]+s[i+1] in dic):
                    sum+=dic[s[i]+s[i+1]]
                    skip=True
                    continue
            elif(s[i]=="X"):
                if(i<len(s)-1 and s[i]+s[i+1] in dic):
                    sum+=dic[s[i]+s[i+1]]
                    skip=True
                    continue
            elif(s[i]=="C"):
                if(i<len(s)-1 and s[i]+s[i+1] in dic):
                    sum+=dic[s[i]+s[i+1]]
                    skip=True
                    continue
            sum+=dic[s[i]]
        return sum
    
print(romanToInt("MCMXCIV"))