#include <stdio.h>
int findIntersection(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int k = 0; 
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                int isDuplicate = 0;
                for (int m = 0; m < k; m++) {
                    if (result[m] == arr1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    result[k] = arr1[i];
                    k++;
                }
                break; 
            }
        }
    }
    return k; 
}

int main() {
    int arr1[] = {4, 9, 2, 4, 1, 7};
    int arr2[] = {2, 7, 4, 4, 8};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int maxIntersectionSize = (size1 < size2) ? size1 : size2;
    int result[maxIntersectionSize];
    int intersectionSize = findIntersection(arr1, size1, arr2, size2, result);
    printf("Array 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", arr1[i]);
    
    printf("\nArray 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", arr2[i]);

    printf("\nIntersection elements: ");
    if (intersectionSize == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < intersectionSize; i++) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");

    return 0;
}
