#pragma once
#include "shape2d.h"

class Triangle : public Shape2D {
private:
	float base;
	float height;
public:
	void CalculateArea() override {
		area = 0.5 * base * height;
	};

};