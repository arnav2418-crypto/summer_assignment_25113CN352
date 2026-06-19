#include <stdio.h>

int main() {
    int n, i, j, sum = 0;
    int matrix[10][10];
    printf("Enter the size of the square matrix (e.g., 3 for 3x3): ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        sum += matrix[i][i]; 
    }
    printf("\nSum of the main diagonal elements = %d\n", sum);

    return 0;
}
