#include <stdio.h>

int main() {
    int start, end, i, temp1, temp2, remainder, digits, sum, power;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        temp1 = i;
        digits = 0;
        while (temp1 != 0) {
            temp1 /= 10;
            digits++;
        }
        temp2 = i;
        sum = 0;
        while (temp2 != 0) {
            remainder = temp2 % 10;
            power = 1;
            for (int j = 0; j < digits; j++) {
                power *= remainder;
            }
            
            sum += power;
            temp2 /= 10;
        }
        if (sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
