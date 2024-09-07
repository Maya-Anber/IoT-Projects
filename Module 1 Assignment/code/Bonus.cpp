#include <iostream>
#include <cmath>

float calculatePricePerSquareInch(float diameter, float price) {
    float radius = diameter / 2.0;
    float area = M_PI * radius * radius;
    return price / area;
}

int main() {
    float diameter1, price1, diameter2, price2;
    float pricePerSquareInch1, pricePerSquareInch2;

    std::cout << "Enter the diameter (in inches) and price for the first pizza: ";
    std::cin >> diameter1 >> price1;
    std::cout << "Enter the diameter (in inches) and price for the second pizza: ";
    std::cin >> diameter2 >> price2;

    pricePerSquareInch1 = calculatePricePerSquareInch(diameter1, price1);
    pricePerSquareInch2 = calculatePricePerSquareInch(diameter2, price2);

    std::cout << "Price per square inch for the first pizza: $" << pricePerSquareInch1 << std::endl;
    std::cout << "Price per square inch for the second pizza: $" << pricePerSquareInch2 << std::endl;

    if (pricePerSquareInch1 < pricePerSquareInch2) {
        std::cout << "The first pizza is the better buy." << std::endl;
    } else if (pricePerSquareInch2 < pricePerSquareInch1) {
        std::cout << "The second pizza is the better buy." << std::endl;
    } else {
        std::cout << "Both pizzas have the same price per square inch. The smaller pizza is considered the better buy." << std::endl;
    }

    return 0;
}
