#include <iostream>
#include <string>
#include <cmath>
#include <clocale> // For setlocale
#include "Square.h"
#include "Triangle.h"
#include "triangular_pyramid.h"
#include "Sphere.h"


void TestSquare() {
    Square square(5);
    square.ShowInfo();
    square.Scale(2);
    square.ShowInfo();
}

void TestTriangle() {
    Triangle triangle(5, 10);
    triangle.ShowInfo();
    triangle.Scale(2);
    triangle.ShowInfo();
}

void TestTrianglePyramid() {
    TriangularPyramid pyramid(4.0f, 3.0f, 5.0f);  // Например, с параметрами 4, 3 и 5

    // Отображаем информацию о пирамиде
    pyramid.ShowInfo();

    // Масштабируем пирамиду с коэффициентом
    float scaleFactor = 2.0f;  // увеличиваем в 2 раза
    pyramid.Scale(scaleFactor);

    // Отображаем информацию о пирамиде после масштабирования
    std::cout << "\nПосле масштабирования:" << std::endl;
    pyramid.ShowInfo();
}

void TestSphere() {
    // Создание объекта сферы с радиусом 5.0
    Sphere mySphere(5.0f);

    // Отображение информации о сфере
    std::cout << "\nИнформация о сфере до масштабирования:" << std::endl;
    mySphere.ShowInfo();

    // Масштабирование сферы с коэффициентом масштабирования 2.0
    std::cout << "\nМасштабирование сферы с коэффициентом 2.0..." << std::endl;
    mySphere.Scale(2.0f);

    // Отображение информации о сфере после масштабирования
    std::cout << "\nИнформация о сфере после масштабирования:" << std::endl;
    mySphere.ShowInfo();
}

// Main function to demonstrate the functionality
int main() {
    std::setlocale(LC_ALL, "Russian");

    TestSquare();

    TestTriangle();

    TestTrianglePyramid();

    //TestCircle();

    //TestCylinder();

    TestSphere();

    return 0;
}





/*void TestCircle() {
    Circle circle(5);
    circle.ShowInfo();
    circle.Scale(2);
    circle.ShowInfo();
}

void TestCylinder() {
    Cylinder cylinder(5, 10);
    cylinder.ShowInfo();
    cylinder.Scale(2);
    cylinder.ShowInfo();

}
*/
