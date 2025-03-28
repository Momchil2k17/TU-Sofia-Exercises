#include<stdio.h>
#include <stdlib.h>

int countOfNum(int num){
    int count=0;
    while (abs(num)>0)
    {
        num/=10;
        count++;
    }
    return count;
    
}

int main(){
    printf("%d",countOfNum(-1234));
}