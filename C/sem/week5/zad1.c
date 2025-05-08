#include<stdio.h>
#include<string.h>

#define chair_price 13.99
#define table_price 42.00
#define glass_price 5.98
#define plate_price 21.02

int main(){
    int chairs=0,tables=0,glass_sets=0,plate_sets=0;
    int count;
    double total_price=0;
    scanf("%d", &count);

    char command[20];
    scanf("%s", command);
    while (1)
    {
      if (strcmp(command,"PARTY!")==0)
      {
        break;
      }
      
      if(strcmp(command,"Chair")==0){
        chairs++;
        total_price+=chair_price;
      }
      if (strcmp(command,"Table")==0){
        tables++;
        total_price+=table_price;
      }
      if (strcmp(command,"Cups")==0){
        glass_sets++;
        total_price+=glass_price;
      }
      if (strcmp(command,"Dishes")==0){
        plate_sets++;
        total_price+=plate_price;
      }
      scanf("%s", command);
      
    }
    int chairsNeeded=count-chairs;
    int tablesNeeded=(count+7)/7-tables;
    int glass_setsNeeded=(count+5)/6-glass_sets;
    int plate_setsNeeded=(count+5)/6-plate_sets;

    printf("%.2lf\n",total_price);
    printf("%d\n", chairsNeeded);
    printf("%d\n", tablesNeeded);
    printf("%d\n", glass_setsNeeded);
    printf("%d\n", plate_setsNeeded);
    
}