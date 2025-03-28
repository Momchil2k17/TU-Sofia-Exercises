#include<stdio.h>

int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for (size_t i = 2; i < n; i++)
    {
        if(n%i==0){
            return 0;
        }
    }
    return n;
    
}
int sumOfPrime(int n){
    int sum=0;
    for (size_t i = 1; i < n; i++)
    {
        sum+=isPrime(i);
    }
    return sum;
    
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Sum of prime numbers between 1-%d: %d ",n,sumOfPrime(n));   
}