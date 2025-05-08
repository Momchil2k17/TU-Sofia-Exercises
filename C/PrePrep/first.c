#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} Car;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
   int *ptr = arr;
   printf("arr[2] = %d\n", arr[2]);
   printf("*(arr + 2) = %d\n", *(arr + 2));
   printf("ptr[2] = %d\n", ptr[3]);
   printf("*(ptr + 2) = %d\n", *(ptr + 2));
   return 0;

}

