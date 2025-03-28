#include<stdio.h>

int main(){
    int a,b,c,d,e;
    scanf("%d",&a);
    scanf("%d",&b);
    while (b<=a)
    {
        scanf("%d",&b);
    }
    scanf("%d",&c);
    while (c<=b)
    {
        scanf("%d",&c);
    }
    scanf("%d",&d);
    while (d<=c)
    {
        scanf("%d",&d);
    }
    scanf("%d",&e);
    while (e<=d)
    {
        scanf("%d",&e);
    }
    printf("%d %d %d %d %d",a,b,c,d,e);

    //scan a new num and find the position to insert it
    int newNum;
    scanf("%d",&newNum);
    if (newNum<a)
    {
        printf("%d %d %d %d %d %d",newNum,a,b,c,d,e);
    }
    else if (newNum<b)
    {
        printf("%d %d %d %d %d %d",a,newNum,b,c,d,e);
    }
    else if (newNum<c)
    {
        printf("%d %d %d %d %d %d",a,b,newNum,c,d,e);
    }
    else if (newNum<d)
    {
        printf("%d %d %d %d %d %d",a,b,c,newNum,d,e);
    }
    else if (newNum<e)
    {
        printf("%d %d %d %d %d %d",a,b,c,d,newNum,e);
    }
    else
    {
        printf("%d %d %d %d %d %d",a,b,c,d,e,newNum);
    }
    
}