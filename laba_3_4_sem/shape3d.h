#pragma once
#include "shape.h"


// Abstract class for 3D shapes
class Shape3D : public Shape {
protected:
    float volume;
public:
    Shape3D() : volume(0) {}

    float GetVolume() const {
        return volume;
    }

    virtual void CalculateVolume() = 0;

    bool operator > (const Shape3D& rhs) const {
        return this->volume > rhs.volume;
    }

    bool operator < (const Shape3D& rhs) const {
        return this->volume < rhs.volume;
    }

    bool operator == (const Shape3D& rhs) const {
        return this->volume == rhs.volume;
    }
};

