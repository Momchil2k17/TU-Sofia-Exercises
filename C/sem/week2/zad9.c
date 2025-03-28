#include<stdio.h>

int main(){
    float metres;
    scanf("%f",&metres);
    float metresForWine = metres*0.4;
    float wine=metresForWine/2.5;
    float wantedLitres;
    scanf("%f",&wantedLitres);

    if(wine<wantedLitres){
        printf("Not enough wine, %.1f liters of wine needed.",wantedLitres-wine);
    }
    else{
        int workers;
        printf("Enough wine, Total wine: %.1f liters.",wine);
        printf("\nEnter a number of workers: ");
        scanf("%d",&workers);
        float wineLeft = wine-wantedLitres;
        float winePerWorker = wineLeft/workers;
        printf("%.1f liters left -> %.1f liters per person.",wineLeft,winePerWorker);
    }
}