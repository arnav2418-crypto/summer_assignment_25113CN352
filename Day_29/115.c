#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str1[100], str2[100];
    int choice;

    do {
        printf("\n--- STRING OPERATIONS MENU ---\n");
        printf("1. Calculate Length\n");
        printf("2. Reverse String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Copy String\n");
        printf("5. Compare Strings\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter string: ");
                scanf("%s", str1);
                printf("Length: %d\n", strlen(str1));
                break;
            case 2:
                printf("Enter string: ");
                scanf("%s", str1);
                printf("Reversed: %s\n", strrev(str1)); 
                break;
            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 4:
                printf("Enter source string: ");
                scanf("%s", str1);
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 5:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                if (strcmp(str1, str2) == 0)
                    printf("Strings are identical.\n");
                else
                    printf("Strings are different.\n");
                break;
            case 6:
                printf("Exiting program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number from 1 to 6.\n");
        }
    } while(choice != 6);

    return 0;
}
