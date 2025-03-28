#include<stdio.h>

void Square(){
    printf("Type: Square\n");
    float a;
    scanf("%f",&a);
    printf("Area: %.2f\n",a*a);
}
void Rectanle(){
    printf("Type: Rectanle\n");
    float a,b;
    scanf("%f",&a);
    scanf("%f",&b);
    printf("Area: %.2f\n",a*b);
}
void Triangle(){
    printf("Type: Triangle\n");
    float a,b;
    scanf("%f",&a);
    scanf("%f",&b);
    printf("Area: %.2f\n",a*b/2);
}
void Circle(){
    printf("Type: Circle\n");
    float r;
    scanf("%f",&r);
    printf("Area: %.2f\n",r*r*3.14);
}

int main(){
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        Square();
    }
    else if(choice==2){
        Triangle();
    }
    else if(choice==3){
        Circle();
    }
    else if(choice==0){
        printf("Invalid choice");
    }
}