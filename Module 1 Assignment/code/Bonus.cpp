#include <iostream>
#include <cmath>

using namespace std;

float calculatePricePerSquareInch(float diameter, float price) {
    float radius = diameter / 2.0;
    float area = M_PI * radius * radius;
    return price / area;
}

int main() {
    float diameter1, price1, diameter2, price2;
    float pricePerSquareInch1, pricePerSquareInch2;

    cout << "Enter the diameter (in inches) and price for the first pizza: ";
    cin >> diameter1 >> price1;
    cout << "Enter the diameter (in inches) and price for the second pizza: ";
    cin >> diameter2 >> price2;

    pricePerSquareInch1 = calculatePricePerSquareInch(diameter1, price1);
    pricePerSquareInch2 = calculatePricePerSquareInch(diameter2, price2);

    cout << "Price per square inch for the first pizza: $" << pricePerSquareInch1 << endl;
    cout << "Price per square inch for the second pizza: $" << pricePerSquareInch2 << endl;

    if (pricePerSquareInch1 < pricePerSquareInch2) {
        cout << "The first pizza is the better buy." << endl;
    } else if (pricePerSquareInch2 < pricePerSquareInch1) {
        cout << "The second pizza is the better buy." << endl;
    } else {
        cout << "Both pizzas have the same price per square inch. The smaller pizza is considered the better buy." << endl;
    }

    return 0;
}
