word=input("word= ")
d=dict()
for l in range(len(word)):
    if(word[l] in d):
        d[word[l]]+=1
    else:
        d[word[l]]=1
print(d)