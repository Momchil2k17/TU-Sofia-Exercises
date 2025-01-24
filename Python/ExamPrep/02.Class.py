class ClothesShop:
    def __init__(self,id,type,brand,price,quantity):
        self.id=id
        self.type=type
        self.brand=brand
        self.price=price
        self.quantity=quantity
    def change_price(self):
        newPrice=float(input("Моля въведете желаната нова цена: "))
        self.price=newPrice
        print("Успешно променихте цената на артикула")
    def clothes_info(self):
        print(f"Id: {self.id} Type: {self.type} Brand: {self.brand} Price: {self.price} Quantity: {self.quantity}")
    def change_quantity(self):
        newQuantity=int(input("Моля въведете желаната нова бройка: "))
        self.quantity=newQuantity
        print("Успешно променихте бройката на артикула")
        
c1=ClothesShop(15,"Hat","Nike",15.4,27)
c2=ClothesShop(19,"Shirt","Nike",34,12)
c3=ClothesShop(20,"Shoe","Adidas",121.5,5)

clothesList=[c1,c2,c3]

def searchById(clothes_list,id):
    isFound=False
    for product in clothes_list:
        if(product.id==id):
            product.clothes_info()
            isFound=True
            break
    if isFound==False:
        print(f"No product with id:{id} was found")

def search_by_brand(clothes_list,brand):
    brandList=[]
    for product in clothes_list:
        if (product.brand==brand):
            brandList.append(product)
    if(len(brandList)>0):
        print(f"Artikulite s marka {brand} sa:")
        for product in brandList:
            print(product.type)
    else:
        print("No products with the given brand was found")

def sell_clothes_by_id(clothes_list,id,num):
    found=False
    for product in clothes_list:
        print(product.id)
        if(product.id==id):
            found=True
            if(product.quantity>=num):
                product.quantity-=num
                print("Успешна продажба")
            else:
                print("Nedostatuhcna nalichnost")
                break
            break
    if(found==False):
        print("Ne e otkrit takuv product")

sell_clothes_by_id(clothesList,30,50)