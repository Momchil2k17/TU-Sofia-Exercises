#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 51

char** readLinkedWords(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    int capacity = 10;
    char** words = (char**)malloc(capacity * sizeof(char*));
    if (!words) {
        fclose(file);
        return NULL;
    }

    char word[MAX_WORD_LENGTH];
    *count = 0;
    char lastChar = '\0';

    if (fscanf(file, "%50s", word) == 1) {
        words[(*count)] = strdup(word);
        (*count)++;
        lastChar = tolower(word[strlen(word) - 1]);
    }

    while (fscanf(file, "%50s", word) == 1) {
        if (tolower(word[0]) == lastChar) {
            if (*count >= capacity) {
                capacity *= 2;
                char** temp = (char**)realloc(words, capacity * sizeof(char*));
                if (!temp) break;
                words = temp;
            }
            
            words[(*count)] = strdup(word);
            (*count)++;
            lastChar = tolower(word[strlen(word) - 1]);
        }
    }

    fclose(file);
    return words;
}

void writeWordsToBinaryFile(const char* filename, char** words, int count) {
    FILE* file = fopen(filename, "wb");
    if (!file) return;

    for (int i = 0; i < count; i++) {
        fwrite(words[i], sizeof(char), strlen(words[i]), file);
        
        if (i < count - 1) {
            char space = ' ';
            fwrite(&space, sizeof(char), 1, file);
        }
    }

    fclose(file);
}

void displayBinaryFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return;
    
    char c;
    while (fread(&c, sizeof(char), 1, file) == 1) {
        putchar(c);
    }
    printf("\n");

    fclose(file);
}

int main() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.bin";
    
    int count = 0;
    char** words = readLinkedWords(inputFileName, &count);
    
    if (words) {
        writeWordsToBinaryFile(outputFileName, words, count);
        displayBinaryFile(outputFileName);
        
        for (int i = 0; i < count; i++) {
            free(words[i]);
        }
        free(words);
    }
    
    return 0;
}