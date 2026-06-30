#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    float salary;
};
struct Employee emp[MAX];
int count = 0;

void addEmployee() {
    if (count >= MAX) {
        printf("\nSystem Full!\n");
        return;
    }
    printf("\nEnter ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", emp[count].name); 
    printf("Enter Salary: ");
    scanf("%f", &emp[count].salary);
    count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
}

void searchEmployee() {
    int searchId, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchId) {
            printf("\nEmployee Found:\nID: %d\nName: %s\nSalary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee with ID %d not found.\n", searchId);
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Mini Employee System ***\n");
        printf("1. Add Employee\n2. Display All\n3. Search Employee\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
