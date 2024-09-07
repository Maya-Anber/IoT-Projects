#include <iostream>
#include <cmath>

const double G = 6.673e-8;  // Universal gravitational constant (cm^3)/(g*sec^2)

double calculateGravitationalForce(double mass1, double mass2, double distance) {
    if (distance == 0) {
        std::cerr << "Distance cannot be zero." << std::endl;
        return -1;
    }
    return (G * mass1 * mass2) / (distance * distance);
}

int main() {
    double mass1, mass2, distance, force;
    char repeat;

    do {
        std::cout << "Enter the mass of the first body (in grams): ";
        std::cin >> mass1;

        std::cout << "Enter the mass of the second body (in grams): ";
        std::cin >> mass2;

        std::cout << "Enter the distance between the bodies (in centimeters): ";
        std::cin >> distance;

        force = calculateGravitationalForce(mass1, mass2, distance);

        if (force != -1) {
            std::cout << "The gravitational force between the two bodies is: " << force << " dynes" << std::endl;
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
