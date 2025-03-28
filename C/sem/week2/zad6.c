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
    int x1,y1,x2,y2;
    scanf("%d",&x1);
    scanf("%d",&y1);
    scanf("%d",&x2);
    scanf("%d",&y2);
    int x,y;
    scanf("%d",&x);
    scanf("%d",&y);
    int minx=min(x1,x2);
    int maxx=max(x1,x2);
    int miny=min(y1,y2);
    int maxy=max(y1,y2);
    if(x>=minx && x<=maxx && y>=miny && y<=maxy){
        printf("Inside");
    }else{
        printf("Outside");
    }
}