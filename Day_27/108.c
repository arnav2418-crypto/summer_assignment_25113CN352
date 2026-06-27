#include <stdio.h>

int main() {
    char name[50];
    int m1, m2, m3, total;
    float perc;

    printf("Enter student name: ");
    fgets(name, sizeof(name), stdin);
    
    printf("Enter marks for 3 subjects: ");
    scanf("%d %d %d", &m1, &m2, &m3);
    total = m1 + m2 + m3;
    perc = (float)total / 3.0;

    printf("\n\n====== STUDENT MARKSHET ======\n");
    printf("Name: %s", name);
    printf("Marks: %d, %d, %d\n", m1, m2, m3);
    printf("Total: %d / 300\n", total);
    printf("Percentage: %.2f%%\n", perc);
    printf("Division: ");
    if (perc >= 60) {
        printf("First\n");
    } else if (perc >= 50) {
        printf("Second\n");
    } else if (perc >= 40) {
        printf("Third\n");
    } else {
        printf("Fail\n");
    }
    printf("==============================\n");

    return 0;
}
