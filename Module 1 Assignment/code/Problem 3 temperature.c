#include <stdio.h>
#include <stdlib.h>

int main() {
    int startTemp, endTemp;
    float velocity;

    printf("Enter the starting temperature (C): ");
    scanf("%d", &startTemp);

    printf("Enter the ending temperature (C): ");
    scanf("%d", &endTemp);


    for (int temp = startTemp; temp <= endTemp; temp++) {
        velocity = 331.3 + 0.61 * temp;
        printf("At %d degrees Celsius the velocity of sound is %.1f m/s\n", temp, velocity);
    }

    return 0;
}
