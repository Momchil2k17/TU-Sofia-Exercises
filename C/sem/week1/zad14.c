#include <stdio.h>
int main() {
    
    double n, m; 
    int kg_vegetables, kg_fruits; 
    
    scanf("%lf", &n); 
    scanf("%lf", &m); 
    scanf("%d", &kg_vegetables); 
    scanf("%d", &kg_fruits); 
    double totalLv = (n * kg_vegetables) + (m* kg_fruits);
    
    double totalEur = totalLv / 1.95;
    
    printf("%.2f\n", totalEur);

}