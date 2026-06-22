#include <stdio.h>

int main() {
    char str[200];
    int i = 0, words = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]s", str); 
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            if (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\n' && str[i + 1] != '\0') {
                words++;
            }
        }
        i++;
    }
    if (i > 0 && str[0] != ' ' && str[0] != '\t') {
        words++;
    }

    printf("Total number of words = %d\n", words);

    return 0;
}
