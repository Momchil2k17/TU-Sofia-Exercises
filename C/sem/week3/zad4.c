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

    for (size_t i = 0; i < k; i++)
    {
        int last = arr[n-1];
        for (size_t j = n-1; j >= 1; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = last;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}