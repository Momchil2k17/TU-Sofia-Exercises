start=int(input('Enter the start: '))
end=int(input('Enter the end: '))
if end<start:
    print("End cannot be smaller than start")
    exit()
counter=0
n=int(input("Enter n: "))
for i in range(n):
    num=int(input("Enter num: "))
    if num>=start and num<=end:
        counter+=1
print(counter)