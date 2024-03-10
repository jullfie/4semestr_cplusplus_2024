#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H

#include "Shape3D.h"
#include <cmath>

// TriangularPyramid is a subclass of Shape3D
class TriangularPyramid : public Shape3D {
private:
    float baseEdge; // Edge length of the triangular base
    float height; // Height from the base to the apex

public:
    // Constructor
    TriangularPyramid(float baseEdge, float height)
        : baseEdge(baseEdge), height(height) {
        CalculateVolume(); // Calculate the volume when the pyramid is created
    }

    // Implement the pure virtual scaling method
    void Scale(float scaleFactor) override {
        baseEdge *= scaleFactor;
        height *= scaleFactor;
        CalculateVolume(); // Recalculate the volume after scaling
    }

    // Implement the pure virtual volume calculation method
    void CalculateVolume() override {
        float baseArea = (sqrt(3) / 4) * baseEdge * baseEdge; // Area of equilateral triangle
        volume = (baseArea * height) / 3; // Volume of the pyramid
    }

    // Implement the pure virtual method to show information about the pyramid
    void ShowInfo() const override {
        std::cout << "Я триангулярная пирамида!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Длина ребра основания = " << baseEdge << std::endl;
        std::cout << "Моя высота = " << height << std::endl;
    }

    // Implement the pure virtual method to get the name of the shape
    std::string GetName() const override {
        return "TriangularPyramid";
    }

    // Destructor
    ~TriangularPyramid() override {}
};

#endif // TRIANGULAR_PYRAMID_H
