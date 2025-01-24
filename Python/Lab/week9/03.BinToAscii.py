binary_file=open('document.bin','wb')
text="This is good"
encoded=text.encode("ascii")
binary_file.write(encoded)
binary_file.close()



binary_file=open('document.bin','rb')
print(binary_file.read())
binary_file.seek(0)
print(binary_file.read(4)) 