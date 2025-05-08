#include <stdio.h>

int main() {
    int n, m;
    
    printf("Enter number of rows (n): ");
    scanf("%d", &n);
    printf("Enter number of columns (m): ");
    scanf("%d", &m);
    
    if (n < 3 || m < 3) {
        printf("Error: Matrix should be at least 3x3 to find a 3x3 submatrix.\n");
        return 1;
    }
    
    int matrix[n][m];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int maxSum = -100000;
    int maxRow = 0, maxCol = 0;
    
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            int currentSum = 0;
            
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    currentSum += matrix[r][c];
                }
            }
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxRow = i;
                maxCol = j;
            }
        }
    }
    
    printf("\nSubmatrix with maximum sum (%d):\n", maxSum);
    for (int i = maxRow; i < maxRow + 3; i++) {
        for (int j = maxCol; j < maxCol + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}