#include<stdio.h>

int main(){
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);
    int count[256] = {0};
    for (int i = 0; str[i]; i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if(count[i]>0){
            printf("%c: %d\n", i, count[i]);
        }
    }
    
}