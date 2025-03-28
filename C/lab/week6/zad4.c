#include <stdio.h>

#define MAX_SIZE 20

int main() {
    int arr[MAX_SIZE];
    int n, i, maxCount = 1, currentCount = 1;
    int maxElement, currentElement;
    int startIndex = 0;

   
    scanf("%d", &n);

  
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    currentElement = arr[0];
    maxElement = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxElement = currentElement;
                startIndex = i - currentCount; 
            }
            currentElement = arr[i];
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxElement = currentElement;
        startIndex = n - currentCount; 
    }

    for (i = startIndex; i < startIndex + maxCount; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
