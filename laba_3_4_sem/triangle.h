#pragma once 

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape2D.h"
#include <iostream>
#include <string>

class Triangle : public Shape2D {
private:
    float base;
    float height;

public:
    Triangle(float base, float height) : base(base), height(height) {
        CalculateArea();
    }

    void Scale(float scaleFactor) override {
        base *= scaleFactor;
        height *= scaleFactor;
        CalculateArea();
    }

    void CalculateArea() override {
        area = CalculateBaseArea();
    }

    // New method to calculate the area without modifying the member variable
    float CalculateBaseArea() const {
        return (base * height) / 2;
    }

    void ShowInfo() const override {
        std::cout << "Я треугольник!" << std::endl;
        std::cout << "Моя площадь = " << area << std::endl;
        std::cout << "Длина моего основания = " << base << std::endl;
        std::cout << "\nМоя высота = " << height << std::endl;
    }

    std::string GetName() const override {
        return "Triangle";
    }

    // Accessor methods to expose the base and height to subclasses
    float GetBase() const {
        return base;
    }

    float GetHeight() const {
        return height;
    }
};

#endif // TRIANGLE_H
