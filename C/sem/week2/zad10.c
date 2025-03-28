#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float p1,p2,p3,p4,p5;
    int count1=0,count2=0,count3=0,count4=0,count5=0;
    for (size_t i = 0; i < n; i++)
    {
        float num;
        printf("Num %d: ",i+1);
        scanf("%f",&num);
        while (num<1 || num>1000)
        {
            printf("Invalid number! Enter a number between 1 and 1000: \n");
            printf("Num %d: ",i+1);
            scanf("%f",&num);
        }
        
        if(num<200){
            count1++;
        }else if(num<400){
            count2++;
        }else if(num<600){
            count3++;
        }else if(num<800){
            count4++;
        }else{
            count5++;
        }
    }
    p1=(float)count1/n*100;
    p2=(float)count2/n*100; 
    p3=(float)count3/n*100;
    p4=(float)count4/n*100;
    p5=(float)count5/n*100;
    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%",p1,p2,p3,p4,p5);
    
}