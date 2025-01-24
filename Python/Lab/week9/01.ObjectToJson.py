import json
dictionary={
    "name":"kristian",
    "rollno":56,
    "phonenumber":"0888888888",
    "spisuk":[3,4,5]
}

json_object=json.dumps(dictionary,indent=4)
with open("samplezad1.json","w") as outfile:
    outfile.write(json_object)