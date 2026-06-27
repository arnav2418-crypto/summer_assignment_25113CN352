#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0, choice, searchRoll, found;

    while (1) {
        printf("\n--- STUDENT RECORD SYSTEM ---\n");
        printf("1. Add Student\n2. View All Students\n3. Search Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count < MAX_STUDENTS) {
                    printf("Enter Roll Number: ");
                    scanf("%d", &students[count].roll);
                    printf("Enter Name: ");
                    scanf(" %[^\n]s", students[count].name); 
                    printf("Enter Marks: ");
                    scanf("%f", &students[count].marks);
                    count++;
                    printf("Record added successfully!\n");
                } else {
                    printf("Database full!\n");
                }
                break;

            case 2: 
                if (count == 0) {
                    printf("No records found.\n");
                } else {
                    printf("\nRoll\tName\t\tMarks\n");
                    printf("---------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%-15s\t%.2f\n", students[i].roll, students[i].name, students[i].marks);
                    }
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("No records available to search.\n");
                    break;
                }
                printf("Enter Roll Number to search: ");
                scanf("%d", &searchRoll);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].roll == searchRoll) {
                        printf("\nStudent Found:\nRoll: %d\nName: %s\nMarks: %.2f\n", 
                               students[i].roll, students[i].name, students[i].marks);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Student with Roll Number %d not found.\n", searchRoll);
                }
                break;

            case 4: 
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
