#include <stdio.h>
#include <limits.h> 

int main() {
    int arr[100], size, i;
    int max1, max2;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    if (size < 2) {
        printf("Invalid Input! Array must contain at least two elements.\n");
        return 1; 
    }
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    max1 = INT_MIN; 
    max2 = INT_MIN; 
    for (i = 0; i < size; i++) {
        if (arr[i] > max1) {
            
            max2 = max1; 
            max1 = arr[i]; 
        } 
        else if (arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i]; 
        }
    }
    if (max2 == INT_MIN) {
        printf("There is no second largest element (all elements are equal).\n");
    } else {
        printf("The largest element is: %d\n", max1);
        printf("The second largest element is: %d\n", max2);
    }

    return 0;
}
