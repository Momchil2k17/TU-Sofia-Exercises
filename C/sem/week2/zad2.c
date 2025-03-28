#include<stdio.h>

int main(){
    int hour,minutes;
    scanf("%d",&hour);
    scanf("%d",&minutes);
    if(minutes+15>=60){
        if(hour+1>=24){
            hour = 0;
        }else{
            hour++;
        }
        minutes = (minutes+15)%60;
    }else{
        minutes+=15;
    }
    if(minutes<10){
        printf("%d:0%d",hour,minutes);
    }
    else{
    printf("%d:%d",hour,minutes);
    }
}