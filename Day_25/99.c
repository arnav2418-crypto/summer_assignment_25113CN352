#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int count, i, j;
    printf("Enter the number of names: ");
    if (scanf("%d", &count) != 1 || count <= 0 || count > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }
    while (getchar() != '\n');
    printf("Enter %d names (one per line):\n", count);
    for (i = 0; i < count; i++) {
        fgets(names[i], MAX_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names using strcpy
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
