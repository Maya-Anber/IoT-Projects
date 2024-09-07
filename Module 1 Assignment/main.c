#include <stdio.h>
#include <stdlib.h>

int main() {
    float time, distance;
    const float acceleration = 32.0;
    printf("time in seconds: ");
    scanf("%f", &time);
    distance = (acceleration * time * time) / 2;
    printf("The object will drop %.2f feet", distance);

    return 0;
}
