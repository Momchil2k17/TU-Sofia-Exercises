#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    char author[31];
    char pictureName[31];
    float price;
} Picture;

float averageOfPicturesWithHigherPrice(Picture*, int, float);
int writeTextFile(Picture*, int, char);
int searchForPictureByAuthorInBinaryFile(char*);
void createBinaryFileWithPictures();//za testvane

int main(){
    int n=0;
    Picture* pictures = NULL;
    while((n<=3) || (n>=30)){
        printf("Enter number of pictures [4-29]: ");
        scanf("%d", &n);
    }
    pictures=calloc(n, sizeof(Picture));
    if (pictures == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    while((getchar() != '\n'));
    for (int i = 0; i < n; i++){
        printf("Enter picture id: ");
        scanf("%d", &pictures[i].id);
        while((getchar() != '\n'));
        printf("Enter author name: ");
        fgets(pictures[i].author, sizeof(pictures[i].author), stdin);
        if(pictures[i].author[strlen(pictures[i].author) - 1] == '\n') {
            pictures[i].author[strlen(pictures[i].author) - 1] = '\0';
        }
        printf("Enter picture name: ");
        fgets(pictures[i].pictureName, sizeof(pictures[i].pictureName), stdin);
        if(pictures[i].pictureName[strlen(pictures[i].pictureName) - 1] == '\n') {
            pictures[i].pictureName[strlen(pictures[i].pictureName) - 1] = '\0';
        }
        printf("Enter price: ");
        scanf("%f", &pictures[i].price);
    }

    float averagePrice = averageOfPicturesWithHigherPrice(pictures, n, 200.0);
    printf("Average price of pictures with price higher than 100.0: %.2f\n", averagePrice);

    int writtenCount = writeTextFile(pictures, n, 'J');

    printf("%d records added to pictures.txt\n", writtenCount);
    createBinaryFileWithPictures();
    int found = searchForPictureByAuthorInBinaryFile("Bob Brown");
    
}

float averageOfPicturesWithHigherPrice(Picture* pictures, int n, float price) {
    float avgPrice = 0,sum=0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pictures[i].price > price) {
            sum += pictures[i].price;
            count++;
        }
    }
    if(count > 0) {
        avgPrice = sum / count;
    }
    return avgPrice;
}

int writeTextFile(Picture* pictures, int n, char letter) {
    FILE* file = fopen("pictures.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    int res = 0;
    int writtenCount = 0;
    for (int i = 0; i < n; i++) {
        if (tolower(pictures[i].author[0]) == tolower(letter)) {
            res = fprintf(file, "%d-%s-%s-%.2f\n", pictures[i].id, pictures[i].author, pictures[i].pictureName, pictures[i].price);
            if (res < 0) {
                printf("Error writing to file\n");
                fclose(file);
                return -1;
            }
            writtenCount++;
        }
    }
    fclose(file);
    return writtenCount;
}

int searchForPictureByAuthorInBinaryFile(char* author) {
    FILE* file = fopen("pictures.bin", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    char fileAuthor[31], pictureName[31];
    int id,alen,plen, found = 0;
    float price;
    while(fread(&id, sizeof(int), 1, file) == 1) {
        if(fread(&alen, sizeof(int), 1, file) != 1) {
            break;
        }
        if(fread(fileAuthor, sizeof(char), alen, file) != alen) {
            break;
        }
        fileAuthor[alen] = '\0';
        
        if(fread(&plen, sizeof(int), 1, file) != 1) {
            break;
        }
        if(fread(pictureName, sizeof(char), plen, file) != plen) {
            break;
        }
        pictureName[plen] = '\0';
        
        if(fread(&price, sizeof(float), 1, file) != 1) {
            break;
        }
        
        if(strcmp(author, fileAuthor) == 0) {
            printf("*********************\n");
            printf("Picture ID: %d\n", id);
            printf("Picture Name: %s\n", pictureName);
            printf("Price: %.2f\n", price);
            printf("*********************\n");
            found++;
        }
    }
    if (found == 0) {
        printf("No pictures found for author %s\n", author);
    }else {
        printf("Found %d pictures for author %s\n", found, author);
    }
    fclose(file);
    return found;
}
void createBinaryFileWithPictures() {
    FILE* file = fopen("pictures.bin", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    Picture pictures[] = {
        {1234, "Alice Smith", "Sunset", 150.50},
        {2345, "Bob Brown", "Mountains", 200.00},
        {2346, "Bob Brown", "Mountains2", 201.00},
        {3456, "Charlie Johnson", "Ocean View", 300.75},
        {4567, "David Wilson", "City Lights", 250.00}
    };
    int count=5;
    for (int i = 0; i < count; i++) {
        int alen = strlen(pictures[i].author);
        int plen = strlen(pictures[i].pictureName);
        fwrite(&pictures[i].id, sizeof(int), 1, file);
        fwrite(&alen, sizeof(int), 1, file);
        fwrite(pictures[i].author, sizeof(char), alen, file);
        fwrite(&plen, sizeof(int), 1, file);
        fwrite(pictures[i].pictureName, sizeof(char), plen, file);
        fwrite(&pictures[i].price, sizeof(float), 1, file);
    }
    
    fclose(file);
}