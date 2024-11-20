def decimalToBinary(decimalNum):
    if decimalNum == 0:
        return 0
    
    binary = ""
    while decimalNum > 0:
        remainder = decimalNum % 2
        binary = str(remainder) + binary  
        decimalNum //= 2 
    
    return int(binary)

print(decimalToBinary(20))