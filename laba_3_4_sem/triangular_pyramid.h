#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H

#include "Triangle.h"
#include "Shape3D.h"  // Include the header for the Shape3D class

// TriangularPyramid now inherits from both Triangle and Shape3D
class TriangularPyramid : public Triangle, public Shape3D {
private:
    float pyramidHeight;  // Height from the base to the apex

public:
    // Constructor
    TriangularPyramid(float base, float height, float pyramidHeight)
        : Triangle(base, height), pyramidHeight(pyramidHeight) {
        CalculateVolume();
    }

    // Scaling the pyramid scales all three dimensions
    void Scale(float scaleFactor) override {
        Triangle::Scale(scaleFactor); // Scale the base triangle
        pyramidHeight *= scaleFactor; // Scale the pyramid height
        CalculateVolume();
    }

    // Volume calculation for the pyramid
    void CalculateVolume() override {
        volume = (Triangle::CalculateBaseArea() * pyramidHeight) / 3;
    }

    // Show information about the pyramid
    void ShowInfo() const override {
        std::cout << "Я треугольная пирамида!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Длина ребра основания = " << Triangle::GetBase() << std::endl;
        std::cout << "Высота основания = " << Triangle::GetHeight() << std::endl;
        std::cout << "Моя высота = " << pyramidHeight << std::endl;
    }

    // Get the name of the shape
    std::string GetName() const override {
        return "TriangularPyramid";
    }

    // Function to get volume
    float GetVolume() const { return volume; }  // This should be inherited from Shape3D
};

#endif // TRIANGULAR_PYRAMID_H
