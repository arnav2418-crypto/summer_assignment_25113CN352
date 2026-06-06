#include <stdio.h>

int main() {
    long long binary;
    long long tempBinary;
    int decimal = 0;
    int base = 1;
    int rem;
    printf("Enter a binary number (composed of 0s and 1s): ");
    if (scanf("%lld", &binary) != 1) {
        printf("Invalid input. Please enter numbers only.\n");
        return 1;
    }

    tempBinary = binary;
    while (tempBinary > 0) {
        rem = tempBinary % 10; 
        if (rem != 0 && rem != 1) {
            printf("Error: %lld is not a valid binary number.\n", binary);
            return 1;
        }

        decimal += rem * base;  
        base *= 2;             
        tempBinary /= 10;      
    }
    printf("Binary: %lld\n", binary);
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
