#include<stdio.h>


int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int maxCount=1;
    int tempCount=1;
    for (size_t i = 1; i < n; i++)
    {
        if(arr[i-1]==arr[i]){
            tempCount++;
        }
        else{
            tempCount=1;
        }      
        if(tempCount>maxCount){
            maxCount=tempCount;
        }
    }
    printf("%d\n", maxCount);
    
}