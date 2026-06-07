#include <stdio.h>
int reverse_number(int num, int reversed) {
    if (num == 0) {
        return reversed;
    }
    int last_digit = num % 10;
    reversed = (reversed * 10) + last_digit;
    return reverse_number(num / 10, reversed);
}

int main() {
    int input_num;
    
    printf("Enter an integer: ");
    scanf("%d", &input_num);
    int result = reverse_number(input_num, 0);
    
    printf("Reversed number: %d\n", result);
    
    return 0;
}
