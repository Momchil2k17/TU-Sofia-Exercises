#include <stdio.h>

#define MAX_SIZE 20

int main() {
    int n, m;
    int matrix[MAX_SIZE][MAX_SIZE];
    int max_val, min_val;
    int max_row = 0, min_row = 0;
    
    printf("Enter number of rows (N): ");
    scanf("%d", &n);
    printf("Enter number of columns (M): ");
    scanf("%d", &m);
    
    printf("Enter the matrix elements:\n");
    scanf("%d", &matrix[0][0]);
    min_val = max_val = matrix[0][0];
    
    for (int j = 1; j < m; j++) {
        scanf("%d", &matrix[0][j]);
        if (matrix[0][j] > max_val) {
            max_val = matrix[0][j];
            max_row = 0;
        }
        if (matrix[0][j] < min_val) {
            min_val = matrix[0][j];
            min_row = 0;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            
            // Update min and max while reading
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
            }
            if (matrix[i][j] < min_val) {
                min_val = matrix[i][j];
                min_row = i;
            }
        }
    }
    printf("\nOriginal matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Max element %d is in row %d\n", max_val, max_row);
    printf("Min element %d is in row %d\n", min_val, min_row);
    
    if (max_row != min_row) {
        for (int j = 0; j < m; j++) {
            int temp = matrix[max_row][j];
            matrix[max_row][j] = matrix[min_row][j];
            matrix[min_row][j] = temp;
        }
    }
    printf("\nMatrix after swapping rows %d and %d:\n", max_row, min_row);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}