#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 20

const char *words[] = {
    "algorithm",
    "function",
    "variable",
    "integer",
    "structure",
    "computer",
    "pointer",
    "memory",
    "javascript",
    "python",
    "elephant",
    "banana",
    "chocolate",
    "universe",
    "programming",
    "mountain",
    "ocean",
    "galaxy",
    "concatenation",
    "adventure"
};

int main() {
    srand(time(NULL));
    
    int randomIndex = rand() % MAX_WORDS;
    char secretWord[MAX_WORD_LENGTH];
    strcpy(secretWord, words[randomIndex]);
    
    int wordLength = strlen(secretWord);
    int maxAttempts = wordLength + 2;
    
    char displayWord[MAX_WORD_LENGTH];
    for (int i = 0; i < wordLength; i++) {
        displayWord[i] = '_';
    }
    displayWord[wordLength] = '\0';
    
    char guessedLetters[26] = {0};
    int lettersGuessed = 0;
    int correctLettersCount = 0;
    
    printf("Welcome to the Hangman game!\n");
    printf("You need to guess a word with %d characters.\n", wordLength);
    printf("You have a maximum of %d attempts.\n\n", maxAttempts);
    
    while (lettersGuessed < maxAttempts && correctLettersCount < wordLength) {
        printf("Word: ");
        for (int i = 0; i < wordLength; i++) {
            printf("%c ", displayWord[i]);
        }
        
        printf("\nLetters used: %d/%d\n", lettersGuessed, maxAttempts);
        
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        
        if (guessedLetters[guess - 'a']) {
            printf("You already tried this letter! Try a different one.\n\n");
            continue;
        }
        
        guessedLetters[guess - 'a'] = 1;
        lettersGuessed++;
        
        int foundLetter = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess && displayWord[i] == '_') {
                displayWord[i] = guess;
                foundLetter = 1;
                correctLettersCount++;
            }
        }
        
        if (foundLetter) {
            printf("Correct! The letter '%c' is in the word.\n\n", guess);
        } else {
            printf("Sorry, the letter '%c' is not in the word.\n\n", guess);
        }
    }
    
    if (correctLettersCount == wordLength) {
        printf("Congratulations! You guessed the word: %s\n", secretWord);
        printf("You used %d out of %d possible attempts.\n", lettersGuessed, maxAttempts);
        printf("You won the game!\n");
    } else {
        printf("Sorry, you couldn't guess the word: %s\n", secretWord);
        printf("You used all %d attempts.\n", maxAttempts);
        printf("Try again!\n");
    }
    
    return 0;
}