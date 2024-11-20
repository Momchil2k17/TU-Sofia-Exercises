def binaryToDecimal(binaryNum):
    binaryStr=str(binaryNum)
    decimal = 0
    length = len(binaryStr)
    for i in range(length):
        bit = int(binaryStr[i])
        decimal += bit * (2 ** (length - i - 1))
    
    return decimal

print(binaryToDecimal(10100))