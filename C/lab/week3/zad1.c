#include<stdio.h>
int main(){
    int *ptr;
    int a=5;

    ptr=&a;

    printf("Address: %x\n",ptr);
    printf("Value: %d",*ptr);
}