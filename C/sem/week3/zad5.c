#include<stdio.h>

int main(){
    int n;
    printf("Enter N: \n");
    scanf("%d", &n);

    int k;
    printf("Enter K: \n");
    scanf("%d", &k);

    int arr[n];

    printf("Enter the elements of the array: \n");
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("The K-th biggest element is: %d\n", arr[k-1]);
}