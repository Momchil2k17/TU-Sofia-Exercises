#include<stdio.h>

char str[]="This Value is unique for now";
char str2[]="This Value Already Exist";

char* findNum(){
    int a,b,c,d,e,newNum;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    scanf("%d", &newNum);
    if (a==newNum || b==newNum || c==newNum || d==newNum || e==newNum)
    {
        return str2;
    }
    return str;

}

int main(){
    char* result = findNum();
    printf("%s",result);
    return 0;
}

