#include <stdio.h>
#include <string.h>

int main() {
    char students[32][128];
    int count;
    
    scanf("%d", &count);
    getchar();
    
    for (int i = 0; i < count; i++) {
        fgets(students[i], 128, stdin);
        students[i][strcspn(students[i], "\n")] = 0; 
    }
    
    char query[128];
    fgets(query, 128, stdin);
    query[strcspn(query, "\n")] = 0;
    
    for (int i = 0; i < count; i++) {
        if (strstr(students[i], query)) {
            printf("%s\n", students[i]);
        }
    }
    
    return 0;
}