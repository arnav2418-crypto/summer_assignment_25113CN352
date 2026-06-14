#include <stdio.h>

int main() {
    int arr[] = {2, 5, 8, 2, 3, 2, 7, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target, count = 0;
    printf("Enter the element to find its frequency: ");
    scanf("%d", &target);
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            count++;
        }
    }
    printf("The element %d occurs %d times in the array.\n", target, count);

    return 0;
}
