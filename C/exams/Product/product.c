#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[21];
    int Code;
    char Date[11];
    float Price;
} Product;

typedef struct {
    int year;
    int day;
    int month;
} Date;

Date parse_date(char dateStr[11]) {
    Date d;
    sscanf(dateStr, "%d.%d.%d", &d.year, &d.month,&d.day);
    return d;
}

int compare_dates(Date a, Date b) {
    if (a.year != b.year)
        return (a.year < b.year) ? -1 : 1;
    if (a.month != b.month)
        return (a.month < b.month) ? -1 : 1;
    if (a.day != b.day)
        return (a.day < b.day) ? -1 : 1;
    return 0;
}

float avg_by_price(Product*, int, float);
int write_text_file(Product*, int, char*, float);
int print_info(char*,int);
void createBinaryFileWithProducts();

int main(){
    //suzdavame si binaren fail s produkti
    createBinaryFileWithProducts();
    Product* products = NULL;
    int n = 0;  
    while((n<=10) || (n>=30)){
        printf("Enter number of products (10-30): ");
        scanf("%d", &n);
    }
    products = malloc(n * sizeof(Product));
    if (products == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    while((getchar() != '\n'));
    for (int i = 0; i < n; i++){
        printf("Enter product name: ");
        fgets(products[i].Name, sizeof(products[i].Name), stdin);
        if(products[i].Name[strlen(products[i].Name) - 1] == '\n') {
            products[i].Name[strlen(products[i].Name) - 1] = '\0';
        }

        printf("Enter product code: ");
        scanf("%d", &products[i].Code);
        while((getchar() != '\n'));

        printf("Enter product date (yyyy.mm.dd): ");
        fgets(products[i].Date, sizeof(products[i].Date), stdin);
        if(products[i].Date[strlen(products[i].Date) - 1] == '\n') {
            products[i].Date[strlen(products[i].Date) - 1] = '\0';
        }

        printf("Enter product price: ");
        scanf("%f", &products[i].Price);
        while((getchar() != '\n'));
    }
    //printirame da vidim dali sa se zapisali
    for (int i = 0; i < n; i++) {
        printf("Product #%d:\n", i + 1);
        printf("Name: %s\n", products[i].Name);
        printf("Code: %d\n", products[i].Code);
        printf("Date: %s\n", products[i].Date);
        printf("Price: %.2f\n", products[i].Price);
    }

    printf("\nAverage price of products with price greater than 5.00: %.2f\n", avg_by_price(products, n, 5.00));
    char date[11]="2023.10.01";
    float price=5.00;
    int writtenCount = write_text_file(products, n, date, price);
    printf("%d records added to products.txt\n", writtenCount);

    char prName[]="Product1";
    int prCode=123;
    int found = print_info(prName, prCode);
    if (found == -1) {
        printf("Error: Unable to open file\n");
    } else if (found == -2) {
        printf("Error: Unable to read product information\n");
    } else if (found == 0) {
        printf("Product not found\n");
    } else {
        printf("Product found successfully\n");
    }
     
    
   
}

float avg_by_price(Product* products, int n, float price) {
    float avgPrice = 0,sum=0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (products[i].Price > price) {
            sum += products[i].Price;
            count++;
        }
    }
    if(count > 0) {
        avgPrice = sum / count;
    }
    return avgPrice;
}

int write_text_file(Product* products, int n, char date[11], float price) {
    FILE* file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    int res=0,writtenCount=0;
    for (int i = 0; i < n; i++) {
        if (compare_dates(parse_date(products[i].Date), parse_date(date)) < 0 && products[i].Price > price) {
            res=fprintf(file, "%s-%d-%s-%.2f\n", products[i].Name, products[i].Code, products[i].Date, products[i].Price);
            if (res < 0) {
                printf("Error writing to file\n");
                fclose(file);
                return -1;
            }
            writtenCount++;
        }
    }
    fclose(file);
    return writtenCount;
}

int print_info(char* name,int code){
    FILE* file=fopen("product.bin", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char productName[21],productDate[11];
    int productCode,nameLength,found=0;
    float productPrice;

    while(fread(&nameLength,sizeof(int),1,file)==1){
        if(fread(productName,sizeof(char),nameLength,file)!=nameLength){
            printf("Error reading product name\n");
            fclose(file);
            return -2;
        }
        productName[nameLength]='\0';
        if(fread(&productCode,sizeof(int),1,file)!=1){
            printf("Error reading product code\n");
            fclose(file);
            return -2;
        }
        if(fread(productDate,sizeof(char),10,file)!=10){
            printf("Error reading product date\n");
            fclose(file);
            return -2;
        }
        productDate[10]='\0';
        if(fread(&productPrice,sizeof(float),1,file)!=1){
            printf("Error reading product price\n");
            fclose(file);
            return -2;
        }


        //tui ne e kat na izpita ama bachka
        if(strcmp(name,productName)==0 && code==productCode){
            printf("Product Name: %s\n", productName);
            printf("Product Code: %d\n", productCode);
            printf("Product Date: %s\n", productDate);
            printf("Product Price: %.2f\n", productPrice);
            found=1;
            break;
        }
    }
    if (!found) {
        printf("Product with name '%s' and code '%d' not found.\n", name, code);
    }
    fclose(file);
    return found;
}

//za suzdavane na binaren fail
void createBinaryFileWithProducts() {
    FILE* file = fopen("product.bin", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    Product products[] = {
        {"Product1", 123, "2023.10.01", 5.50},
        {"Product2", 456, "2023.09.15", 7.25},
        {"Product3", 789, "2023.08.20", 4.75},
        {"Product4", 101, "2023.07.30", 6.00},
        {"Product5", 112, "2023.06.10", 8.50}
    };
    int n = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < n; i++) {
        int nameLength = strlen(products[i].Name);
        fwrite(&nameLength, sizeof(int), 1, file);
        fwrite(products[i].Name, sizeof(char), nameLength, file);
        fwrite(&products[i].Code, sizeof(int), 1, file);
        fwrite(products[i].Date, sizeof(char), 10, file);
        fwrite(&products[i].Price, sizeof(float), 1, file);
    }
    fclose(file);
}