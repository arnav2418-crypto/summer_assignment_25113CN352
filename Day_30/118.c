#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[100];
    int count = 0, choice, searchId, i;

    while (1) {
        printf("\n--- MINI LIBRARY ---\n");
        printf("1. Add Book\n2. View Books\n3. Search Book\n4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &library[count].id);
                printf("Enter Title: ");
                scanf(" %[^\n]s", library[count].title);
                printf("Enter Author: ");
                scanf(" %[^\n]s", library[count].author);
                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("Library is empty.\n");
                } else {
                    printf("\nID\tTitle\t\tAuthor\n");
                    for (i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
                    }
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);
                int found = 0;
                for (i = 0; i < count; i++) {
                    if (library[i].id == searchId) {
                        printf("\nFound! Title: %s, Author: %s\n", library[i].title, library[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Book not found.\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
