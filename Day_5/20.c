#include <stdio.h>

int main() {
    long long n;
    long long largest_factor = 0;
    printf("Enter a positive integer: ");
    scanf("%lld", &n);
    while (n % 2 == 0) {
        largest_factor = 2;
        n /= 2;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest_factor = i;
            n /= i;
        }
    }
    if (n > 2) {
        largest_factor = n;
    }
    printf("The largest prime factor is: %lld\n", largest_factor);

    return 0;
}
