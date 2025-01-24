class TextAndNum:
    def __init__(self,arg1,arg2):
        if (type(arg1) is str and type(arg2) is str):
            self.text=arg1+arg2
        elif(type(arg1) is int and type(arg2) is int):
            self.num=arg1+arg2
        else:
            print("Objects has no attributes")
        
t1=TextAndNum("gg","wp")
print(t1.text)
n1=TextAndNum(1,2)
print(n1.num)
o=TextAndNum("1",1)
