#include<stdio.h>

int main(){
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    
}