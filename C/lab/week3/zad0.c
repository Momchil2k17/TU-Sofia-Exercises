#include <stdio.h>
// float areaOfCicle(float radius){
//     float result;
//     result=radius*radius*3.1415926;
//     return result;
// }
// int main(){
//     float r1,r2;
//     float area1,area2;

//     r1=6.0;
//     printf("r2: ");
//     scanf("%f",&r2);

//     area1=areaOfCicle(r1);
//     area2=areaOfCicle(r2);

//     printf("Purvata okrujnost s raius %f ima plosht: %.2f\n",r1,area1);
//     printf("Vtorata okrujnost s raius %f ima plosht: %.2f\n",r2,area2);
// }

// int max(int, int);

// void main()
// {
//  int x=4,y=5;
 
//  printf("%d",max(x,y));

// }


// int max(int num1, int num2)
//  {

//    int result;
 
//    if (num1 > num2)
//       result = num1;
//    else
//       result = num2;
 
//    return result; 
// }

int main(){
    int  var = 30;   /* декларация на реална променлива*/
    int  *ip=NULL;        /* декларация на указател */
 
    // ip = &var;  /* подаване на стойност на указателя адреса на променлива */
 
    printf("Address of var variable: %x\n", &var  );
 
    /* адреса запазен в указателя */
    printf("Address stored in ip variable: %x\n", ip );
 
    /* достъп до стойността в указателя */
    printf("Value of *ip variable: %d\n", *ip );
 
}