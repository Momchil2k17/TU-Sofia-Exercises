#include <stdio.h>

void enterAndPrintNumbers() {
    int num, previous;
    printf("Num 1: ");
    scanf("%d", &previous);

    for (int i = 2; i <= 5; i++) {
        do {
            printf("Num %d: ", i);
            scanf("%d", &num);
            if (num <= previous) {
                printf("Enter a higher number\n");
            }
        } while (num <= previous);
        previous = num;  
    }

    for (int i = 5; i >= 1; i--) {
        printf("%d ", previous);
        if (i > 1) {
            
            previous--;
        }
    }
}

int main() {
    enterAndPrintNumbers();
    return 0;
}
