#include <stdio.h>
int findSum(int num1, int num2);

int main() {
    int a, b, total;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    total = findSum(a, b);
    printf("The sum of %d and %d is: %d\n", a, b, total);

    return 0;
}
int findSum(int num1, int num2) {
    int sum;
    sum = num1 + num2; 
    return sum;        
}
