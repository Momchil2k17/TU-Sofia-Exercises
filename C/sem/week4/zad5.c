#include <stdio.h>

#define MAX_SIZE 100  // Maximum number of elements

int main() {
    int numbers[MAX_SIZE];  // Array to store the numbers
    int count = 0;          // Current number of elements
    
    int command, x;
    
    printf("Children's Number Software\n");
    printf("Commands:\n");
    printf("1: add(x) - Add number x\n");
    printf("2: delete(x) - Delete all occurrences of x\n");
    printf("3: smallest(x) - Find the xth smallest number\n");
    printf("0: exit - Exit the program\n");
    
    while (1) {
        printf("\nEnter command (0-3): ");
        scanf("%d", &command);
        
        switch (command) {
            case 0:  // Exit
                printf("Goodbye!\n");
                return 0;
                
            case 1:  // Add
                printf("Enter number to add: ");
                scanf("%d", &x);
                
                if (count < MAX_SIZE) {
                    numbers[count] = x;
                    count++;
                    printf("Added %d\n", x);
                } else {
                    printf("Cannot add more numbers, array is full!\n");
                }
                break;
                
            case 2:  // Delete
                printf("Enter number to delete: ");
                scanf("%d", &x);
                
                int newCount = 0;
                int deletedCount = 0;
                
                for (int i = 0; i < count; i++) {
                    if (numbers[i] != x) {
                        numbers[newCount] = numbers[i];
                        newCount++;
                    } else {
                        deletedCount++;
                    }
                }
                
                count = newCount;
                printf("Deleted %d occurrences of %d\n", deletedCount, x);
                break;
                
            case 3:  // Smallest
                printf("Enter position (x): ");
                scanf("%d", &x);
                
                if (x <= 0 || x > count) {
                    printf("Error: Cannot find %dth smallest element (count: %d)\n", x, count);
                } else {
                    // Make a copy of the array
                    int temp[MAX_SIZE];
                    for (int i = 0; i < count; i++) {
                        temp[i] = numbers[i];
                    }
                    
                    // Sort using simple bubble sort
                    for (int i = 0; i < count - 1; i++) {
                        for (int j = 0; j < count - i - 1; j++) {
                            if (temp[j] > temp[j + 1]) {
                                int t = temp[j];
                                temp[j] = temp[j + 1];
                                temp[j + 1] = t;
                            }
                        }
                    }
                    
                    printf("The %dth smallest number is: %d\n", x, temp[x - 1]);
                }
                break;
                
            default:
                printf("Unknown command. Please try again.\n");
        }
        
        // Print current state
        printf("Current numbers: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }
    
    return 0;
}