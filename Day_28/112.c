#include <stdio.h>
#include <string.h>

#define MAX 50

struct Contact {
    char name[30];
    char phone[15];
};

struct Contact list[MAX];
int count = 0;

void addContact() {
    if (count >= MAX) {
        printf("\n list full!\n");
        return;
    }
    printf("\nEnter Name: ");
    scanf(" %[^\n]s", list[count].name);
    printf("Enter Phone: ");
    scanf("%s", list[count].phone);
    count++;
    printf("Contact added successfully!\n");
}

void viewContacts() {
    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, list[i].name, list[i].phone);
    }
}

void searchContact() {
    char query[30];
    int found = 0;
    printf("\nEnter name to search: ");
    scanf(" %[^\n]s", query);
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(list[i].name, query) == 0) {
            printf("Found: %s - %s\n", list[i].name, list[i].phone);
            found = 1;
        }
    }
    if (!found) printf("Contact not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add 2. View 3. Search 4. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
