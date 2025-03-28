#include<stdio.h>

int isEven(int num) {
    if (num % 2 == 0) {
        return 0;  
    } else {
        return 1; 
    }
}

int main(){
   printf("%d\n",isEven(5));
   printf("%d",isEven(4));
}