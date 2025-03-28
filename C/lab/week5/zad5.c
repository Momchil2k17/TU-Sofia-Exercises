#include<stdio.h>
int add(int a,int b){
    return a*5+(b-10);
}


int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
    printf("%d\n",add(a,b));
    printf("%d\n",a+b);

}