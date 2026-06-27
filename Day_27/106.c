#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};
void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp.name); 
    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}
void viewEmployees() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    struct Employee emp;
    printf("\n--- Employee Records ---\n");
    printf("%-5s %-20s %-10s\n", "ID", "Name", "Salary");
    printf("-----------------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        printf("%-5d %-20s %-10.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(fp);
}
void searchEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    int searchId, found = 0;
    struct Employee emp;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    while (fread(&emp, sizeof(struct Employee), 1, fp)) {
        if (emp.id == searchId) {
            printf("\nRecord Found:\nID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
    fclose(fp);
}
int main() {
    int choice;
    while (1) {
        printf("\n*** Employee Management System ***\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
