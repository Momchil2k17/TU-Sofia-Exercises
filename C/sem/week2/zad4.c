#include<stdio.h>

int main(){
    float points;
    scanf("%f",&points);
    float bonus=0;
    if(points<=100){
        bonus = 5;
    }else if(points>100 && points<=1000){
        bonus = points*0.2;
    }else if(points>1000){
        bonus = points*0.1;
    }

    if((int)points%2==0){
        bonus+=1;}
    else if((int)points%10==5){
        bonus+=2;
    }
    printf("Bonus: %.1lf",bonus);
    printf("\nTotal: %.1f",points+bonus);

}