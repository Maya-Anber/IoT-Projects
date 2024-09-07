#include <stdio.h>
#include <stdlib.h>
#define LITERS_PER_GALLON 0.264179

float calculateMilesPerGallon(float liters, float miles) {
    float gallons = liters * LITERS_PER_GALLON;
    return miles / gallons;
}

int main() {
    float liters, miles, milesPerGallon;
    char repeat;

    do {
        printf("Enter the number of liters consumed: ");
        scanf("%f", &liters);

        printf("Enter the number of miles traveled: ");
        scanf("%f", &miles);

        milesPerGallon = calculateMilesPerGallon(liters, miles);

        printf("The car delivered %.2f miles per gallon.\n", milesPerGallon);

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
