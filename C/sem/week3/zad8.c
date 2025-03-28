#include<stdio.h>

void shiftRight(int arr[], int n) {
    for (int i = 19; i >= n; i--) {
        arr[i + 1] = arr[i];
    }
}

int main(){
    int arr[20]={};
    for (size_t i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
        {
            break;
        }
    }
    for (size_t i = 0; i < 20; i++)
    {
        int num,pos;
        scanf("%d %d", &num, &pos);
        if (num == 0)
        {
            break;
        }
        if (arr[pos] == 0)
        {
            arr[pos] = num;
        }
        else
        {
            shiftRight(arr, pos);
            arr[pos] = num;
        }
        for (int i = 0; i < 20; i++) {
                printf("%d ", arr[i]);
        }
    }
    

    for (int i = 0; i < 20; i++) {
        if (!arr[i] == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}