#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basic, allowances, deductions, net;
};

void addEmployee() {
    struct Employee emp;
    FILE *fp = fopen("salary_records.dat", "ab");
    if (fp == NULL) { printf("Error opening file!\n"); return; }

    printf("\nEnter ID: "); scanf("%d", &emp.id);
    printf("Enter Name: "); scanf(" %[^\n]s", emp.name);
    printf("Enter Basic Salary: "); scanf("%f", &emp.basic);
    printf("Enter Allowances: "); scanf("%f", &emp.allowances);
    printf("Enter Deductions: "); scanf("%f", &emp.deductions);

    emp.net = emp.basic + emp.allowances - emp.deductions;
    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);
    printf("Employee added successfully!\n");
}

void viewEmployees() {
    struct Employee emp;
    FILE *fp = fopen("salary_records.dat", "rb");
    if (fp == NULL) { printf("\nNo records found!\n"); return; }

    printf("\n--- SALARY RECORDS ---\n");
    printf("%-5s %-20s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Basic", "Allow.", "Deduct.", "Net Pay");
    printf("--------------------------------------------------------------\n");
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-5d %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n", emp.id, emp.name, emp.basic, emp.allowances, emp.deductions, emp.net);
    }
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Employee\n2. View All Records\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addEmployee();
        else if (choice == 2) viewEmployees();
        else if (choice == 3) break;
        else printf("Invalid choice!\n");
    }
    return 0;
}
