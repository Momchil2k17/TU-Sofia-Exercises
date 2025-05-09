#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char Id[3];
    char Name[21];
    int weight;
    float price;
} IceCream;
//method za da pisane na binaren fail bez proverki 
void writeBinaryFile(IceCream* arr, int n) {
    FILE* file = fopen("icecream.bin", "wb");
    for (int i = 0; i < n; i++) {
        fwrite(arr[i].Id, sizeof(char), 2, file);
        int len = strlen(arr[i].Name);
        fwrite(&len, sizeof(int), 1, file);
        fwrite(arr[i].Name, sizeof(char), len, file);
        fwrite(&arr[i].weight, sizeof(int), 1, file);
        fwrite(&arr[i].price, sizeof(float), 1, file);
    }
    fclose(file);
}

float calculateTotalPriceByLetter(IceCream* icecreams, int n, char letter) {
    float totalPrice = 0.0;
    int found = 0;
   
    if(icecreams==NULL) {
        printf("Error: Empty Array was pass to function\n");
        return 0;
    }
    if (n<1) {
        printf("Error: %d is wrong value for iceCreamArraySize\n",n);
        return 0;
    }
    if (!isalpha(letter)) {
        printf("Error: Letter is out of range (A-z)\n");
    }

    for (int i = 0; i < n; i++) {
        if (tolower(icecreams[i].Name[0]) == tolower(letter)) {
            totalPrice += icecreams[i].weight * icecreams[i].price;
            found = 1;
        }
    }
    
    return found ? totalPrice : 0.0;
}
int saveFilteredIceCreamToFile(IceCream* icecreams, int n, float price, int weight) {

    if(icecreams==NULL) {
        printf("Error: Empty Array was pass to function\n");
        return 0;
    }
    if (n<1) {
        printf("Error: %d is wrong value for iceCreamArraySize\n",n);
        return 0;
    }
    if (price<=0) {
        printf("Error: criteriaPrice is not correct\n");
        return 0;
    }
    if (weight<=0) {
        printf("Error: criteriaWeight is not correct\n");
        return 0;
    }


    FILE* file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file info.txt for writing!\n");
        exit(-2);
    }
    
    int count = 0,res=0;
    
    for (int i = 0; i < n; i++) {
        if (icecreams[i].price < price && icecreams[i].weight > weight) {
            res=fprintf(file, "%s;%s;%d;%.2fleva\n", 
                    icecreams[i].Id, 
                    icecreams[i].Name, 
                    icecreams[i].weight, 
                    icecreams[i].price);
            if (res<0) {
                printf("Error: Unable to write to file info.txt\n");
                fclose(file);
                exit(-1);
            }
            count++;
        }
    }
    
    fclose(file);
    return count;
}
int findIceCreamByCode(const char* code) {
    FILE* file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open binary file icecream.bin!\n");
        return -1;
    }
    
    char fileCode[3];
    int nameLength;
    char name[21];
    int weight;
    float price;
    int found = 0;
    while (fread(fileCode, sizeof(char), 2, file) == 2) {
        fileCode[2] = '\0';
        if (fread(&nameLength, sizeof(int), 1, file) != 1) {
            break;
        }
        if (fread(name, sizeof(char), nameLength, file) != nameLength) {
            break;
        }
        name[nameLength] = '\0'; 
        printf("Name: %s\n", name);
        
        if (fread(&weight, sizeof(int), 1, file) != 1) {
            break;
        }
        
        if (fread(&price, sizeof(float), 1, file) != 1) {
            break;
        }
        
        if (strcmp(fileCode, code) == 0) {
            printf("====================\n");
            printf("IceCream - %s\n", name);
            printf("Price - %.2f BGN\n", price);
            printf("====================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Ice cream with code '%s' not found.\n", code);
    }
    
    fclose(file);
    return found;
}
int main() {
    int n=0;
    IceCream *icecreams = NULL;
    while (n<6 || n>14)
    {
        //vuvedi 7
        printf("Enter the number of ice cream flavors (between 6 and 14): ");
        scanf("%d", &n);
    }

    icecreams = (IceCream*)malloc(n * sizeof(IceCream));
    if (icecreams == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    //stoinosti che me murzi da vuvejdam vseki put
    if (n >= 7) {
        strcpy(icecreams[0].Id, "A2");
        strcpy(icecreams[0].Name, "Vanilla Delight");
        icecreams[0].weight = 1;
        icecreams[0].price = 3.50;

        strcpy(icecreams[1].Id, "B4");
        strcpy(icecreams[1].Name, "Choco Dream");
        icecreams[1].weight = 7;
        icecreams[1].price = 4.20;

        strcpy(icecreams[2].Id, "C1");
        strcpy(icecreams[2].Name, "Strawberry Shine");
        icecreams[2].weight = 15;
        icecreams[2].price = 3.75;

        strcpy(icecreams[3].Id, "D3");
        strcpy(icecreams[3].Name, "Mint Choco");
        icecreams[3].weight = 5;
        icecreams[3].price = 4.00;

        strcpy(icecreams[4].Id, "E5");
        strcpy(icecreams[4].Name, "Caramel Swirl");
        icecreams[4].weight = 12;
        icecreams[4].price = 4.30;

        strcpy(icecreams[5].Id, "F7");
        strcpy(icecreams[5].Name, "Tiramisu Ice");
        icecreams[5].weight = 9;
        icecreams[5].price = 5.10;

        strcpy(icecreams[6].Id, "G6");
        strcpy(icecreams[6].Name, "Blueberry Cream");
        icecreams[6].weight = 6;
        icecreams[6].price = 3.90;
    }

    //printirame da vidim dali sa se zapisali
    for (int i = 0; i < n; i++) {
        printf("Ice Cream #%d:\n", i + 1);
        printf("Code: %s\n", icecreams[i].Id);
        printf("Name: %s\n", icecreams[i].Name);
        printf("Weight: %d kg\n", icecreams[i].weight);
        printf("Price: %.2f BGN\n", icecreams[i].price);
    }
    //pravim si binaren fail za zad 4
    writeBinaryFile(icecreams, n);

    //prazen masiv za proverki na edge cases
    IceCream* icecreams1=NULL;
    
    //2
    printf("\nTASK 2\n");
    float totalPrice1 = calculateTotalPriceByLetter(icecreams, n, '#');
    printf("Total Price is: %.2f\n",totalPrice1);
    float totalPrice2 = calculateTotalPriceByLetter(icecreams, n, 'b');
    printf("Total Price is: %.2f\n",totalPrice2);
    
    //3
    int result= saveFilteredIceCreamToFile( icecreams, 7, 4.00, 2);
    printf("%d records added to txt file",result);

    //4
    char searchCode[3];
    printf("\nEnter a code to search for (e.g., A2): ");
    scanf("%s", searchCode);    
    findIceCreamByCode(searchCode);

}

