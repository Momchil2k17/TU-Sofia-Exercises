#include<stdio.h>

int main(){
    int nums[20];

    for (size_t i = 0; i < 20; i++)
    {
        nums[i] = i*5;
    }

    for (size_t i = 0; i < 20; i++)
    {
        printf("%d\n", nums[i]);
    }
    
}