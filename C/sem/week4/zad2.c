#include <stdio.h>

#define SIZE 20

// Function to calculate sum of surrounding elements
int calculateSurroundingSum(int matrix[SIZE][SIZE], int n, int m, int row, int col) {
    int sum = 0;
    
    // Check all 8 surrounding positions
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Skip the element itself and out of bounds positions
            if ((i == row && j == col) || i < 0 || j < 0 || i >= n || j >= m) {
                continue;
            }
            
            sum += matrix[i][j];
        }
    }
    
    return sum;
}

int main() {
    int n, m;
    int matrix[SIZE][SIZE];
    int maxSum = -1000000;
    int maxNumRow = 0, maxNumCol = 0;
    printf("Enter matrix dimensions (N M): ");
    scanf("%d %d", &n, &m);
    
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int surroundingSum = calculateSurroundingSum(matrix, n, m, i, j);
            
            if (surroundingSum > maxSum) {
                maxSum = surroundingSum;
                maxNumRow = i;
                maxNumCol = j;
            }
        }
    }
    printf("Number with maximum surrounding sum: %d\n", matrix[maxNumRow][maxNumCol]);
    printf("Position: [%d][%d]\n", maxNumRow, maxNumCol);
    printf("Sum of surrounding elements: %d\n", maxSum);
    
    return 0;
}