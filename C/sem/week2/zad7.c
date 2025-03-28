#include<stdio.h>
#include <ctype.h>

int main(){
    int km;
    scanf("%d",&km);
    char type;
    scanf(" %c",&type);
    float taxiPrice=0;
    if(tolower(type)=='d'){
        taxiPrice = 0.79*km+0.70;
    }
    else if (tolower(type)=='n'){
        taxiPrice = 0.90*km+0.70;
    }
    if(km<20){
        printf("Cheapest transport is with taxi: %.2f$",taxiPrice);
        return 0;
    }
    else if (km<100)
    {
        float busPrice = 0.09*km;   
        printf("Cheapest transport is with bus: %.2f$",busPrice);
        return 0;
    }
    else{
        float trainPrice = 0.06*km;
        printf("Cheapest transport is with train: %.2f$",trainPrice);
        return 0;
    }
    
    
    
}