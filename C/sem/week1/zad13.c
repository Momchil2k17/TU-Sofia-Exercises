#include<stdio.h>
#include<math.h>

int main(){

   double w,h;
   scanf("%lf",&w);
   scanf("%lf",&h);
   double area=w*(h-1);
   double singleSeat=0.7*1.2;
   int seats=ceil(area/singleSeat)-3;
   printf("%d",seats);
}