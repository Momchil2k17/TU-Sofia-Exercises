#include <stdio.h>

int main() {
    double N, W, L, M, O;
    scanf("%lf", &N);
    scanf("%lf", &W);
    scanf("%lf", &L);
    scanf("%lf", &M);
    scanf("%lf", &O);

    double totalarea = N * N;
    double peika = M * O;
    double plochki = W * L;

    double totalCover = totalarea - peika;
    double obshtoPlochki = totalCover / plochki;
    double time = obshtoPlochki * 0.2;

    printf("%.2lf\n", obshtoPlochki);
    printf("%.2fl\n", time);
}
