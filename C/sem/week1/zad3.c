#include<stdio.h>

int main(){
    char symbol;
    scanf("%c",&symbol);
    for (size_t i = 0; i < 10; i++)
    {
       printf("%c",symbol);
    }
    printf("\n%c        %c",symbol,symbol);
    printf("\n%c        %c",symbol,symbol);
    printf("\n%c        %c\n",symbol,symbol);
    for (size_t i = 0; i < 10; i++)
    {
       printf("%c",symbol);
    }
}