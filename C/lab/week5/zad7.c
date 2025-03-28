#include<stdio.h>

int main(){
    char str1[256],str2[256];
    gets(str1);
    gets(str2);
    //check if strings are equal
    printf("%p\n",&str1);
    printf("%p\n",&str2);
    
}