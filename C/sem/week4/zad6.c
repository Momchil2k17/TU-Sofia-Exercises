#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            primeCount++;
        }
    }
    
    int* primeArr = (int*)malloc(primeCount * sizeof(int));
    int primeIndex = 0;
    
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            primeArr[primeIndex++] = arr[i];
        }
    }
    
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i])) {
            arr[newSize++] = arr[i];
        }
    }
    
    arr = (int*)realloc(arr, newSize * sizeof(int));
    
    printf("\nOriginal array after removing prime numbers (%d elements):\n", newSize);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nArray with prime numbers (%d elements):\n", primeCount);
    for (int i = 0; i < primeCount; i++) {
        printf("%d ", primeArr[i]);
    }
    printf("\n");
    
    free(arr);
    free(primeArr);
    
    return 0;
}