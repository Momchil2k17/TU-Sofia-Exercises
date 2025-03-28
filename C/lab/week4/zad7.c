#include<stdio.h>

void found(){
    int a,b,c,d,e,f;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    scanf("%d",&f);
    if(a==f || b==f || c==f || d==f || e==f){
        printf("Found");
    }
    else{
        printf("Not found");
    }
}

int main(){
    found();
}