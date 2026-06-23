#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char str[MAX_SIZE];
    int freq[256] = {0}; 
    int max_count = 0;
    char max_char;

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin); 
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            continue;
        }
        int ascii_val = (unsigned char)str[i]; 
        freq[ascii_val]++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        int ascii_val = (unsigned char)str[i];
        
        if (freq[ascii_val] > max_count) {
            max_count = freq[ascii_val];
            max_char = str[i];
        }
    }
    if (max_count > 0) {
        printf("The maximum occurring character is '%c' (appears %d times).\n", max_char, max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
