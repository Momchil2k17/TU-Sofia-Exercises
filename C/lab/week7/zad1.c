#include<stdio.h>   
#include<stdlib.h>
#include<string.h>

void printMenu(){
    printf("-------------Sofia Aiport-------------\n");
    printf("----------Choose an option:----------\n");
    printf("1.Enter list of flights\n");
    printf("2.Change flight status to Active\n");
    printf("3.Change flight status to Finished\n");
    printf("4.Add flight\n");
    printf("5.Delete flight\n");
    printf("6.Edit flight\n");
    printf("7.Flights for today\n");
    printf("8.Add Passenger\n");
    printf("9.Add Passenger to flight\n");
    printf("10.Change Passenger status\n");
    printf("11.Print Flight info and Passengers\n");
    printf("0.Exit\n");
    printf("---------Made by Momchil Yankov---------\n");
    printf("---------Version 1.0---------\n");

    printf("Option: \n");
}

void addFlightList(char **ListOfFlights, int *StatusOfFlights, int *numOfFlights, int *capacityOfFlights){
    for (int i = 0; i < *numOfFlights; i++){
        printf("Flight %d: %s\n", i + 1, ListOfFlights[i]);
    }
    
    int newNumFlights;
    printf("Enter number of flights: ");
    scanf("%d", &newNumFlights);
    
    if (newNumFlights > *capacityOfFlights) {
        printf("Error: Requested number of flights exceeds capacity\n");
        return;
    }
    
    for (int i = 0; i < *numOfFlights; i++) {
        if (ListOfFlights[i] != NULL) {
            free(ListOfFlights[i]);
        }
    }
    
    *numOfFlights = newNumFlights;
    for (int i = 0; i < *numOfFlights; i++){
        ListOfFlights[i] = (char*)malloc(11 * sizeof(char));
        if (ListOfFlights[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        
        printf("Enter flight name: ");
        scanf("%s", ListOfFlights[i]);
        StatusOfFlights[i] = -1;
    }
}

void addFlight(char **ListOfFlights, int *StatusOfFlights, int *numOfFlights, int *capacityOfFlights){
    if (*numOfFlights >= *capacityOfFlights) {
        *capacityOfFlights += 10;
        
        ListOfFlights = (char**)realloc(ListOfFlights, sizeof(char*) * (*capacityOfFlights));
        if (ListOfFlights == NULL) {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        
        StatusOfFlights = (int*)realloc(StatusOfFlights, sizeof(int) * (*capacityOfFlights));
        if (StatusOfFlights == NULL) {
            printf("Memory allocation failed\n");
            exit(-1);
        }
    }
    
    ListOfFlights[*numOfFlights] = (char*)malloc(11 * sizeof(char));
    if (ListOfFlights[*numOfFlights] == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    
    printf("Enter flight name: ");
    scanf("%s", ListOfFlights[*numOfFlights]);
    StatusOfFlights[*numOfFlights] = -1;
    (*numOfFlights)++;
}

void changeStatusToActive(char **ListOfFlights, int *StatusOfFlights, int numOfFlights){
    char flightName[11];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    for (int i = 0; i < numOfFlights; i++){
        if (strcmp(ListOfFlights[i], flightName) == 0){
            StatusOfFlights[i] = 1;
            printf("Flight %s status changed to Active\n", flightName);
            return;
        }
    }
    printf("Flight %s not found\n", flightName);
}

void changeStatusToFinished(char **ListOfFlights, int *StatusOfFlights, int numOfFlights){
    char flightName[11];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    for (int i = 0; i < numOfFlights; i++){
        if (strcmp(ListOfFlights[i], flightName) == 0){
            StatusOfFlights[i] = 0;
            printf("Flight %s status changed to Finished\n", flightName);
            return;
        }
    }
    printf("Flight %s not found\n", flightName);
}

void deleteFlight(char **ListOfFlights, int *StatusOfFlights, int *numOfFlights){
    char flightName[11];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    
    for (int i = 0; i < *numOfFlights; i++){
        if (strcmp(ListOfFlights[i], flightName) == 0){
            free(ListOfFlights[i]);
            
            for (int j = i; j < *numOfFlights - 1; j++){
                ListOfFlights[j] = ListOfFlights[j + 1];
                StatusOfFlights[j] = StatusOfFlights[j + 1];
            }
            
            ListOfFlights[*numOfFlights - 1] = NULL;
            StatusOfFlights[*numOfFlights - 1] = -1;
            
            (*numOfFlights)--;
            
            printf("Flight %s deleted\n", flightName);
            return;
        }
    }
    printf("Flight %s not found\n", flightName);
}

void editFlight(char **ListOfFlights, int *StatusOfFlights, int numOfFlights){
    char flightName[11];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    for (int i = 0; i < numOfFlights; i++){
        if (strcmp(ListOfFlights[i], flightName) == 0){
            printf("Enter new flight name: ");
            scanf("%s", ListOfFlights[i]);
            printf("Flight %s edited\n", flightName);
            return;
        }
    }
    printf("Flight %s not found\n", flightName);
}

void printFlightsForToday(char **ListOfFlights, int *StatusOfFlights, int numOfFlights){
    printf("Flights for today:\n");
    for (int i = 0; i < numOfFlights; i++){
            printf("N:%s Status:%d \n", ListOfFlights[i], StatusOfFlights[i]);
    }
}

void addPassenger(char **ListOfPassangers, int *StatusOfPassangers, int *numOfPassangers, int *capacityOfPassangers){
    if (*numOfPassangers >= *capacityOfPassangers) {
        *capacityOfPassangers += 10;
        
        ListOfPassangers = (char**)realloc(ListOfPassangers, sizeof(char*) * (*capacityOfPassangers));
        if (ListOfPassangers == NULL) {
            printf("Memory allocation failed\n");
            exit(-1);
        }
        
        StatusOfPassangers = (int*)realloc(StatusOfPassangers, sizeof(int) * (*capacityOfPassangers));
        if (StatusOfPassangers == NULL) {
            printf("Memory allocation failed\n");
            exit(-1);
        }
    }
    
    ListOfPassangers[*numOfPassangers] = (char*)malloc(51 * sizeof(char));
    if (ListOfPassangers[*numOfPassangers] == NULL) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    
    printf("Enter passenger name: ");
    scanf("%s", ListOfPassangers[*numOfPassangers]);
    StatusOfPassangers[*numOfPassangers] = -1;
    (*numOfPassangers)++;
}

void addPassengerToFlight(char **ListOfFlights, int *StatusOfFlights, char **ListOfPassangers, int *StatusOfPassangers, int numOfFlights, int numOfPassangers){
    char flightName[11];
    char passengerName[51];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    printf("Enter passenger name: ");
    scanf("%s", passengerName);
    
    int flightFound = 0;
    int passengerFound = 0;
    int flightIndex = -1;
    int passengerIndex = -1;
    
    for (int i = 0; i < numOfFlights; i++){
        if (ListOfFlights[i] != NULL && strcmp(ListOfFlights[i], flightName) == 0){
            flightFound = 1;
            flightIndex = i;
            break;
        }
    }
    
    for (int j = 0; j < numOfPassangers; j++){
        if (ListOfPassangers[j] != NULL && strcmp(ListOfPassangers[j], passengerName) == 0){
            passengerFound = 1;
            passengerIndex = j;
            break;
        }
    }
    
    if (flightFound && passengerFound) {
        StatusOfFlights[flightIndex] = 1;
        StatusOfPassangers[passengerIndex] = 100 + flightIndex;
        printf("Passenger %s added to flight %s\n", passengerName, flightName);
    } else {
        printf("Flight %s or Passenger %s not found\n", flightName, passengerName);
    }
}

void changePassengerStatus(char **ListOfPassangers, int *StatusOfPassangers, int numOfPassangers){
    char passengerName[51];
    printf("Enter passenger name: ");
    scanf("%s", passengerName);
    for (int i = 0; i < numOfPassangers; i++){
        if (strcmp(ListOfPassangers[i], passengerName) == 0){
            if (StatusOfPassangers[i] >= 100) {
                int flightIndex = StatusOfPassangers[i] - 100;
                StatusOfPassangers[i] = 1 + flightIndex;
                printf("Passenger %s status changed to On Board\n", passengerName);
            } else {
                printf("Passenger %s is not assigned to any flight\n", passengerName);
            }
            return;
        }
    }
    printf("Passenger %s not found\n", passengerName);
}

void printFlightInfoAndPassengers(char **ListOfFlights, int *StatusOfFlights, char **ListOfPassangers, int *StatusOfPassangers, int numOfFlights, int numOfPassangers){
    char flightName[11];
    printf("Enter flight name: ");
    scanf("%s", flightName);
    
    int flightFound = 0;
    int flightIndex = -1;
    
    for (int i = 0; i < numOfFlights; i++){
        if (strcmp(ListOfFlights[i], flightName) == 0){
            flightFound = 1;
            flightIndex = i;
            break;
        }
    }
    
    if (flightFound) {
        printf("Flight %s Status: %d\n", ListOfFlights[flightIndex], StatusOfFlights[flightIndex]);
        printf("Passengers:\n");
        
        int passengerCount = 0;
        for (int j = 0; j < numOfPassangers; j++){
            if (StatusOfPassangers[j] == 100 + flightIndex){
                printf("%s\n", ListOfPassangers[j]);
                passengerCount++;
            }
        }
        
        if (passengerCount == 0) {
            printf("No passengers on this flight.\n");
        }
    } else {
        printf("Flight %s not found\n", flightName);
    }
}

int main(){
    char **ListOfFlights, **ListOfPassangers;
    int *StatusOfFlights, *StatusOfPassangers;
    int capacityOfFlights = 25;
    int capacityOfPassangers = 150;
    int numOfFlights = 0;
    int numOfPassangers = 0;
    
    ListOfFlights = (char**)malloc(sizeof(char*) * capacityOfFlights);
    if (ListOfFlights == NULL) {
        exit(-1);
    }
    
    ListOfPassangers = (char**)malloc(sizeof(char*) * capacityOfPassangers);
    if (ListOfPassangers == NULL) {
        exit(-1);
    }

    StatusOfFlights = (int*)malloc(sizeof(int) * capacityOfFlights);
    if (StatusOfFlights == NULL) {
        exit(-1);
    }
    
    StatusOfPassangers = (int*)malloc(sizeof(int) * capacityOfPassangers);
    if (StatusOfPassangers == NULL) {
        exit(-1);
    }
    
    printMenu();
    int option;
    scanf("%d", &option);
    
    while (option != 0){
        switch (option){
            case 1:
                addFlightList(ListOfFlights, StatusOfFlights, &numOfFlights, &capacityOfFlights);
                break;
            case 2:
                changeStatusToActive(ListOfFlights, StatusOfFlights, numOfFlights);
                break;
            case 3:
                changeStatusToFinished(ListOfFlights, StatusOfFlights, numOfFlights);
                break;
            case 4:
                addFlight(ListOfFlights, StatusOfFlights, &numOfFlights, &capacityOfFlights);
                break;
            case 5:
                deleteFlight(ListOfFlights, StatusOfFlights, &numOfFlights);
                break;
            case 6:
                editFlight(ListOfFlights, StatusOfFlights, numOfFlights);
                break;
            case 7:
                printFlightsForToday(ListOfFlights, StatusOfFlights, numOfFlights);
                break;
            case 8:
                addPassenger(ListOfPassangers, StatusOfPassangers, &numOfPassangers, &capacityOfPassangers);
                break;
            case 9:
                addPassengerToFlight(ListOfFlights, StatusOfFlights, ListOfPassangers, StatusOfPassangers, numOfFlights, numOfPassangers);
                break;
            case 10:
                changePassengerStatus(ListOfPassangers, StatusOfPassangers, numOfPassangers);
                break;
            case 11:
                printFlightInfoAndPassengers(ListOfFlights, StatusOfFlights, ListOfPassangers, StatusOfPassangers, numOfFlights, numOfPassangers);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        // printMenu();
        printf("Option: \n");
        scanf("%d", &option);
    }
    
    for (int i = 0; i < numOfFlights; i++){
        if (ListOfFlights[i] != NULL) {
            free(ListOfFlights[i]);
        }
    }
    
    for (int i = 0; i < numOfPassangers; i++){
        if (ListOfPassangers[i] != NULL) {
            free(ListOfPassangers[i]);
        }
    }
    
    free(ListOfFlights);
    free(StatusOfFlights);
    free(ListOfPassangers);
    free(StatusOfPassangers);
   
    printf("Exiting program...\n");
    return 0;
}