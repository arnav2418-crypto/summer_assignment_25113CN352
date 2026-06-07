// program to find reverse factorial 
 
#include <stdio.h>
int findFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * findFactorial(n - 1);
}

int main() {
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of a negative number does not exist.\n");
    } else {
        printf("Factorial of %d is %d\n", num, findFactorial(num));
    }
    return 0;
}
