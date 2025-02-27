#include <stdio.h>

int main() {
    int N, M;
    double dollar;

    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%lf", &dollar);

    double month = N * M;

    double yearly= 14.5 * month;

    double net_yearly = yearly * 0.75;

    double day = (net_yearly / 365) * dollar;

    printf("%.2f\n", day);

    return 0;
}
