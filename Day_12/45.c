#include <stdio.h>
int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    int remainder;
    while (num > 0) {
        remainder = num % 10;
        reversedNum = (reversedNum * 10) + remainder;
        num = num / 10;
    }
    if (originalNum == reversedNum) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}
