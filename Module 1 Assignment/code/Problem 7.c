#include <iostream>
#include <cmath>

using namespace std;

const double G = 6.673e-8;  // Universal gravitational constant (cm^3)/(g*sec^2)

double calculateGravitationalForce(double mass1, double mass2, double distance) {
    if (distance == 0) {
        cout << "Distance cannot be zero." << endl;
        return -1;
    }
    return (G * mass1 * mass2) / (distance * distance);
}

int main() {
    double mass1, mass2, distance, force;
    char repeat;

    do {
        cout << "Enter the mass of the first body (in grams): ";
        cin >> mass1;

        cout << "Enter the mass of the second body (in grams): ";
        cin >> mass2;

        cout << "Enter the distance between the bodies (in centimeters): ";
        cin >> distance;

        force = calculateGravitationalForce(mass1, mass2, distance);

        if (force != -1) {
            cout << "The gravitational force between the two bodies is: " << force << " dynes" << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
