#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[51];
    char date[11];
    int lections;
    float price;
} Course;

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date parse_date(char dateStr[11]) {
    Date d;
    sscanf(dateStr, "%d.%d.%d", &d.year, &d.month,&d.day);
    return d;
}

int compare_dates(Date a, Date b) {
    if (a.year != b.year)
        return (a.year < b.year) ? -1 : 1;
    if (a.month != b.month)
        return (a.month < b.month) ? -1 : 1;
    if (a.day != b.day)
        return (a.day < b.day) ? -1 : 1;
    return 0;
}

Course* readFromBinaryFile(Course* , int*);
int discountCourse(Course* , int, int);
int writeToFile(Course* , int, float, float);
Course* deleteCourseByNameAndDate(Course* , int*, char*, char*);

void createBinaryFileWithCourses() {
    FILE* file = fopen("courses.bin", "wb");
    if (file == NULL) {
        printf("Error: Unable to open file courses.bin\n");
        return;
    }
    Course course1 = {"Mathematics", "2023.10.01", 30, 100.0};
    Course course2 = {"Physics", "2023.11.01", 25, 150.0};
    Course course3 = {"Chemistry", "2023.12.01", 20, 200.0};
    Course course4 = {"Biology", "2024.01.01", 15, 250.0};
    int count = 4;
    fwrite(&count, sizeof(int), 1, file);
    fwrite(&course1, sizeof(Course), 1, file);
    fwrite(&course2, sizeof(Course), 1, file);
    fwrite(&course3, sizeof(Course), 1, file);
    fwrite(&course4, sizeof(Course), 1, file);
    fclose(file);
}

int main() {
    // Create binary file with courses
    createBinaryFileWithCourses();
    
    Course* courses = NULL;
    int count = 0;
    
    // Read and store data from binary file
    courses = readFromBinaryFile(courses, &count);
    if (courses == NULL) {
        printf("Error: Unable to read data from file\n");
        return 1;
    }
    
    // Print courses to check if they are stored correctly
    for (int i = 0; i < count; i++) {
        printf("Course Name: %s\n", courses[i].name);
        printf("Start Date: %s\n", courses[i].date);
        printf("Number of Lections: %d\n", courses[i].lections);
        printf("Price: %.2f\n", courses[i].price);
        printf("-------------------------\n");
    }
    
    // Discount course at index 1
    int index = 1;
    if (discountCourse(courses, count, index) == -1) {
        printf("Error: Unable to apply discount\n");
    }
    printf("Discounted course at index %d:\n", index);
    printf("Course Name: %s\n", courses[index].name);
    printf("Start Date: %s\n", courses[index].date);
    printf("Number of Lections: %d\n", courses[index].lections);
    printf("Price: %.2f\n", courses[index].price);
    
    // Write to text file
    float minPrice = 50.0;
    float maxPrice = 200.0;
    int writtenCount = writeToFile(courses, count, minPrice, maxPrice);
    printf("%d records added to courses.txt\n", writtenCount);
    
    // Delete course by name and date
    char courseName[] = "Mathematics";
    char courseDate[] = "2023.10.01";
    courses = deleteCourseByNameAndDate(courses, &count, courseName, courseDate);

     for (int i = 0; i < count; i++) {
        printf("Course Name: %s\n", courses[i].name);
        printf("Start Date: %s\n", courses[i].date);
        printf("Number of Lections: %d\n", courses[i].lections);
        printf("Price: %.2f\n", courses[i].price);
        printf("-------------------------\n");
    }
    
  
    
    // // Free allocated memory
    // free(courses);
    
    // return 0;
}

Course* readFromBinaryFile(Course* courses, int* count) {
    FILE* file = fopen("courses.bin", "rb");
    if (file == NULL) {
        printf("Error: Unable to open file courses.bin\n");
        return NULL;
    }
    if(fread(count, sizeof(int), 1, file)!= 1) {
        printf("Error: Unable to read count from file\n");
        fclose(file);
        return NULL;
    }
    Course* temp = realloc(courses, (*count) * sizeof(Course));
    if (temp == NULL) {
        printf("Error: Memory reallocation failed\n");
        fclose(file);
        return NULL;
    }
    courses = temp;
    Course tempCourse;
    for (int i = 0; i < *count; i++) {
        if (fread(&tempCourse, sizeof(Course), 1, file) != 1) {
            printf("Error: Unable to read course data from file\n");
            free(courses);
            fclose(file);
            return NULL;
        }
        courses[i] = tempCourse;
    }
    fclose(file);
    return courses;
}
int discountCourse(Course* courses, int count, int index) {
    if(index < 0 || index >= count) {
        printf("Error: Invalid index\n");
        return -1;
    }
    courses[index].price *= 0.9; 
    printf("%.2flv.-%s - %s\n", courses[index].price, courses[index].name, courses[index].date);
    return 1;
}
int writeToFile(Course* courses, int count, float minPrice, float maxPrice) {
    FILE* file = fopen("courses.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file courses.txt\n");
        return -1;
    }
    int res = 0;
    int writtenCount = 0;
    for (int i = 0; i < count; i++) {
        if (courses[i].price >= minPrice && courses[i].price <= maxPrice) {
            //kolkot da se zapishe nestho
            res = fprintf(file, "%s-%s-%d-%.2f\n", courses[i].name, courses[i].date, courses[i].lections, courses[i].price);
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
Course* deleteCourseByNameAndDate(Course* courses, int* count, char* name, char* date) {
    int found=0;
    for(int i = 0; i < *count; i++) {
        if (strcmp(courses[i].name, name) == 0 && compare_dates(parse_date(courses[i].date), parse_date(date)) == 0) {
            for (int j = i; j < *count - 1; j++) {
                courses[j] = courses[j + 1];
            }
            (*count)--;
            Course* temp = realloc(courses, (*count) * sizeof(Course));
            if (temp == NULL) {
                printf("Error: Memory reallocation failed\n");
                return courses;
            }
            courses = temp;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: Course with name '%s' and date '%s' not found\n", name, date);
    }else {
        printf("Course with name '%s' and date '%s' deleted successfully\n", name, date);
    }
    return courses;
}