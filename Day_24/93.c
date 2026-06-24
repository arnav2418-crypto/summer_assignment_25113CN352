#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isRotation(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }
    int len = strlen(str1);
    char* temp = (char*)malloc(2 * len + 1);

    if (temp == NULL) return false; 
    strcpy(temp, str1);
    strcat(temp, str1);
    bool result = (strstr(temp, str2) != NULL);
    free(temp);

    return result;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    if (isRotation(str1, str2)) {
        printf("Yes, %s is a rotation of %s\n", str2, str1);
    } else {
        printf("No, %s is not a rotation of %s\n", str2, str1);
    }

    return 0;
}
