def checkFile(file):
    try:
        with open(file, 'r') as file:
            content = file.read()
        print(content)
    except:
        print("Couldn't open file")
        
checkFile("nums1.txt")
