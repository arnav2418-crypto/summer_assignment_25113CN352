#include <stdio.h>
#include <string.h>

#define MAX_SEATS 10

int main() {
    int seats[MAX_SEATS] = {0}; 
    char passengerNames[MAX_SEATS][50];
    int choice, seatNum;

    do {
        printf("\n=== TICKET BOOKING SYSTEM ===\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Seat Status ---\n");
                for (int i = 0; i < MAX_SEATS; i++) {
                    if (seats[i] == 0)
                        printf("Seat %d: Available\n", i + 1);
                    else
                        printf("Seat %d: Booked by %s\n", i + 1, passengerNames[i]);
                }
                break;

            case 2:
                printf("\nEnter seat number (1-%d): ", MAX_SEATS);
                scanf("%d", &seatNum);
                if (seatNum < 1 || seatNum > MAX_SEATS) {
                    printf("Invalid seat number!\n");
                } else if (seats[seatNum - 1] == 1) {
                    printf("Sorry, Seat %d is already booked!\n", seatNum);
                } else {
                    printf("Enter passenger name: ");
                    scanf("%s", passengerNames[seatNum - 1]);
                    seats[seatNum - 1] = 1;
                    printf("Ticket booked successfully for Seat %d!\n", seatNum);
                }
                break;

            case 3:
                printf("\nEnter seat number to cancel (1-%d): ", MAX_SEATS);
                scanf("%d", &seatNum);
                if (seatNum < 1 || seatNum > MAX_SEATS) {
                    printf("Invalid seat number!\n");
                } else if (seats[seatNum - 1] == 0) {
                    printf("Seat %d is already available (not booked).\n", seatNum);
                } else {
                    seats[seatNum - 1] = 0;
                    strcpy(passengerNames[seatNum - 1], "");
                    printf("Booking for Seat %d has been canceled.\n", seatNum);
                }
                break;

            case 4:
                printf("\nExiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
