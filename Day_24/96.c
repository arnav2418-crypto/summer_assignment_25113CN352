#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char words[20][20]; 
    int i = 0, j = 0, k = 0, wordCount = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            words[wordCount][j] = '\0';
            wordCount++;
            j = 0;
        } else {
            words[wordCount][j] = str[i];
            j++;
        }
    }
    words[wordCount][j] = '\0'; 
    wordCount++;
    for (i = 0; i < wordCount; i++) {
        for (k = i + 1; k < wordCount; k++) {
            if (strcmp(words[i], words[k]) == 0) {
                words[k][0] = '\0'; 
            }
        }
    }
    printf("Result: ");
    for (i = 0; i < wordCount; i++) {
        if (words[i][0] != '\0') {
            printf("%s ", words[i]);
        }
    }
    printf("\n");

    return 0;
}
