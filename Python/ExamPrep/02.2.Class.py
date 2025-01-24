class Shoes:
    def __init__(self,brand,price,color,size,quantity):
        self.brand=brand
        self.price=price
        self.color=color
        self.size=size
        self.quantity=quantity
    def Sale(self,quantity):
        if(self.quantity>=quantity):
            self.quantity-=quantity
            print("Успешна продажба")
        else:
            print("Недостатъчно количество")
    def Purchase(self,quantity):
        self.quantity+=quantity
    
s1=Shoes("Nike",120,"green",37.5,14)
s2=Shoes("Adidas",55.6,"yellow",37.5,14)
s3=Shoes("Puma",98,"red",37.5,14)
s4=Shoes("NB",123,"green",37.5,14)
s5=Shoes("Sketchers",102,"green",37.5,14)
s6=Shoes("Nike",78.99,"green",37.5,14)
s7=Shoes("Nike",213,"green",37.5,14)

shoes_list=[s1,s2,s3,s4,s5,s6,s7]

def sort_price(shoes_list):
        shoes_list.sort(key=lambda x:x.price,reverse=True)
        for shoe in shoes_list:
            print(f"{shoe.brand} shoe price: {shoe.price}")
def shoes_searching(shoes_list,brand,size):
    sumPrice=0
    searchShoe=[]
    for shoe in shoes_list:
        sumPrice+=shoe.price
        if(shoe.brand==brand and shoe.size==size):
            searchShoe.append(shoe)
    avgPrice=sumPrice/len(shoes_list)
    filteredShoes=[]
    for shoe in searchShoe:
        if shoe.price<avgPrice:
            filteredShoes.append(shoe)
    return filteredShoes

def cheapest_shoe(shoe_list,color):
    cheapest_shoe=None
    cheapest_price=1000000
    for shoe in shoe_list:
        if shoe.color==color and shoe.price<cheapest_price:
            cheapest_shoe=shoe
    if cheapest_shoe is None:
        print("Color isnt available")
    else:
        print(f"{cheapest_shoe.brand} {cheapest_shoe.size} {cheapest_shoe.color}")

def delete_shoes(shoe_list,brand):
    for shoe in shoe_list:
        if shoe.brand==brand:
            shoe_list.remove(shoe)