#include <stdio.h>
unsigned long long findFactorial(int n) {
    unsigned long long fact = 1; 
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error! Factorial of a negative number does not exist.\n");
    } else {
        unsigned long long result = findFactorial(num);
        printf("Factorial of %d = %llu\n", num, result);
    }

    return 0;
}
