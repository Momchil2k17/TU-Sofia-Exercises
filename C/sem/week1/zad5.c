#include<stdio.h>

int main(){
    double inches;
    scanf("%lf",&inches);
    printf("mm: %0.2lf\n",inches*25.4);
    printf("cm: %0.2lf\n",inches*2.54);
    printf("dm: %0.2lf\n",inches*0.254);
    printf("m: %0.2lf\n",inches*0.0254);
}