#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char longest_word[100] = "";
    char current_word[100] = "";
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 
    for (i = 0; i <= strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            current_word[j++] = str[i];
        } 
        else {
            current_word[j] = '\0'; 
            if (strlen(current_word) > strlen(longest_word)) {
                strcpy(longest_word, current_word);
            }
            
            j = 0; 
        }
    }

    printf("The longest word is: %s\n", longest_word);
    printf("Length of the longest word: %lu\n", strlen(longest_word));

    return 0;
}
