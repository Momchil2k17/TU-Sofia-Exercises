#include <stdio.h>
#include <stdbool.h>

void simpleNumbers(int n) {
    bool prime[n + 1];
    
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++) 
    {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    int sum = 0;
    printf("Simple number from 1 to %d: \n", n);
    for (int i = 2; i <= n; i++) 
    {
        if (prime[i]) 
        {
            sum = sum + i;
        }
    }
    printf("%d", sum);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    simpleNumbers(n);
}