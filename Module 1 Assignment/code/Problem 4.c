#include <stdio.h>
#include <stdlib.h>

int main() {
    float balance, interest, totalDue, minPayment;
    int choice;

    do {
        printf("Enter the account balance: ");
        scanf("%f", &balance);

        if (balance <= 1000) {
            interest = balance * 0.015;
        } else {
            interest = (1000 * 0.015) + ((balance - 1000) * 0.01);
        }

        totalDue = balance + interest;

        if (totalDue <= 10) {
            minPayment = totalDue;
        } else {
            minPayment = (totalDue * 0.10 > 10) ? (totalDue * 0.10) : 10;
        }

        printf("Interest due: %.2f\n", interest);
        printf("Total amount due: %.2f\n", totalDue);
        printf("Minimum payment: %.2f\n", minPayment);

        printf("Do you want to calculate again? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 0:
                printf("goodbye\n");
                break;
            default:
                printf("Invalid choice. Exiting the program\n");
                choice = 0;
                break;
        }

    } while (choice == 1);

    return 0;
}
