products=set(input("Products: ").split(" "))
recipeName=input("Name: ")
recipeProducts=set()
n=int(input("n: "))
for i in range(n):
    recipeProducts.add(input())
availableProducts=products&recipeProducts
productsToBuy=recipeProducts-products
unnecessaryPr=products-recipeProducts
print(f"There are {len(availableProducts)} products for {recipeName}:")
for i in availableProducts:
    print(i)
print(f"You need to buy {len(productsToBuy)} products: {productsToBuy}")
print(f"Unnecessary products: {unnecessaryPr}")