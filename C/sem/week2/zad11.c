#include <stdio.h>

void printFirstRow(int n) {
    int side = n / 2;

    printf("/");
    for (int i = 0; i < side; i++) {
        printf("^");
    }
    printf("\\");
    if(n>4){
        for (int i = 0; i < side; i++) {
            printf("_");
        }
    }
    printf("/");
    for (int i = 0; i < side; i++) {
        printf("^");
    }
    printf("\\\n");
}

void printMiddleRows(int n) {
    int totalWidth = 2 * n;
    int side = n / 2;

    for (int i = 0; i < n - 2; i++) {
        printf("|");
        for (int j = 0; j < totalWidth - 2; j++) {
            if (j < side || j >= totalWidth - side - 2) {
                printf(" ");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    if(n>4){
        printf("|");
        for (int j = 0; j < totalWidth-2 ; j++) {
            if (j < side+1 || j >= totalWidth - side - 3) {
                printf(" ");
            } else {
                printf("_");
            }
        }
        printf("|\n");
    }
}

void printLastRow(int n) {
    int middle = n - 2;
    int side = n / 2;

    printf("\\");
    for (int i = 0; i < side; i++) {
        printf("_");
    }
    printf("/");
    if(n>4){
        for (int i = 0; i < side; i++) {
            printf(" ");
        }
    }
    printf("\\");
    for (int i = 0; i < side; i++) {
        printf("_");
    }
    printf("/\n");
}

int main() {
    int n;
    scanf("%d", &n);

    printFirstRow(n);
    printMiddleRows(n);
    printLastRow(n);

    return 0;
}