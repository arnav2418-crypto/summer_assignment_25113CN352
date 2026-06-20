#include <stdio.h>

int main() {
    int rows, cols;
    int i, j, sum;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n--- Column-wise Sums ---\n");
    for (j = 0; j < cols; j++) {
        sum = 0; 
        for (i = 0; i < rows; i++) {
            sum += matrix[i][j]; 
        }
        printf("Sum of Column %d = %d\n", j + 1, sum);
    }

    return 0;
}
