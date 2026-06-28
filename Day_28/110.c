#include <stdio.h>
#include <string.h>

struct BankAccount {
    char name[50];
    int accNumber;
    float balance;
};

void createAccount(struct BankAccount *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", acc->name);
    acc->balance = 0.0;
    printf("\nAccount Created Successfully!\n");
}

void checkBalance(struct BankAccount acc) {
    printf("\nCurrent Balance: $%.2f\n", acc.balance);
}

void deposit(struct BankAccount *acc) {
    float amount;
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("\n$%.2f Deposited Successfully!\n", amount);
    } else {
        printf("\nInvalid amount!\n");
    }
}

void withdraw(struct BankAccount *acc) {
    float amount;
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("\n$%.2f Withdrawn Successfully!\n", amount);
    } else if (amount > 0) {
        printf("\nInsufficient Balance!\n");
    } else {
        printf("\nInvalid amount!\n");
    }
}

int main() {
    struct BankAccount account;
    int choice;
    int isCreated = 0;

    while (1) {
        printf("\n=== Bank Account System ===");
        printf("\n1. Create Account");
        printf("\n2. Check Balance");
        printf("\n3. Deposit");
        printf("\n4. Withdraw");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                isCreated = 1;
                break;
            case 2:
                if (isCreated) checkBalance(account);
                else printf("\nPlease create an account first!\n");
                break;
            case 3:
                if (isCreated) deposit(&account);
                else printf("\nPlease create an account first!\n");
                break;
            case 4:
                if (isCreated) withdraw(&account);
                else printf("\nPlease create an account first!\n");
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
