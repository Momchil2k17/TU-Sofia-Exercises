#include<stdio.h>

int sumToNum(int n){
    if(n==0){
        return 0;
    }
    return n+sumToNum(n-1);
}


int main(){
    printf("%d",sumToNum(20));
}