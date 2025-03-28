#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    int maxNum = max(a,b);
    int minNum = min(a,b);
    int c;
    scanf("%d",&c);
    while (c!=0)
    {
        maxNum = max(maxNum,c);
        minNum = min(minNum,c);
        scanf("%d",&c);
    }
    printf("Max: %d\nMin: %d",maxNum,minNum);
    
    
}