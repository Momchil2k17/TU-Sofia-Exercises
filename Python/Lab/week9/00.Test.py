# with open('test1.txt','r') as f:
#     print(f.read())
#     print(f.read(4))
# with open('test1.txt','r') as f:
#     print(f.readline(1))
#     print(f.readline(3))

# mf=open("test1.txt",'r')

# for line in mf:
#     print(line,end="")

# mf.close()

# new_file=open('newfile.txt','w')
# new_file.write("Writing to a new file\n")
# new_file.write("Writing to a new file\n")
# new_file.write("Writing to a new file\n")

# new_file.close()


# fruits=["Orange\n","Banana\n","Apple\n"]
# new_file=open('newfile.txt','a+',encoding="utf-8")
# new_file.writelines(fruits)
# new_file.seek(0)
# for line in new_file:
#     print(line,end='')
# new_file.close()


# cars=["Audi\n","Bentley\n","Toyota\n"]
# new_file=open('newfile.txt','a+',encoding="utf-8")
# for car in cars:
#     new_file.write(car)
# print(F"Tell the byte at which the file cursor is: {new_file.tell()}")
# new_file.seek(0)
# for line in new_file:
#     print(line,end='')
# new_file.close()

import json
# dictionary={
#     "name":"kristian",
#     "rollno":56,
#     "phonenumber":"0888888888",
#     "spisuk":[3,4,5]
# }

# json_object=json.dumps(dictionary,indent=4)
# with open("sample.json","w") as outfile:
#     outfile.write(json_object)

# dictionary1 ={
#     "name" : "sathiyajith",
#     "rollno" : 56,
#     "cgpa" : 8.6,
#     "phonenumber" : "9976770500"
# }
  
# with open("sample1.json", "w") as outfile:
#     json.dump(dictionary1, outfile,indent=4)

# with open("sample.json",'r') as openfile:
#     json_object=json.load(openfile)
# print(json_object)
# print(type(json_object))

# binary_file=open('binary_file.bin','wb+')
# text="Hello 123"
# encoded=text.encode("utf-8")
# binary_file.write(encoded)
# binary_file.seek(0)
# binary_data=binary_file.read()
# print(f"binary: {binary_data}")
# text=binary_data.decode("utf-8")
# print(f"Deccoded data: {text}")
import pickle
tup1=[22,44,66]
p1=pickle.dumps(tup1)
print(p1)
t2=pickle.loads(p1)
print(t2)

with open("a.txt",'wb') as f:
    pickle.dump(tup1,f)

with open("a.txt","rb") as f:
    t3=pickle.load(f)
print(t3)