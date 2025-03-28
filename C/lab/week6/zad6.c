#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int N, K;
    
    scanf("%d", &N);
    scanf("%d", &K);
    
  
    int arr[N];
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, N);
    
    int sum = 0;
    for (int i = N-K; i < N; i++) {
        sum += arr[i];
    }
    
    printf("Largest nums are\n");
    for (int i = N-K; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum of the %d largest elements: %d\n", K, sum);
    
    return 0;
}