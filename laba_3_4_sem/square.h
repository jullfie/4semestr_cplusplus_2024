#pragma once
#include <iostream>
#include "shape2d.h"

// Concrete class for a Square
class Square : public Shape2D {
private:
    float side;
public:
    Square(float side) : side(side) {
        CalculateArea();
    }

    void Scale(float scaleFactor) override {
        side *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() const override {
        std::cout << "Я квадрат!" << std::endl;
        std::cout << "Моя площадь = " << area << std::endl;
        std::cout << "Длина стороны = " << side << std::endl;
    }

    std::string GetName() const override {
        return "Square";
    }

    void CalculateArea() override {
        area = side * side;
    }
};
