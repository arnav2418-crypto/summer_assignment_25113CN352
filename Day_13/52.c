#include <stdio.h>

int main() {
    int size, i;
    int even_sum = 0, odd_sum = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; 
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            even_sum += arr[i]; 
        } else {
            odd_sum += arr[i];  
        }
    }
    printf("\nSum of Even elements = %d", even_sum);
    printf("\nSum of Odd elements = %d\n", odd_sum);

    return 0;
}
