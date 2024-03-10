#ifndef CIRCLE_H
#define CIRCLE_H
#define PI          3.14159265358979323846

#include "Shape2D.h"
#include <iostream>
#include <cmath>

class Circle : public Shape2D {
private:
    float radius;  // Radius of the circle

public:
    // Constructor
    Circle(float radius) : radius(radius) {
        CalculateArea();
    }

    // Override the Scale method to scale the circle's radius
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;  // Scale the radius
        CalculateArea();       // Recalculate the area
    }

    // Area calculation for the circle
    void CalculateArea() override {
        area = PI * pow(radius, 2);  // Area formula for circle
    }

    // Show information about the circle
    void ShowInfo() const override {
        std::cout << "Я круг!" << std::endl;
        std::cout << "Моя площадь = " << area << std::endl;
        std::cout << "\nРадиус = " << radius << std::endl;
    }

    // Get the name of the shape
    std::string GetName() const override {
        return "Circle";
    }

    // Function to get area
    float GetArea() const { return area; }  // Already calculated in CalculateArea()
};

#endif // CIRCLE_H
