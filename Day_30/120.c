#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

void displayMenu();
void addStudent(char names[][MAX_NAME_LEN], int marks[], int *count);
void displayStudents(char names[][MAX_NAME_LEN], int marks[], int count);
void searchStudent(char names[][MAX_NAME_LEN], int marks[], int count);
void calculateAverage(int marks[], int count);

int main() {
    
    char studentNames[MAX_STUDENTS][MAX_NAME_LEN];
    int studentMarks[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                addStudent(studentNames, studentMarks, &studentCount);
                break;
            case 2:
                displayStudents(studentNames, studentMarks, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentMarks, studentCount);
                break;
            case 4:
                calculateAverage(studentMarks, studentCount);
                break;
            case 5:
                printf("\nExiting the system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}


void displayMenu() {
    printf("\n====================================");
    printf("\n  STUDENT DATABASE MANAGEMENT SYSTEM");
    printf("\n====================================");
    printf("\n1. Add New Student");
    printf("\n2. Display All Students");
    printf("\n3. Search Student by Name");
    printf("\n4. Calculate Class Average");
    printf("\n5. Exit");
    printf("\n====================================\n");
}


void addStudent(char names[][MAX_NAME_LEN], int marks[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter student's full name: ");
    fgets(names[*count], MAX_NAME_LEN, stdin);
    
    
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter student's marks: ");
    scanf("%d", &marks[*count]);
    getchar(); // Clear buffer

    (*count)++; 
    printf("\nStudent record added successfully!\n");
}


void displayStudents(char names[][MAX_NAME_LEN], int marks[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n%-5s %-30s %-10s\n", "ID", "Student Name", "Marks");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-30s %-10d\n", i + 1, names[i], marks[i]);
    }
}


void searchStudent(char names[][MAX_NAME_LEN], int marks[], int count) {
    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    char searchName[MAX_NAME_LEN];
    int found = 0;

    printf("\nEnter the exact name of the student to search: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    for (int i = 0; i < count; i++) {
    
        if (strcmp(names[i], searchName) == 0) {
            printf("\nRecord Found!");
            printf("\nID: %d\nName: %s\nMarks: %d\n", i + 1, names[i], marks[i]);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nStudent '%s' not found in the database.\n", searchName);
    }
}
void calculateAverage(int marks[], int count) {
    if (count == 0) {
        printf("\nNo marks available to calculate average.\n");
        return;
    }

    int totalSum = 0;
    for (int i = 0; i < count; i++) {
        totalSum += marks[i];
    }

    float average = (float)totalSum / count;
    printf("\nTotal Students: %d", count);
    printf("\nClass Average Marks: %.2f\n", average);
}
