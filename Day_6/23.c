#include <stdio.h>
int countSetBits(unsigned int num) {
    int count = 0;
    
    while (num > 0) {
        count += (num & 1); 
        num >>= 1; 
    }
    return count;
}
int main() {
    unsigned int number;
    
    printf("Enter an integer: ");
    scanf("%u", &number);
    
    int result = countSetBits(number);
    
    printf("Number of set bits (1s): %d\n", result);
    
    return 0;
}