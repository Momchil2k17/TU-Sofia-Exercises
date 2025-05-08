#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[31];
    char Date[8];
    long long Code;
    float Price;
    int Quantity;
} Medicine;

typedef struct {
    int month;
    int year;
} Date;

Date parse_date(const char *dateStr) {
    Date d;
    sscanf(dateStr, "%d.%d", &d.month, &d.year);
    return d;
}
int compare_dates(Date a, Date b) {
    if (a.year != b.year)
        return (a.year < b.year) ? -1 : 1;
    if (a.month != b.month)
        return (a.month < b.month) ? -1 : 1;
    return 0;
}

//tova ne e za izpita
void createBinaryFileWithMedicine(){
    FILE* file = fopen("medicine.bin", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file medicine.bin\n");
        return;
    }
    Medicine medicine = {"Paracetamol", "11.2026", 1234567890123, 5.99, 100};
    Medicine medicine2 = {"Ibuprofen", "12.2025", 9876543210987, 7.49, 50};
    Medicine medicine3 = {"Aspirin", "09.2024", 4567891234567, 3.99, 200};
    Medicine medicine4 = {"Amoxicillin", "09.2023", 7891234567890, 9.99, 30};
    fwrite(&medicine, sizeof(Medicine), 1, file);
    fwrite(&medicine2, sizeof(Medicine), 1, file);
    fwrite(&medicine3, sizeof(Medicine), 1, file);
    fwrite(&medicine4, sizeof(Medicine), 1, file);
    fclose(file);
}

Medicine* readAndStoreData(Medicine* medicines, int* count) {
    FILE* file = fopen("medicine.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file medicine.bin\n");
        return NULL;
    }
    Medicine temp;
    while (fread(&temp, sizeof(Medicine), 1, file) == 1) {
        medicines = realloc(medicines, (*count + 1) * sizeof(Medicine));
        if (medicines == NULL) {
            printf("Error: Memory reallocation failed\n");
            fclose(file);
            return NULL;
        }
        medicines[*count] = temp;
        (*count)++;
    }
    fclose(file);
    return medicines;
}

Medicine* findBeforeExpiryDate(Medicine* medicines, int count, char date[8]) {
    if (medicines == NULL) {
        printf("Error: Empty Array was passes to function\n");
        return NULL;    
    }
    if (count < 1) {
        printf("Error: %d is wrong value for medicineArraySize\n", count);
        return NULL;
    }
    if (strlen(date) != 7) {
        printf("Error: Date is out of range (dd.yyyy)\n");
        return NULL;
    }
    Medicine* result = NULL;
    int resultCount = 0;
    for (int i = 0; i < count; i++) {
        if (compare_dates(parse_date(medicines[i].Date), parse_date(date)) < 0) {
            result = realloc(result, (resultCount + 1) * sizeof(Medicine));
            result[resultCount] = medicines[i];
            resultCount++;
        }
    }
    return result;
}

int writeToFile(Medicine* medicines, int count,float minPrice,float maxPrice) {
    FILE* file = fopen("offer.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file offer.txt\n");
        return 0;
    }
    int res = 0;
    int writtenCount = 0;
    for (size_t i = 0; i < count; i++)
    {
        if(medicines[i].Price >= minPrice && medicines[i].Price <= maxPrice) {
            res = fprintf(file, "%s\n%s\n%lld\n%.2fleva\n\n",
                medicines[i].Name,
                medicines[i].Date,
                medicines[i].Code,
                medicines[i].Price);
            
            if (res < 0) {
                printf("Error: Unable to write to file offer.txt\n");
                fclose(file);
                return -1;
            }
            writtenCount++;
        }
    }
    fclose(file);
    return writtenCount;
}

Medicine* deleteMedicineByNameAndDate(Medicine* medicines, int* count, char* name, char* date) {
    int found=0;
    if (medicines == NULL) {
        printf("Error: Empty Array was passed to function\n");
        return NULL;    
    }
    if (*count < 1) {
        printf("Error: %d is wrong value for medicineArraySize\n", count);
        return NULL;    
    }
    if (strlen(date) != 7) {
        printf("Error: Date is out of range (dd.yyyy)\n");
        return NULL;
    }
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].Name, name) == 0 && compare_dates(parse_date(medicines[i].Date), parse_date(date)) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            
            (*count)--;
            found = 1;
            Medicine* temp = realloc(medicines, (*count) * sizeof(Medicine));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed\n");
                return medicines;
            }
            medicines = temp;
            break;
        }
    }
    if (found) {
        printf("Medicine %s with expiry date %s deleted successfully.\n", name, date);
    } else {
        printf("Medicine %s with expiry date %s not found.\n", name, date);
    }
    return medicines;
}
int main(){
    //suzdavame si binaren fail s lekarstva
    createBinaryFileWithMedicine();
    Medicine* medicines = NULL;
    int count = 0;
    medicines = readAndStoreData(medicines, &count);
    if (medicines == NULL) {
        printf("Error: Unable to read data from file\n");
        return 1;
    }
    //printirame da vidim dali sa se zapisali
    // for (int i = 0; i<count; i++) {
    //     printf("Medicine Name: %s\n", medicines[i].Name);
    //     printf("Expiry Date: %s\n", medicines[i].Date);
    //     printf("Code: %lld\n", medicines[i].Code);
    //     printf("Price: %.2f\n", medicines[i].Price);
    //     printf("Quantity: %d\n", medicines[i].Quantity);
    //     printf("-------------------------\n");
    // }

    //2
    char date[]="10.2024";
    Medicine* result = findBeforeExpiryDate(medicines, count, date);
    if (result == NULL) {
        printf("Error: Unable to find medicines before expiry date\n");
        free(medicines);
        return 1;
    }

    //za proverka prebroi ruchno kolko sa predi expiry date, inache trqq promenqm metoda
    // printf("Medicines before expiry date %s:\n", date);
    // for (int i = 0; i < 2; i++) {
    //     printf("Medicine Name: %s\n", result[i].Name);
    //     printf("Expiry Date: %s\n", result[i].Date);
    //     printf("Code: %lld\n", result[i].Code);
    //     printf("Price: %.2f\n", result[i].Price);
    //     printf("Quantity: %d\n", result[i].Quantity);
    //     printf("-------------------------\n");
    // }


    //3
    float minPrice = 3.99;
    float maxPrice = 8.00;
    int writtenCount = writeToFile(medicines, 4, minPrice, maxPrice);
    printf("%d records added to offer.txt\n", writtenCount);
    

    //4
    char name[]="Paracetamol";
    char date1[]="11.2026";
    deleteMedicineByNameAndDate(medicines, &count, name, date1);
    char name2[]="Ibuprofen";
    char date2[]="11.2025";
    deleteMedicineByNameAndDate(medicines, &count, name2, date2);

    //проwерка след изтриване
    for (int i = 0; i<count; i++) {
            printf("Medicine Name: %s\n", medicines[i].Name);
            printf("Expiry Date: %s\n", medicines[i].Date);
            printf("Code: %lld\n", medicines[i].Code);
            printf("Price: %.2f\n", medicines[i].Price);
            printf("Quantity: %d\n", medicines[i].Quantity);
            printf("-------------------------\n");
        }
}