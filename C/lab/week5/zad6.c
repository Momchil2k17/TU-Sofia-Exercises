#include<stdio.h>
int Add(int a,int b){
    return a+b;
}
int Sub(int a,int b){
    return a-b;
}
int Pow(int a,int b){
    int result=1;
    for (int i = 0; i < b; i++)
    {
        result*=a;
    }
    return result;
}
int main(){
    int choice, a, b;
    int (*oper1)(int,int);
    
    while (1) { 
        printf("\nChooese func\n");
        printf("1.Add\n");
        printf("2.Subtracts\n");
        printf("3.Power\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exited program\n");
            break; 
        }

        printf("Two nums:");
        scanf("%d %d", &a, &b);

        if(choice==1){
            oper1 = Add;
        }
        else if(choice==2){
            oper1 = Sub;
            printf("Subtract: %d\n", oper2(a,b));
        }
        else if(choice==3){
            printf("Pow: %d\n", oper3(a,b));
        }
    }

}