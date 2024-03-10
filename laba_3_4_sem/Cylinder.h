#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape3D.h"
#include "Circle.h"
#include <iostream>

class Cylinder : public Circle, public Shape3D {
private:
    float height;  // Height of the cylinder

public:
    // Constructor
    Cylinder(float radius, float height) : Circle(radius), height(height) {
        CalculateVolume();
    }

    // Override the Scale method to scale both the circle's radius and the cylinder's height
    void Scale(float scaleFactor) override {
        Circle::Scale(scaleFactor); // Scale the base circle
        height *= scaleFactor;      // Scale the height
        CalculateVolume();         // Recalculate the volume
    }

    // Volume calculation for the cylinder
    void CalculateVolume() override {
        volume = Circle::GetArea() * height;  // Volume formula for cylinder
    }

    // Show information about the cylinder
    void ShowInfo() const override {
        std::cout << "Я цилиндр!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Радиус основания = " << Circle::GetRadius() << std::endl; // This function should be provided in Circle class
        std::cout << "\nВысота = " << height << std::endl;
    }

    // Get the name of the shape
    std::string GetName() const override {
        return "Cylinder";
    }

    // Get the volume of the cylinder
    float GetVolume() const { return volume; }  // Already calculated in CalculateVolume()

    // Getter for height, if needed
    float GetHeight() const { return height; }
};

#endif // CYLINDER_H
