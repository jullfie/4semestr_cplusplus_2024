#pragma once
#include <string>

// Base abstract class for all shapes
class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() const = 0;
    virtual std::string GetName() const = 0;
    virtual ~Shape() {}
};
