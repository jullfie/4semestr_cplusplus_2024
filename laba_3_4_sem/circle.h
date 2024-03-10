#pragma once
#include "shape2d.h"
#include <iostream>
#define PI = 3.1415926535


class Circle : public Shape2D {
private:
	float radius;
public:
	void CalculateArea() override {
		area = PI* radius* radius;
	}
};