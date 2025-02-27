#include<stdio.h>

int main(){
    // char symbol;
    // scanf("%c",&symbol);
    // printf("    %c\n",symbol);
    // printf("   %c %c\n",symbol,symbol);
    // printf("  %c   %c\n",symbol,symbol);
    // printf(" %c     %c\n",symbol,symbol);
    // printf("%c%c%c%c%c%c%c%c%c",symbol,symbol,symbol,symbol,symbol,symbol,symbol,symbol,symbol);
   char symbol;
   scanf("%c",&symbol);
   int rows;
   scanf("%d",&rows);
   for (size_t i = 0; i < rows; i++)
   {
       if(i==0){
         for (size_t j = 0; j < rows-1; j++)
         {  
            printf(" ");

         }
         printf("%c",symbol);
       }
       else if(i<rows-1){
            for (size_t k = rows; k > rows/2+i-1; k--)
            {  
               printf(" ");
   
            }
            printf("%c",symbol);
            for (size_t j = 0; j < i*2-1; j++)
            {  
               printf(" ");
   
            }
            printf("%c",symbol);
       }
       else{
        for (size_t k = 0; k < rows*2-1; k++)
        {
           printf("%c",symbol);
        }
       }
    //    for (size_t k = rows; k > rows/2+i-1; k--)
    //    {
    //        printf(" ");
    //    }
       
    //    for (size_t j = 0; j < i*2+1; j++)
    //    {
    //        printf("%c","$");
    //    }
       printf("\n");
   }
    
}
