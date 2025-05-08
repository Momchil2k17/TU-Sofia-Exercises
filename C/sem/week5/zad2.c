#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

typedef struct {
    char name[MAX_LENGTH];
    double price;
    int id;
} Product;

typedef struct {
    char address[MAX_LENGTH];
    int productId;
} Order;

Product products[MAX_PRODUCTS];
int productCount = 0;

Order waitingOrders[MAX_ORDERS];
int waitingOrderCount = 0;

Product* findProduct(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

void addProduct(char* name, double price, int id) {
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.id = id;
    
    products[productCount++] = newProduct;
    
    for (int i = 0; i < waitingOrderCount; i++) {
        if (waitingOrders[i].productId == id) {
            printf("Client %s ordered %s\n", waitingOrders[i].address, name);
            
            for (int j = i; j < waitingOrderCount - 1; j++) {
                waitingOrders[j] = waitingOrders[j + 1];
            }
            waitingOrderCount--;
            i--;
        }
    }
}

void processOrder(char* address, int productId) {
    Product* product = findProduct(productId);
    
    if (product != NULL) {
        printf("Client %s ordered %s\n", address, product->name);
    } else {
        Order newOrder;
        strcpy(newOrder.address, address);
        newOrder.productId = productId;
        
        waitingOrders[waitingOrderCount++] = newOrder;
    }
}

int main() {
    char command[MAX_LENGTH];
    char name[MAX_LENGTH];
    char address[MAX_LENGTH];
    double price;
    int id;
    
    while (1) {
        scanf("%s", command);
        
        if (strcmp(command, "END") == 0) {
            break;
        }
        
        if (strcmp(command, "Product") == 0) {
            scanf("%s", name);
            scanf("%lf", &price);
            scanf("%d", &id);
            addProduct(name, price, id);
        } else if (strcmp(command, "Order") == 0) {
            scanf("%s", address);
            scanf("%d", &id);
            processOrder(address, id);
        }
    }
    
    return 0;
}