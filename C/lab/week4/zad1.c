#include<stdio.h>

float avg(int nums[],int size){
    int sum = 0;
    if(size==0){
        return 0;
    }
    for (size_t i = 0; i < size; i++)
    {
        sum+=nums[i];
    }
    return (float)sum/size;
}
int min(int nums[],int size){
    int min=nums[0];
    for (size_t i = 1; i < size ; i++)
    {
        if(min>nums[i]){
            min=nums[i];
        }
    }
    return min;
    
    
}
int max(int nums[],int size){
    int max=nums[0];
    for (size_t i = 1; i < size ; i++)
    {
        if(max<nums[i]){
            max=nums[i];
        }
    }
    return max;
    
    
}
int main(){
    int nums[100];
    int count=0;
    int num;
    while (count < 100) {
        scanf("%d", &num);
        
        if (num == 0) break; 
        
        nums[count++] = num;
    }
    printf("%.2f\n",avg(nums,count));
    printf("%d\n",min(nums,count));
    printf("%d",max(nums,count));
}

