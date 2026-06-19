#include <stdio.h>

int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int A[r][c], B[r][c], sum[r][c];

    printf("Enter elements of matrix A:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            scanf("%d", &B[i][j]);
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            sum[i][j] = A[i][j] + B[i][j];

    printf("Resultant Matrix:\n");
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) printf("%d\t", sum[i][j]);
        printf("\n");
    }
    return 0;
}
