def printSaleInfo(info):
    floors=info.split(", ")
    sales=len(floors)
    theatreTicketsSold=0
    money=0
    for floor in floors:
        floorInfo=floor.split(" -> ")
        red=int(floorInfo[0])
        mesta=int(floorInfo[1])
        if(red>=1 and red<=3):
            theatreTicketsSold+=mesta
            money+=mesta*20
        elif(red>3 and red<=12):
            theatreTicketsSold+=mesta
            money+=mesta*15
    print(f"Sales: {sales}")
    print(f"Theatre tickets sold: {theatreTicketsSold}")
    print(f"Total money: {money}lv")

printSaleInfo("3 -> 5, 6 -> 10, 8 -> 2")
printSaleInfo("1 -> 7, 5 -> 9, 9 -> 12, 2 -> 4")