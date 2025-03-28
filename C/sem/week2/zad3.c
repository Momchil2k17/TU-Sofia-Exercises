#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a==b && b==c){
        printf("YES");
    }
    else{
        printf("NO");
    }
}