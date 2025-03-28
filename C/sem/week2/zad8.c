#include<stdio.h>

int main(){
    float v;
    scanf("%f",&v);
    v*=1000;
    float deb1,deb2;
    scanf("%f",&deb1);
    scanf("%f",&deb2);
    float debSum=deb1+deb2;
    int h;
    scanf("%d",&h);
    v-=debSum*h;
    if(v<=0){
        printf("Pool is empty");
    }else{
        printf("Litres left: %.2f",v);
    }
}