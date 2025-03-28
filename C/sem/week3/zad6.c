#include <stdio.h>
#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int n;
    int inc_start = 0, inc_len = 1; 
    int dec_start = 0, dec_len = 1; 
    int curr_inc_start = 0, curr_inc_len = 1;
    int curr_dec_start = 0, curr_dec_len = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            curr_inc_len++;
            if (curr_inc_len > inc_len) {
                inc_len = curr_inc_len;
                inc_start = curr_inc_start;
            }
        } else {
            curr_inc_start = i;
            curr_inc_len = 1;
        }
        if (arr[i] < arr[i-1]) {
            curr_dec_len++;
            if (curr_dec_len > dec_len) {
                dec_len = curr_dec_len;
                dec_start = curr_dec_start;
            }
        } else {
            curr_dec_start = i;
            curr_dec_len = 1;
        }
    }

    if (inc_len >= dec_len) {
        for (int i = inc_start; i < inc_start + inc_len; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = dec_start; i < dec_start + dec_len; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}