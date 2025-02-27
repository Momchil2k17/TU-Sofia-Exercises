#include<stdio.h>
#include <stdlib.h>

int main(){

    int x1,y1;
    int x2,y2;

    scanf("%d",&x1);
    scanf("%d",&y1); 
    scanf("%d",&x2);
    scanf("%d",&y2); 
    int x=abs(x2-x1);
    int y=abs(y2-y1);
    double area=x*y;
    printf("%0.1lf",area);
}