#include <stdio.h>
int isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int count = 0;
    int sum = 0;
    while (temp != 0) {
        temp /= 10;
        count++;
    }
    temp = originalNum;
    while (temp != 0) {
        int remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < count; i++) {
            power *= remainder;
        }
        
        sum += power;
        temp /= 10;
    }
    if (sum == originalNum) {
        return 1; 
    } else {
        return 0;
    }
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isArmstrong(number) == 1) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
