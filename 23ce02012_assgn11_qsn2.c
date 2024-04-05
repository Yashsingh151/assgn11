#include <stdio.h>
#include <string.h>

char *removeDuplicates(char *s) {
    int len = strlen(s);
    char *result = s; 
    int top = -1; 

    for (int i = 0; i < len; i++) {
        if (top >= 0 && result[top] == s[i]) {
            top--; 
        } else {
            result[++top] = s[i];
        }
    }
    result[top + 1] = '\0';
    return result; 
}

int main() {
    char s[] = "abbaca";
    printf("Original string: %s\n", s);
    char *result = removeDuplicates(s);
    printf("String after duplicate removal: %s\n", result);
    return 0;
}