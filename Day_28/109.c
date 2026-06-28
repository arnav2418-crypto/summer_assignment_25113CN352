#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[MAX_BOOKS];
    int count = 0;
    int choice, searchId, found;

    while (1) {
        printf("\n--- Library System ---\n");
        printf("1. Add Book\n2. Display All Books\n3. Search Book by ID\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_BOOKS) {
                    printf("Enter Book ID: ");
                    scanf("%d", &library[count].id);
                    getchar(); 
                    
                    printf("Enter Book Title: ");
                    fgets(library[count].title, 50, stdin);
                    library[count].title[strcspn(library[count].title, "\n")] = 0; // Remove newline

                    printf("Enter Author Name: ");
                    fgets(library[count].author, 50, stdin);
                    library[count].author[strcspn(library[count].author, "\n")] = 0; // Remove newline

                    count++;
                    printf("Book added successfully!\n");
                } else {
                    printf("Library is full!\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    printf("\nID\t%-25s\t%-25s\n", "Title", "Author");
                    printf("--------------------------------------------------------\n");
                    for (int i = 0; i < count; i++) {
                        printf("%d\t%-25s\t%-25s\n", library[i].id, library[i].title, library[i].author);
                    }
                }
                break;

            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (library[i].id == searchId) {
                        printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\n", library[i].id, library[i].title, library[i].author);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book with ID %d not found.\n", searchId);
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
