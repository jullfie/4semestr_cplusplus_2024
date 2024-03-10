#pragma once
#include "shape.h"



// Abstract class for 2D shapes
class Shape2D : public Shape {
protected:
    float area;
public:
    Shape2D() : area(0) {}

    float GetArea() const {
        return area;
    }

    virtual void CalculateArea() = 0;

    bool operator > (const Shape2D& rhs) const {
        return this->area > rhs.area;
    }

    bool operator < (const Shape2D& rhs) const {
        return this->area < rhs.area;
    }

    bool operator == (const Shape2D& rhs) const {
        return this->area == rhs.area;
    }
};


