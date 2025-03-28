#include<stdio.h>

int main(){
    float a,b;
    float *p1,*p2;

    a=5;
    b=2;
    p1=&a;
    p2=&b;

    printf("%.2f\n",*p1+*p2);
    printf("%.2f\n",*p1-*p2);
    printf("%.2f\n",*p1**p2);
    if(*p2==0){
        printf("Invalid operation!");
    }
    else{
        printf("%.2f\n",*p1/(*p2));
    }
}