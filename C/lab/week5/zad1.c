#include<stdio.h>

int main(){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int arr[5]={a,b,c,d,e};
    for (int i = 0; i < 5; i++){
        for (int j = i + 1; j < 5; j++){
            if (*(arr + i) > *(arr + j)){
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", *(arr + i));
    }


}