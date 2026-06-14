#include <stdio.h>

int main() {
    int array[100], target, i, n;
    int found = 0; 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        if (array[i] == target) {
            printf("%d found at index position %d.\n", target, i);
            found = 1; 
            break;     
        }
    }
    if (found == 0) {
        printf("%d is not present in the array.\n", target);
    }

    return 0;
}
