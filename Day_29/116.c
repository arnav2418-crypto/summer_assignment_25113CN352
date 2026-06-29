#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[30];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nInventory is full!\n");
        return;
    }
    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\n--- CURRENT INVENTORY ---\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-20s %-10d $%-9.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateStock() {
    int id, found = 0, newQty;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &newQty);
            inventory[i].quantity = newQty;
            printf("Stock updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Item ID not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=== INVENTORY SYSTEM ===\n");
        printf("1. Add Item\n2. View Inventory\n3. Update Stock\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: updateStock(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
