#include<stdio.h>


int main(){
    
    int n;
    scanf("%d", &n);

    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        if ((i % 2 == 1 && arr[i] <= arr[i - 1]) || (i % 2 == 0 && arr[i] >= arr[i - 1])) {
            printf("False\n");
            return 0;
        }
    }
    printf("True\n");
    return 1; 

    
}