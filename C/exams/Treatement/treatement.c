#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char date[11];
    char patient[31];
    char diagnose[51];
} Treatement;

Treatement* readFromBinaryFile(Treatement*, int*);
int count_treatement(Treatement*, int, char*, char*);
Treatement* add_new_treatement(Treatement*, int*);
int writeToFile(Treatement*, int, char*);
void createBinaryFileWithTreatement();
int main(){
    //suzdavame si binaren fail s lekarstva
    createBinaryFileWithTreatement();
    int n=0;
    Treatement* history = NULL;
    history = readFromBinaryFile(history, &n);
    if (history == NULL) {
        printf("Error: Unable to read data from file\n");
        return -1;
    }
    //printirame da vidim dali sa se zapisali
    for (int i = 0; i < n; i++) {
        printf("Treatement #%d:\n", i + 1);
        printf("ID: %d\n", history[i].id);
        printf("Date: %s\n", history[i].date);
        printf("Patient: %s\n", history[i].patient);
        printf("Diagnose: %s\n", history[i].diagnose);
    }

    int treatementCount = count_treatement(history, n, "John Doe", "Flu");
    printf("Number of treatments for John Doe with diagnose Flu: %d\n", treatementCount);

    history = add_new_treatement(history, &n);
    if (history == NULL) {
        printf("Error: Unable to add new treatment\n");
        return -1;
    }
    printf("New treatment added successfully.\n");
    for (int i = 0; i < n; i++) {
        printf("Treatement #%d:\n", i + 1);
        printf("ID: %d\n", history[i].id);
        printf("Date: %s\n", history[i].date);
        printf("Patient: %s\n", history[i].patient);
        printf("Diagnose: %s\n", history[i].diagnose);
    }

    int writtenCount = writeToFile(history, n, "Flu");
    printf("%d records added to treatement.txt\n", writtenCount);
}

Treatement* readFromBinaryFile(Treatement* history, int* count) {
    FILE* file = fopen("treatement.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file treatement.bin\n");
        return NULL;
    }
    Treatement temp;
    if(fread(count, sizeof(int), 1, file) != 1) {
        printf("Error: Unable to read count from file\n");
        fclose(file);
        return NULL;
    }

    Treatement* tempHistory = realloc(history, (*count) * sizeof(Treatement));
    if (tempHistory == NULL) {
        printf("Error: Memory reallocation failed\n");
        fclose(file);
        return NULL;
    }
    history = tempHistory;
    for (int i = 0; i < *count; i++) {
        if (fread(&temp, sizeof(Treatement), 1, file) != 1) {
            printf("Error: Unable to read treatement data from file\n");
            free(history);
            fclose(file);
            return NULL;
        }
        history[i] = temp;
    }
    fclose(file);
    return history;
}
int count_treatement(Treatement* history, int count, char* name, char* diagnose) {
    int resultCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(history[i].patient, name) == 0 && strcmp(history[i].diagnose, diagnose) == 0) {
            resultCount++;
        }
    }
    return resultCount;
}
Treatement* add_new_treatement(Treatement* history, int* count) {
    Treatement newTreatement;
    printf("Enter new treatment details:\n");
    printf("ID: ");
    scanf("%d", &newTreatement.id);
    while (getchar() != '\n'); // Clear the input buffer
    printf("Date (YYYY.MM.DD): ");
    fgets(newTreatement.date, sizeof(newTreatement.date), stdin);
    if(newTreatement.date[strlen(newTreatement.date) - 1] == '\n') {
        printf("problem\n");
        newTreatement.date[strlen(newTreatement.date) - 1] = '\0'; // Remove newline character
    }else{
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    printf("Patient: ");
    fgets(newTreatement.patient, sizeof(newTreatement.patient), stdin);
    if(newTreatement.patient[strlen(newTreatement.patient) - 1] == '\n') {
        newTreatement.patient[strlen(newTreatement.patient) - 1] = '\0'; // Remove newline character
    }else{
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    printf("Diagnose: ");
    fgets(newTreatement.diagnose, sizeof(newTreatement.diagnose), stdin);
    if(newTreatement.diagnose[strlen(newTreatement.diagnose) - 1] == '\n') {
        newTreatement.diagnose[strlen(newTreatement.diagnose) - 1] = '\0'; // Remove newline character
    }else{
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    Treatement* tempHistory = realloc(history, (*count + 1) * sizeof(Treatement));
    if (tempHistory == NULL) {
        printf("Error: Memory reallocation failed\n");
        return NULL;
    }
    history = tempHistory;
    history[*count] = newTreatement;
    (*count)++;
    return history;
}
int writeToFile(Treatement* history, int count, char* diagnose) {
    FILE* file = fopen("treatement.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file treatement.txt\n");
        return -1;
    }
    int res = 0,writeCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(history[i].diagnose, diagnose) == 0) {
            res = fprintf(file, "%d-%s-%s-%s\n", history[i].id, history[i].date, history[i].patient, history[i].diagnose);
            if (res < 0) {
                printf("Error writing to file\n");
                fclose(file);
                return -2;
            }
            writeCount++;
        }
    }

    fclose(file);
    return writeCount;
}
void createBinaryFileWithTreatement() {
    FILE* file = fopen("treatement.bin", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file treatement.bin\n");
        return;
    }
    Treatement treatement1 = {1, "2023.10.01", "John Doe", "Flu"};
    Treatement treatement11 = {11, "2023.11.01", "John Doe", "Flu"};
    Treatement treatement2 = {2, "2023.11.01", "Jane Smith", "Cold"};
    Treatement treatement3 = {3, "2023.12.01", "Alice Johnson", "Headache"};
    Treatement treatement4 = {4, "2024.01.01", "Bob Brown", "Fever"};
    Treatement treatement41 = {41, "2024.01.01", "Bob Brown", "Flu"};
    int count = 6;
    fwrite(&count, sizeof(int), 1, file);
    fwrite(&treatement1, sizeof(Treatement), 1, file);
    fwrite(&treatement2, sizeof(Treatement), 1, file);
    fwrite(&treatement3, sizeof(Treatement), 1, file);
    fwrite(&treatement4, sizeof(Treatement), 1, file);
    fwrite(&treatement11, sizeof(Treatement), 1, file);
    fwrite(&treatement41, sizeof(Treatement), 1, file);
    fclose(file);
}