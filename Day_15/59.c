#include <stdio.h>
void rotateRight(int arr[], int size, int d) {
    d = d % size;
    for (int i = 0; i < d; i++) {
        int last = arr[size - 1]; 
        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = last; 
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotations = 2;

    printf("Original Array: ");
    printArray(arr, size);
    rotateRight(arr, size, rotations);

    printf("Rotated Array:  ");
    printArray(arr, size);

    return 0;
}
