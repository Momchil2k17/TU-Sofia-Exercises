#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define BUFFER_SIZE 1024

int main() {
    char inputFile[MAX_FILENAME];
    char outputFile[MAX_FILENAME];
    int key;
    FILE *in, *out;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter filename to encode: ");
    scanf("%s", inputFile);

    do {
        printf("Enter key (number between 2-10): ");
        scanf("%d", &key);
        
        if (key < 2 || key > 10) {
            printf("Invalid key! Please enter a number between 2 and 10.\n");
        }
    } while (key < 2 || key > 10);

    strcpy(outputFile, "encoded_");
    strcat(outputFile, inputFile);

    in = fopen(inputFile, "r");
    if (in == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Error creating output file!\n");
        fclose(in);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] + key;
        }
        
        fwrite(buffer, 1, bytesRead, out);
    }

    fclose(in);
    fclose(out);

    printf("File encoded successfully and saved as '%s'.\n", outputFile);

    return 0;
}