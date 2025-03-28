#include<stdio.h>

int main(){
    //create an array of ints with 10 elements
    int arr[10];
    //create a pointer to the first element of the array
    int *p = arr;
    //create a pointer to the last element of the array
    int *q = arr + 9;
    //create a pointer to the middle element of the array
    int *r = arr + 4;
    //create a pointer to the second element of the array
    int *s = arr + 1;
    //print all the pointers
    printf("p: %p\n", p);
    printf("q: %p\n", q);
    printf("r: %p\n", r);
    printf("s: %p\n", s);
    //print the difference between the pointers
    printf("q - p: %ld\n", q - p);
    printf("r - p: %ld\n", r - p);
    printf("s - p: %ld\n", s - p);
    printf("r - s: %ld\n", r - s);
    
    char c = 'z';
    while (1==1)
    {
        printf("%c", &c);
    }
    
    
}