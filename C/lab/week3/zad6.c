#include<stdio.h>

void toBinary(int num){
    int bin[64];
    int count=0;
    while (num>0)
    {
        bin[count]=num%2;
        num/=2;
        count+=1;
    }

    for (int i = count-1; i >= 0; i--)
    {
        printf("%d",bin[i]);
    }
    
}

int main(){
    toBinary(173);
}