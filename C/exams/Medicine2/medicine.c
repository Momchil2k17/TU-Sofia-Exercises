#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void printAllMedicines(Medicine* medicines, int count) {
    for (int i = 0; i < count; i++) {
        printf("Medicine Name: %s\n", medicines[i].Name);
        printf("Expiry Date: %s\n", medicines[i].Date);
        printf("Code: %lld\n", medicines[i].Code);
        printf("Price: %.2f\n", medicines[i].Price);
        printf("Quantity: %d\n", medicines[i].Quantity);
        printf("-------------------------\n");
    }
}
Medicine* readFromTextFileAndStoreData(Medicine* medicines, int* count) {
    FILE* file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file medicine.txt\n");
        return NULL;
    }
    char line[256];
    printf("Reading data from file...\n");
    while (fgets(line, sizeof(line), file)) {
        Medicine temp;

        // Използваме strtok() за разделяне по ";"
        char *token = strtok(line, ";");
        if (token) {
            strncpy(temp.Name, token, 31);
            temp.Name[30] = '\0';  // Уверяваме се, че името е завършено с нулев символ
        }

        token = strtok(NULL, ";");
        if (token) {
            strncpy(temp.Date, token, 8);
            temp.Date[7] = '\0';  // Уверяваме се, че датата е завършена с нулев символ
        }

        token = strtok(NULL, ";");
        if (token) {
            temp.Code = atoll(token);  // Преобразуваме в long long
        }

        token = strtok(NULL, ";");
        if (token) {
            temp.Price = atof(token);  // Преобразуваме в float
        }

        token = strtok(NULL, ";\n");
        if (token) {
            temp.Quantity = atoi(token);  // Преобразуваме в int
        }
        Medicine* tempPtr = realloc(medicines, (*count + 1) * sizeof(Medicine));

        if (tempPtr == NULL) {
            printf("Error: Memory reallocation failed\n");
            fclose(file);
            return NULL;
        }
        medicines = tempPtr;
        
        medicines[*count] = temp;
        (*count)++;
    }
    fclose(file);
    return medicines;
}
int setDiscountBeforeExpiryDate(Medicine* medicines, int count, char date[8]) {
    int discountedCount = 0;
    for (int i = 0; i < count; i++) {
        if (compare_dates(parse_date(medicines[i].Date), parse_date(date)) < 0) {
            printf("************************************************\n");
            printf("%s - %s - %.2f - %.2f\n", medicines[i].Name, medicines[i].Date,medicines[i].Price,medicines[i].Price * 0.8);
            printf("************************************************\n");
            medicines[i].Price *= 0.8;
            discountedCount++;
        }
    }
    return discountedCount;
}
void createBinaryFileWithHigherQuantity(Medicine* medicines, int count, int quantity) {
    FILE* file = fopen("medicines.bin", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file medicines.bin\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        if (medicines[i].Quantity > quantity) {
            int len = strlen(medicines[i].Name);
            //make checkings
            if(fwrite(&len, sizeof(int), 1, file)!= 1) {
                printf("Error: Unable to write length of name to file\n");
                fclose(file);
                return;
            }
            if(fwrite(medicines[i].Name, sizeof(char), len, file)!= len) {
                printf("Error: Unable to write name to file\n");
                fclose(file);
                return;
            }
            if(fwrite(medicines[i].Date, sizeof(char), 8, file)!= 8) {
                printf("Error: Unable to write date to file\n");
                fclose(file);
                return;
            }
            if(fwrite(&medicines[i].Code, sizeof(long long), 1, file)!= 1) {
                printf("Error: Unable to write code to file\n");
                fclose(file);
                return;
            }
            if(fwrite(&medicines[i].Price, sizeof(float), 1, file)!= 1) {
                printf("Error: Unable to write price to file\n");
                fclose(file);
                return;
            }
            if(fwrite(&medicines[i].Quantity, sizeof(int), 1, file)!= 1) {
                printf("Error: Unable to write quantity to file\n");
                fclose(file);
                return;
            }
            printf("Medicine %s with expiry date %s and quantity %d written to file.\n", medicines[i].Name, medicines[i].Date, medicines[i].Quantity);
        }
    }
}
Medicine* deleteByCode(Medicine* medicines, int* count, long long code) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (medicines[i].Code == code) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            found = 1;
            Medicine* temp = realloc(medicines, (*count) * sizeof(Medicine));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed\n");
                return NULL;
            }
            medicines = temp;
            break;
        }
    }
    if (found) {
        printf("Medicine with code %lld deleted successfully.\n", code);
    } else {
        printf("Medicine with code %lld not found.\n", code);
    }
    return medicines;
}
int main(){
    Medicine* medicines = NULL;
    int count = 0;
    medicines = readFromTextFileAndStoreData(medicines, &count);
    if (medicines == NULL) {
        printf("Error: Unable to read data from file\n");
        return -1;
    }
    // Print the medicines to verify
    printAllMedicines(medicines, count);

    char date[8]="10.2024";
    int discountedCount = setDiscountBeforeExpiryDate(medicines, count, date);
    if (discountedCount > 0) {
        printf("Discount applied to %d medicines before the expiry date %s.\n", discountedCount, date);
    } else {
        printf("No medicines found before the expiry date %s.\n", date);
    }
    // Print the medicines again to verify the discount
    printAllMedicines(medicines, count);


    int quantity = 101;
    createBinaryFileWithHigherQuantity(medicines, count, quantity);
    long long code = 3801234567890;
    medicines = deleteByCode(medicines, &count, code);
    if (medicines == NULL) {
        printf("Error: Unable to delete medicine with code %lld\n", code);
        return -1;
    }
    medicines = deleteByCode(medicines, &count, 3801234567891);

    
    printAllMedicines(medicines, count);


}