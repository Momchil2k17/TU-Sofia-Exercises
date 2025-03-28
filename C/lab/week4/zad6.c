#include<stdio.h>

void printFibonacciRecursive(int a, int b, int limit) {
    if(limit<0){
        printf("Invalid case");
    }
    if (a > limit) return; 

    printf("%d ", a);
    printFibonacciRecursive(b, a + b, limit);
}

int main(){
    printFibonacciRecursive(0,1,-1);
    printFibonacciRecursive(0,1,24);
}