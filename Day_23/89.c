#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256 

int main() {
    char str[100];
    int count[MAX_CHAR] = {0}; 
    int found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]s", str); 
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
