#include<stdio.h>
#include <math.h>

int main(){

    int x1,y1;
    int x2,y2;
    int x3,y3;

    scanf("%d",&x1);
    scanf("%d",&y1); 
    scanf("%d",&x2);
    scanf("%d",&y2); 
    scanf("%d",&x3);
    scanf("%d",&y3); 
    
    double area=0.5*abs((x1-x2)*(y1+y2)+(x2-x3)*(y2+y3)+(x3-x1)*(y3+y1));
    printf("%0.1lf",area);
}