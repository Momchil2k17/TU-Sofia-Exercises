#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 81

void printMenu(){
    printf("\n-------------String Magic-------------\n");
    printf("----------Choose an option:----------\n");
    printf("1. Enter text\n");
    printf("2. Count words\n");
    printf("3. Left-align text for a specific line\n");
    printf("4. Right-align text for a specific line\n");
    printf("5. Reverse text for a specific line\n");
    printf("6. Count occurrences of a word\n");
    printf("7. Replace a word with another\n");
    printf("8. Display current text\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

char** enterText(char** lines, int* lineCount) {
    char input[MAX_LINE_LENGTH];
    printf("\nEnter text lines (enter an empty line to finish):\n");
    
    while (1) {
        printf("Line %d: ", *lineCount + 1);
        fgets(input, MAX_LINE_LENGTH, stdin);
        
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        
        if (input[0] == '\0') {
            break;
        }
        
        lines = (char**)realloc(lines, (*lineCount + 1) * sizeof(char*));
        if (!lines) {
            printf("Memory allocation error!\n");
            exit(1);
        }
        
        lines[*lineCount] = (char*)malloc(strlen(input) + 1);
        if (!lines[*lineCount]) {
            printf("Memory allocation error!\n");
            exit(1);
        }
        
        strcpy(lines[*lineCount], input);
        (*lineCount)++;
    }
    
    printf("Text input completed. Total lines: %d\n", *lineCount);
    return lines;
}

int countWords(char** lines, int lineCount) {
    int totalWords = 0;
    
    for (int i = 0; i < lineCount; i++) {
        char* line = lines[i];
        int inWord = 0;
        
        for (int j = 0; line[j] != '\0'; j++) {
            int isDelimiter = (line[j] == ' ' || line[j] == '\t' || 
                              line[j] == '.' || line[j] == '!' || line[j] == '?');
            
            if (!isDelimiter && !inWord) {
                inWord = 1;
                totalWords++;
            } else if (isDelimiter) {
                inWord = 0;
            }
        }
    }
    
    return totalWords;
}

void leftAlignText(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    int lineNum;
    printf("Enter line number to left-align (1-%d): ", lineCount);
    scanf("%d", &lineNum);
    getchar();
    
    if (lineNum < 1 || lineNum > lineCount) {
        printf("Invalid line number!\n");
        return;
    }
    
    char* line = lines[lineNum - 1];
    
    int startPos = 0;
    while (line[startPos] == ' ' || line[startPos] == '\t') {
        startPos++;
    }
    
    if (startPos > 0) {
        memmove(line, line + startPos, strlen(line + startPos) + 1);
        printf("Line %d left-aligned.\n", lineNum);
    } else {
        printf("Line %d is already left-aligned.\n", lineNum);
    }
}

void rightAlignText(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    int lineNum;
    printf("Enter line number to right-align (1-%d): ", lineCount);
    scanf("%d", &lineNum);
    getchar();
    
    if (lineNum < 1 || lineNum > lineCount) {
        printf("Invalid line number!\n");
        return;
    }
    
    char* line = lines[lineNum - 1];
    
    int len = strlen(line);
    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t')) {
        line[--len] = '\0';
    }
    
    int padding = MAX_LINE_LENGTH - 1 - len;
    if (padding <= 0) {
        printf("Line %d is too long for right-alignment.\n", lineNum);
        return;
    }
    
    char* newLine = (char*)malloc(MAX_LINE_LENGTH);
    if (!newLine) {
        printf("Memory allocation error!\n");
        return;
    }
    
    for (int i = 0; i < padding; i++) {
        newLine[i] = ' ';
    }
    
    strcpy(newLine + padding, line);
    
    free(lines[lineNum - 1]);
    lines[lineNum - 1] = newLine;
    
    printf("Line %d right-aligned.\n", lineNum);
}

void reverseText(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    int lineNum;
    printf("Enter line number to reverse (1-%d): ", lineCount);
    scanf("%d", &lineNum);
    getchar();
    
    if (lineNum < 1 || lineNum > lineCount) {
        printf("Invalid line number!\n");
        return;
    }
    
    char* line = lines[lineNum - 1];
    int len = strlen(line);
    
    for (int i = 0; i < len / 2; i++) {
        char temp = line[i];
        line[i] = line[len - i - 1];
        line[len - i - 1] = temp;
    }
    
    printf("Line %d reversed.\n", lineNum);
}

void countWordOccurrences(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    char word[MAX_LINE_LENGTH];
    printf("Enter word to search for: ");
    scanf("%s", word);
    getchar();
    
    int totalOccurrences = 0;
    
    for (int i = 0; i < lineCount; i++) {
        char* line = lines[i];
        char* pos = line;
        
        while ((pos = strstr(pos, word)) != NULL) {
            int isWholeWord = 1;
            
            if (pos > line) {
                char before = *(pos - 1);
                if (!(before == ' ' || before == '\t' || 
                      before == '.' || before == '!' || before == '?')) {
                    isWholeWord = 0;
                }
            }
            
            char after = *(pos + strlen(word));
            if (after != '\0' && !(after == ' ' || after == '\t' || 
                                   after == '.' || after == '!' || after == '?')) {
                isWholeWord = 0;
            }
            
            if (isWholeWord) {
                totalOccurrences++;
            }
            
            pos += strlen(word);
        }
    }
    
    printf("The word '%s' appears %d times in the text.\n", word, totalOccurrences);
}

void replaceWord(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    char oldWord[MAX_LINE_LENGTH], newWord[MAX_LINE_LENGTH];
    
    printf("Enter word to replace: ");
    scanf("%s", oldWord);
    getchar();
    
    printf("Enter replacement word: ");
    scanf("%s", newWord);
    getchar();
    
    int replacements = 0;
    
    for (int i = 0; i < lineCount; i++) {
        char* line = lines[i];
        
        int maxNewSize = strlen(line) * 2;
        if (strlen(newWord) > strlen(oldWord)) {
            int potentialReplacements = strlen(line) / (strlen(oldWord) + 1) + 1;
            maxNewSize += potentialReplacements * (strlen(newWord) - strlen(oldWord));
        }
        
        char* newLine = (char*)malloc(maxNewSize);
        if (!newLine) {
            printf("Memory allocation error!\n");
            return;
        }
        
        newLine[0] = '\0';
        
        char* remaining = line;
        char* match;

        while ((match = strstr(remaining, oldWord)) != NULL) {
            int isWholeWord = 1;
            
            if (match > line) {
                char before = *(match - 1);
                if (!(before == ' ' || before == '\t' || 
                      before == '.' || before == '!' || before == '?')) {
                    isWholeWord = 0;
                }
            }
            
            char after = *(match + strlen(oldWord));
            if (after != '\0' && !(after == ' ' || after == '\t' || 
                                  after == '.' || after == '!' || after == '?')) {
                isWholeWord = 0;
            }
            
            int prefixLen = match - remaining;
            strncat(newLine, remaining, prefixLen);
            
            if (isWholeWord) {
                strcat(newLine, newWord);
                replacements++;
            } else {
                strncat(newLine, match, strlen(oldWord));
            }
            
            remaining = match + strlen(oldWord);
        }
        
        strcat(newLine, remaining);
        
        free(lines[i]);
        lines[i] = newLine;
    }
    
    printf("Replaced %d occurrences of '%s' with '%s'.\n", replacements, oldWord, newWord);
}

void displayText(char** lines, int lineCount) {
    if (lineCount == 0) {
        printf("No text available. Please enter text first.\n");
        return;
    }
    
    printf("\n---------- Current Text ----------\n");
    for (int i = 0; i < lineCount; i++) {
        printf("Line %d: %s\n", i + 1, lines[i]);
    }
    printf("---------------------------------\n");
}

void freeMemory(char** lines, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    char** lines = NULL;
    int lineCount = 0;
    int choice;
    
    do {
        printMenu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                lines = enterText(lines, &lineCount);
                break;
            case 2:
                if (lineCount == 0) {
                    printf("No text available. Please enter text first.\n");
                } else {
                    int wordCount = countWords(lines, lineCount);
                    printf("Total number of words: %d\n", wordCount);
                }
                break;
            case 3:
                leftAlignText(lines, lineCount);
                break;
            case 4:
                rightAlignText(lines, lineCount);
                break;
            case 5:
                reverseText(lines, lineCount);
                break;
            case 6:
                countWordOccurrences(lines, lineCount);
                break;
            case 7:
                replaceWord(lines, lineCount);
                break;
            case 8:
                displayText(lines, lineCount);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    freeMemory(lines, lineCount);
    
    return 0;
}