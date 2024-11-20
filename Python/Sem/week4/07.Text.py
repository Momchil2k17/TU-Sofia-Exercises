def writeText(word,*args):
    text=""
    for num in args:
        if num<len(word):
            text+=word[num]
    print(text)

writeText("moka",1,2,3,4,1,1,0)