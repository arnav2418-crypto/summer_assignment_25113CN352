#include <stdio.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_LENGTH 100

int main() {
    char words[MAX_WORDS][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int n, i, j;
    printf("Enter the number of words (up to %d): ", MAX_WORDS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }
    printf("Enter %d words:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
    printf("\nWords sorted by length:\n");
    for (i = 0; i < n; i++) {
        printf("%s (Length: %lu)\n", words[i], (unsigned long)strlen(words[i]));
    }

    return 0;
}
