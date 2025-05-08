#include <stdio.h>

int checkRowsAscending(int matrix[20][20], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] <= matrix[i][j - 1]) {
                return 0; 
            }
        }
    }
    return 1;
}

int checkColumnsDescending(int matrix[20][20], int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] >= matrix[i - 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int rows, cols;
    int matrix[20][20];
    
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int rowsAscending = checkRowsAscending(matrix, rows, cols);
    int columnsDescending = checkColumnsDescending(matrix, rows, cols);
    
    if (rowsAscending && columnsDescending) {
        printf("Valid matrix\n");
    } else {
        if (!rowsAscending) {
            printf("Rows are not in ascending order\n");
        }
        if (!columnsDescending) {
            printf("Columns are not in descending order\n");
        }
    }
    
    return 0;
}