s=[1,2,3,4,5,6]
s1=[9,8]
s+=s1


h=[[1,2,3],['fsdafasdf','fsdafsdffadsfsad','bvbv'],[10,20,3123],[1,1,1,1,1,1,1,1,1]]
for row in range(len(h)):
    for col in range(len(h[row])):
        print(h[row][col], end=' ')
    print()


# bukvi=['s','T','a','E','f']
# print(bukvi)
# bukvi.sort(key=str.lower)
# print(bukvi)

d=dict()
d1=dict(name='ivan',last_name='petrov')
d3=dict([('name','polina'),('l_name','koleva')])
print(d3)