#include<stdio.h>

void Change(int *num1,int *num2){
    *num1=*num1+*num2;
    *num2=*num1-*num2;
    *num1=*num1-*num2;
}

int main(){
    int a=5;
    int b=4;
    Change(&a,&b);
    printf("%d\n",a);
    printf("%d",b);
}