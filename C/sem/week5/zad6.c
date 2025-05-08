#include <stdio.h>
#include <string.h>
#include <ctype.h>

int areAnagrams(const char* str1, const char* str2) {
    int counts[256] = {0};
    int i;
    
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }
    
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    
    for (i = 0; str1[i] != '\0'; i++) {
        counts[tolower(str1[i])]++;
    }
    
    for (i = 0; str2[i] != '\0'; i++) {
        if (counts[tolower(str2[i])] == 0) {
            return 0;
        }
        counts[tolower(str2[i])]--;
    }
    
    return 1;
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    if (areAnagrams(str1, str2)) {
        printf("Strings \"%s\" and \"%s\" are anagrams.\n", str1, str2);
    } else {
        printf("Strings \"%s\" and \"%s\" are NOT anagrams.\n", str1, str2);
    }
    
    return 0;
}