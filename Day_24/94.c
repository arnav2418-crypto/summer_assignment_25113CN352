#include <stdio.h>
#include <string.h>

void compressString(char str[]) {
    int n = strlen(str);
    if (n == 0) return;

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
    printf("\n");
}
int main() {
    char str[] = "aaabbccccdd";
    printf("Original: %s\n", str);
    printf("Compressed: ");
    compressString(str);
    return 0;
}
