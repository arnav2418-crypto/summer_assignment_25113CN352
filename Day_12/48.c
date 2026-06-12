#include <stdio.h>
int isPerfect(int num);

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (isPerfect(number)) {
        printf("%d is a Perfect Number.\n", number);
    } else {
        printf("%d is NOT a Perfect Number.\n", number);
    }

    return 0;
}
int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i; 
        }
    }
    if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}
