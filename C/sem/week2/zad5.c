#include<stdio.h>

int main(){
    int sec1,sec2,sec3;
    scanf("%d",&sec1);
    scanf("%d",&sec2);
    scanf("%d",&sec3);
    int sumOfSec=sec1+sec2+sec3;
    int min=sumOfSec/60;
    int sec=sumOfSec%60;
    if(sec<10){
        printf("%d:0%d",min,sec);
    }
    else{
        printf("%d:%d",min,sec);
    }
}