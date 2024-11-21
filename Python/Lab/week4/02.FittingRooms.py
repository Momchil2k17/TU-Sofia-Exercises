floors=int(input("Floors: "))
floorinfo=dict()
for i in range(floors):
    floorinfo[i+1]=input().split()
for key in floorinfo:
    fittingRoomCount=int(len(floorinfo[key][0]))
    peopleInside=int(floorinfo[key][1])
    peopleWaiting=int(floorinfo[key][2])
    sum=peopleInside+peopleWaiting
    if(sum==fittingRoomCount):
        print(f"Floor {key}: There are no free fitting rooms")
    elif(sum>=fittingRoomCount):
        print(f"Floor {key}: There are {sum-fittingRoomCount} waiting customers")
    else:
         print(f"Floor {key}: There are {fittingRoomCount-sum} free fitting rooms")