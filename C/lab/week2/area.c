#include<stdio.h>
#include <stdlib.h>

int main(){
    // int a;
    // int b;
    // scanf("%d",&a);
    // scanf("%d",&b);
    // int area=a*b;
    // printf("%d",area);

    // int r;
    // scanf("%d",&r);
    // double circle=r*3.14;
    // printf("%lf",circle);

    // int num;
    // scanf("%d",&num);
    // if(num&1==1)
    // {
    //     printf("Odd");
    // }
    // else
    // {
    //     printf("Even");
    // }
    
    // int rows;
    // scanf("%d",&rows);
    // for (size_t i = 0; i < rows; i++)
    // {
    //     for (size_t k = rows; k > rows/2+i-1; k--)
    //     {
    //         printf(" ");
    //     }
        
    //     for (size_t j = 0; j < i*2+1; j++)
    //     {
    //         printf("%c","$");
    //     }
    //     printf("\n");
    // }


    int x1,y1;
    int x2,y2;

    scanf("%d",&x1);
    scanf("%d",&y1); 
    scanf("%d",&x2);
    scanf("%d",&y2); 
    int x=abs(x2-x1);
    int y=abs(y2-y1);
    double area=x*y;
    printf("%lf",area);
}