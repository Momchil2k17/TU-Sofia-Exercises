#include<stdio.h>

int main(){
    int n;
    printf("Enter N: \n");
    scanf("%d", &n);
    int arr[n];
    int targetSum;
    printf("Enter the target sum: \n");
    scanf("%d", &targetSum);
    printf("Enter the elements of the array: \n");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];
            if (sum == targetSum) {
                for (int i = start; i <= end; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("Not found\n");
}