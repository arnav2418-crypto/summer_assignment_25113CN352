#include <stdio.h>
void rotateLeftByOne(int arr[], int size) {
    int temp = arr[0]; 
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    arr[size - 1] = temp; 
}
void rotateLeft(int arr[], int size, int positions) {
    positions = positions % size; 
    
    for (int i = 0; i < positions; i++) {
        rotateLeftByOne(arr, size);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int positions = 2; 

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    rotateLeft(arr, size, positions);

    printf("Array after %d left rotations: ", positions);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
