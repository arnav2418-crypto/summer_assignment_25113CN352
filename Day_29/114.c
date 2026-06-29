#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

int arr[MAX];
int size = 0; 

void createArray();
void displayArray();
void insertElement();
void deleteElement();
void searchElement();

int main() {
    int choice;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Create/Initialize Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: searchElement(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}
void createArray() {
    printf("Enter number of elements (1-%d): ", MAX);
    scanf("%d", &size);
    if (size > MAX || size < 1) {
        printf("Invalid size. Please try again.\n");
        size = 0;
        return;
    }
    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

void displayArray() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    if (size >= MAX) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }
    int element, pos;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter position (1 to %d): ", size + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    size++;
    printf("Element inserted successfully!\n");
}

void deleteElement() {
    if (size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    int pos;
    printf("Enter position of the element to delete (1 to %d): ", size);
    scanf("%d", &pos);

    if (pos < 1 || pos > size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully!\n");
}

void searchElement() {
    if (size == 0) {
        printf("Array is empty. No elements to search.\n");
        return;
    }
    int target, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at position %d (index %d).\n", target, i + 1, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}
