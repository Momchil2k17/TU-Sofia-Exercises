#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PEOPLE 1001

int friendCount[MAX_PEOPLE];
int isFriend[MAX_PEOPLE][MAX_PEOPLE]; 

int main() {
    char line[100];

    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') break; 

        int a, b;
        if (sscanf(line, "%d %d", &a, &b) == 2) {
            if (!isFriend[a][b]) {
                isFriend[a][b] = 1;
                isFriend[b][a] = 1;
                friendCount[a]++;
                friendCount[b]++;
            }
        }
    }
    printf("Friend count:\n");
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '\n') break; 
        int x;
        if (sscanf(line, "%d", &x) == 1) {
            printf("%d\n", friendCount[x]);
        }
    }

    return 0;
}
