def minMaxAvg(*args):
    min=321321321321
    max=-321321321321
    sum=0
    for num in args:
        if(num<min):
            min=num
        if(num>max):
            max=num
        sum+=num
    avg=sum/len(args)
    l=[min,max,avg]
    print(l)
minMaxAvg(1,3,5,15,1,2,1,0)