#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int isSymmetric = 1; 
    int matrix[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if (rows != cols) {
        printf("The matrix is NOT symmetric (Not a square matrix).\n");
        return 0;
    }
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; 
                break;
            }
        }
        if (!isSymmetric) {
            break; 
        }
    }
    if (isSymmetric) {
        printf("\nThe given matrix IS a Symmetric Matrix.\n");
    } else {
        printf("\nThe given matrix is NOT a Symmetric Matrix.\n");
    }

    return 0;
}
