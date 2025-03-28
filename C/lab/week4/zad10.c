#include<stdio.h>
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void nums(){
    int num1,num2,num3,num4;
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);
    scanf("%d",&num4);
    printf("%d %d %d %d\n",num1,num2,num3,num4);

    swap(&num1,&num4);
    swap(&num2,&num3);
    printf("%d %d %d %d",num1,num2,num3,num4);
}



int main(){
    nums();
}