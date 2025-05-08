#include <stdio.h>
#include <stdlib.h>

int main() {
    int initialSize = 10; // Initial array size
    int* array = (int*)malloc(initialSize * sizeof(int));
    int currentSize = initialSize;
    
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter %d initial numbers:\n", initialSize);
    for (int i = 0; i < initialSize; i++) {
        scanf("%d", &array[i]);
    }
    
    int num, pos;
    printf("Enter number and position (0 to stop):\n");
    
    while (1) {
        scanf("%d", &num);
        
        if (num == 0) {
            break; 
        }
        
        scanf("%d", &pos);
        
        currentSize++;
        array = (int*)realloc(array, currentSize * sizeof(int));
        
        if (array == NULL) {
            printf("Memory reallocation failed\n");
            return 1;
        }
        
        for (int i = currentSize - 1; i > pos; i--) {
            array[i] = array[i - 1];
        }
        
        array[pos] = num;
    }
    
    printf("Final array: ");
    for (int i = 0; i < currentSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    free(array);
    
    return 0;
}