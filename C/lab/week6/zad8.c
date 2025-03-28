#include <stdio.h>

int main() {
    int arr[10], count[10] = {0}, n, maxCount = 0, mostFrequent;

    for (n = 0; n < 10; n++) {
        if (scanf("%d", &arr[n]) != 1) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostFrequent = arr[i];
        }
    }
    
    printf(" %d (%d times)\n", mostFrequent, maxCount + 1);
    
    return 0;
}
