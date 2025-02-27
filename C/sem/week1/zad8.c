#include<stdio.h>

int main(){
    double levs;
    scanf("%lf",&levs);
    printf("Dollar: %0.2lf\n",levs*0.53);
    printf("Euro: %0.2lf\n",levs*0.51);
    printf("Pound: %0.2lf\n",levs*0.42);

}