#include <stdio.h>

int main() {
    int size1, size2, size3;
    int arr1[50], arr2[50], merged[100];
    int i, j;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements for the first array:\n", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements for the second array:\n", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    size3 = size1 + size2;

    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (j = 0; j < size2; j++) {
        merged[size1 + j] = arr2[j];
    }

    printf("\nThe merged array elements are:\n");
    for (i = 0; i < size3; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
