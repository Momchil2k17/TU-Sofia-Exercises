#include<stdio.h>

void binaryToHexadecimal(long long binary) {
    int decimal = 0;
    int base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        base *= 2;
        binary /= 10;
    }

    printf("Hexadecimal: %X\n", decimal);
}

int main(){
    binaryToHexadecimal(101111);
}