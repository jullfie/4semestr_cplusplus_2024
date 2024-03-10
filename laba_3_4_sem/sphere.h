#ifndef SPHERE_H
#define SPHERE_H
#define PI          3.14159265358979323846

#include "Shape3D.h"
#include <iostream>
#include <cmath>

// Sphere inherits from Shape3D
class Sphere : public Shape3D {
private:
    float radius;  // Radius of the sphere

public:
    // Constructor
    Sphere(float radius) : radius(radius) {
        CalculateVolume();
    }

    // Override the Scale method to scale the sphere's radius
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;  // Scale the radius
        CalculateVolume();     // Recalculate the volume
    }

    // Volume calculation for the sphere
    void CalculateVolume() override {
        volume = (4.0f / 3.0f) * PI * pow(radius, 3);  // Volume formula for sphere
    }

    // Show information about the sphere
    void ShowInfo() const override {
        std::cout << "Я сфера!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "\nРадиус = " << radius << std::endl;
    }

    // Get the name of the shape
    std::string GetName() const override {
        return "Sphere";
    }

    // Get the volume of the sphere
    float GetVolume() const { return volume; }  // Already calculated in CalculateVolume()
};

#endif // SPHERE_H
