#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the IceCream structure as per requirements
typedef struct {
    char code[3];       // Unique code (combination of capital letter and digit, e.g., "A2")
    char name[21];      // Product name (string up to 20 characters)
    int weight;         // Weight in kilograms (integer)
    float price;        // Price per kilogram (real number with format 0.00)
} IceCream;

// Function prototypes
float calculateTotalPriceByLetter(IceCream* icecreams, int n, char letter);
int saveFilteredIceCreamToFile(IceCream* icecreams, int n, float price, int weight);
void findIceCreamByCode(const char* code);

int main() {
    int n;
    
    // 1. Ask for the number of elements (n) with validation
    printf("Enter the number of ice creams (between 5 and 15): ");
    scanf("%d", &n);
    
    // Validate n
    if (n < 5 || n > 15) {
        printf("Error: Number must be between 5 and 15!\n");
        return 1;
    }
    
    // Allocate memory for the array
    IceCream* icecreams = (IceCream*)malloc(n * sizeof(IceCream));
    
    // Check if memory allocation was successful
    if (icecreams == NULL) {
        printf("Error: Memory allocation failed!\n");
        return 1;
    }
    
    // Fill the array with data entered by user
    printf("\nEnter details for %d ice creams:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nIce Cream #%d:\n", i + 1);
        
        printf("Code (capital letter and digit, e.g., A2): ");
        scanf("%s", icecreams[i].code);
        
        printf("Name (up to 20 characters): ");
        scanf(" %20s", icecreams[i].name);
        
        printf("Weight (in kilograms): ");
        scanf("%d", &icecreams[i].weight);
        
        printf("Price per kilogram: ");
        scanf("%f", &icecreams[i].price);
    }
    
    // Test Task 2: Calculate total price by letter
    char searchLetter;
    printf("\nEnter a letter to search for ice creams starting with: ");
    scanf(" %c", &searchLetter);
    
    float totalPrice = calculateTotalPriceByLetter(icecreams, n, searchLetter);
    if (totalPrice > 0) {
        printf("Total price of ice creams starting with '%c': %.2f\n", searchLetter, totalPrice);
    } else {
        printf("No ice creams found starting with '%c'\n", searchLetter);
    }
    
    // Test Task 3: Save filtered ice creams to file
    float priceThreshold;
    int weightThreshold;
    
    printf("\nEnter price threshold: ");
    scanf("%f", &priceThreshold);
    
    printf("Enter weight threshold: ");
    scanf("%d", &weightThreshold);
    
    int savedCount = saveFilteredIceCreamToFile(icecreams, n, priceThreshold, weightThreshold);
    printf("Number of ice creams saved to info.txt: %d\n", savedCount);
    
    // Test Task 4: Find ice cream by code
    char searchCode[3];
    printf("\nEnter a code to search for (e.g., A2): ");
    scanf("%s", searchCode);
    
    findIceCreamByCode(searchCode);
    
    // Free allocated memory
    free(icecreams);
    
    return 0;
}

// Task 2: Calculate total price of ice creams starting with a given letter
float calculateTotalPriceByLetter(IceCream* icecreams, int n, char letter) {
    float totalPrice = 0.0;
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        if (icecreams[i].name[0] == letter) {
            totalPrice += icecreams[i].weight * icecreams[i].price;
            found = 1;
        }
    }
    
    return found ? totalPrice : 0.0;
}

// Task 3: Save filtered ice creams to a text file
int saveFilteredIceCreamToFile(IceCream* icecreams, int n, float price, int weight) {
    FILE* file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file info.txt for writing!\n");
        return 0;
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (icecreams[i].price < price && icecreams[i].weight > weight) {
            fprintf(file, "%s;%s;%d;%.2fleva\n", 
                    icecreams[i].code, 
                    icecreams[i].name, 
                    icecreams[i].weight, 
                    icecreams[i].price);
            count++;
        }
    }
    
    fclose(file);
    return count;
}

// Task 4: Find and display an ice cream by its code from binary file
void findIceCreamByCode(const char* code) {
    FILE* file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open binary file icecream.bin!\n");
        return;
    }
    
    char fileCode[3];
    int nameLength;
    char name[21];
    int weight;
    float price;
    int found = 0;
    
    while (fread(fileCode, sizeof(char), 3, file) == 3) {
        // Read code (already read above)
        //terminate the code string
        fileCode[2] = '\0';
        // Read name length
        if (fread(&nameLength, sizeof(int), 1, file) != 1) {
            break;
        }
        
        // Read name
        if (fread(name, sizeof(char), nameLength, file) != nameLength) {
            break;
        }
        name[nameLength] = '\0'; // Null-terminate the name
        
        // Read weight
        if (fread(&weight, sizeof(int), 1, file) != 1) {
            break;
        }
        
        // Read price
        if (fread(&price, sizeof(float), 1, file) != 1) {
            break;
        }
        
        // Check if this is the ice cream we're looking for
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
}