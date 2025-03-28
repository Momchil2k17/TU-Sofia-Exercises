#include<stdio.h>

int Pow(int num,int pow){
    int res=1;
    for (size_t i = 0; i < pow; i++)
    {
        res*=num;
    }
    return res;
    
}

int main(){
    printf("%d",Pow(2,8));
}