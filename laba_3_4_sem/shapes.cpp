#include <iostream>
#include <string>
#include <cmath>
#include "square.h"


// Add other classes like Triangle, Circle, TriangularPyramid, Cylinder, and Sphere
// following the same pattern as above

// Main function to demonstrate the functionality
int main() {

    std::setlocale(LC_ALL, "Russian");

    // Create and test shapes here
    Square square(5);
    square.ShowInfo();
    square.Scale(2);
    square.ShowInfo();

    // Add tests for other shapes

    return 0;
}
