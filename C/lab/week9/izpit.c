#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct IceCream{
    char Id[3];
    char Name[21];
    int weight;
    float price;
}typedef IceCream;


float ReportPrice(IceCream* iceCreams, int n, char letter){
    float totalPrice = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (iceCreams[i].Name[0] == letter)
        {
            totalPrice += iceCreams[i].price*iceCreams[i].weight;
        }
    }
    return totalPrice;
}

int WriteFile(IceCream* IceCreams,int n,float price,int weight){
    int count=0;
    FILE* file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (size_t i = 0; i < n; i++)
    {
        if (IceCreams[i].weight > weight && IceCreams[i].price < price)
        {
            fprintf(file, "%s;%s;%d;%.2fleva\n", IceCreams[i].Id, IceCreams[i].Name, IceCreams[i].weight, IceCreams[i].price);
            count++;
        }
    }
    fclose(file);
    return count;
}

int readFromFile(char* UC){
    FILE* file = fopen("icecream.bin", "br");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char ID[3],Name[21];
    int weight,lenName,res;
    float price;
    while (!feof(file))
    {
        res=fread(ID,sizeof(char)*3,1,file);
        if (res!=1)
        {
            exit(-1);
        }
        res=fread(lenName,sizeof(int),1,file);
        if (res!=1)
        {
            exit(-1);
        }
        res=fread(Name,sizeof(char)*21,1,file);
        if (res!=1)
        {
            exit(-1);
        }
        res=fread(&weight,sizeof(int),1,file);
        if (res!=1)
        {
            exit(-1);
        }
        res=fread(&price,sizeof(float),1,file);
        if (res!=1)
        {
            exit(-1);
        }
        if (strcmp(UC,ID)==0)
        {
            printf("=============\n");
            printf("Ice cream - %s\n", Name);
            printf("Price - %.2f\n", price);
            printf("=============\n");
            return 1;
        }
    }
    fclose(file);
    printf("Ice cream with ID %s not found.\n", UC);
    return 0;
    
}

int main(){
    int n;
    while (1) {
        printf("Enter the number of ice creams: ");
        scanf("%d", &n);
        if (n > 5 && n < 15) {
            break; 
        } else {
            printf("Invalid number of ice creams. Please enter a number between 6 and 14.\n");
        }
    }
    IceCream* iceCreams = (IceCream*)malloc(n * sizeof(IceCream));
    if (iceCreams == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("Enter ice cream %d ID: ", i + 1);
        scanf("%s", iceCreams[i].Id);
        printf("Enter ice cream %d Name: ", i + 1);
        scanf("%s", iceCreams[i].Name);
        printf("Enter ice cream %d weight: ", i + 1);
        scanf("%d", &iceCreams[i].weight);
        printf("Enter ice cream %d price: ", i + 1);
        scanf("%f", &iceCreams[i].price);
    }
    printf("Ice Creams:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("ID: %s, Name: %s, Weight: %d, Price: %.2f\n", iceCreams[i].Id, iceCreams[i].Name, iceCreams[i].weight, iceCreams[i].price);
    }
    
}