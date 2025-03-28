#include <stdio.h>

void printUpperWings(int n) {
    int side = n - 2;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < side; j++) {
            if (i % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\\ /");
        for (int j = 0; j < side; j++) {
            if (i % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

void printMiddleRow(int n) {
    int width = 2 * n - 3;
    for (int i = -1; i < width / 2; i++) {
        printf(" ");
    }
    printf("@\n");
}

void printLowerWings(int n) {
    int side = n - 2;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < side; j++) {
            if (i % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("/ \\");
        for (int j = 0; j < side; j++) {
            if (i % 2 == 0) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printUpperWings(n);
    printMiddleRow(n);
    printLowerWings(n);

    return 0;
}