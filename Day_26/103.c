#include <stdio.h>

int main() {
    int choice, pin = 1234;
    int input_pin, attempts = 0;
    float balance = 5000.00;
    float amount;
    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &input_pin);

        if (input_pin == pin) {
            printf("\nPIN accepted! Welcome to your account.\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. You have %d attempt(s) left.\n\n", 3 - attempts);
        }

        if (attempts == 3) {
            printf("Too many incorrect attempts. Your account is locked.\n");
            return 0;
        }
    }
    do {
        printf("\n=============================");
        printf("\n       ATM SIMULATOR         ");
        printf("\n=============================");
        printf("\n 1. Check Balance            ");
        printf("\n 2. Deposit Cash             ");
        printf("\n 3. Withdraw Cash            ");
        printf("\n 4. Exit                     ");
        printf("\n=============================");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Please collect your cash. Withdrawn: $%.2f. New balance: $%.2f\n", amount, balance);
                } else if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 4:
                printf("\nThank you for using the ATM. Have a great day!\n");
                break;

            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
