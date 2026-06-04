#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1, nextTerm;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    return b;
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        printf("The %dth term is: %d\n", n, fibonacci(n));
    }
    return 0;
}