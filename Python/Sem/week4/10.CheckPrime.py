def checkPrime(num):
    for i in range(1,num):
        for j in range(1,num):
            if (isPrime(i) and isPrime(j)):
                if(i+j==num):
                    print(i)
                    print(j)
                    return True
    return False
def isPrime(n):
    for i in range(2,n):
        if n%i==0:
            return False
    if n==1:
        return False
    return True

print(checkPrime(10))