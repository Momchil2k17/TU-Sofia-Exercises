#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[3];       // например "A2" + '\0'
    char name[21];      // до 20 символа + '\0'
    int weight;         // в килограми
    float price;        // цена на кг
} IceCream;
void readFromBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open binary file for reading");
        return;
    }

    char code[3];
    int nameLen;
    char name[21]; // до 20 символа + \0
    int weight;
    float price;

    printf("Reading ice cream data from binary file:\n\n");

    while (fread(code, sizeof(char), 2, file) == 2) {
        code[2] = '\0'; // null-terminate

        if (fread(&nameLen, sizeof(int), 1, file) != 1) break;
        if (nameLen > 20) nameLen = 20; // безопасна граница
        fread(name, sizeof(char), nameLen, file);
        name[nameLen] = '\0'; // null-terminate

        fread(&weight, sizeof(int), 1, file);
        fread(&price, sizeof(float), 1, file);

        printf("====================\n");
        printf("Code: %s\n", code);
        printf("IceCream - %s\n", name);
        printf("Weight - %d kg\n", weight);
        printf("Price - %.2f BGN\n", price);
        printf("====================\n");
    }

    fclose(file);
}
void writeBinaryFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    IceCream icecreams[] = {
        {"A2", "strawberry", 50, 3.50},
        {"C3", "cookies", 40, 3.95},
        {"B1", "vanilla", 60, 2.80},
        {"D4", "mint", 45, 3.10}
    };

    int count = sizeof(icecreams) / sizeof(IceCream);

    for (int i = 0; i < count; i++) {
        // Записваме: код, дължина на име, име, тегло, цена
        fwrite(icecreams[i].code, sizeof(char), 2, file);

        int nameLen = strlen(icecreams[i].name);
        fwrite(&nameLen, sizeof(int), 1, file);
        fwrite(icecreams[i].name, sizeof(char), nameLen, file);

        fwrite(&icecreams[i].weight, sizeof(int), 1, file);
        fwrite(&icecreams[i].price, sizeof(float), 1, file);
    }

    fclose(file);
    printf("Binary file '%s' created successfully.\n", filename);
}

int main() {
    writeBinaryFile("icecream.bin");
    readFromBinaryFile("icecream.bin"); 
    return 0;
}
