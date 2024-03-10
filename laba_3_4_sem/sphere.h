#pragma once
#include "shape3d.h"
#define PI = 3,1415926535

class Sphere : public Shape3D {
private:
	float radius;
public:
	void CalculateVolume() override {
		volume = 4 / 3 * PI * radius * radius * radius;
	}
};