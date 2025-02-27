#include<stdio.h>
#include <math.h>

int main(){
    double degrees;
    scanf("%lf",&degrees);
    double radians=degrees*3.14/180;
    double sine = sin(radians);
    double cosine = cos(radians);
    double tangent = tan(radians);
    double cotangent=1/tangent;
    printf("Sin: %.2lf\n", sine);
    printf("Cos: %.2lf\n", cosine);
    printf("Tan: %.2lf\n", tangent);
    printf("Cotg: %.2lf\n", cotangent);
}