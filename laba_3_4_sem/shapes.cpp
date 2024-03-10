/*П.С.

Ипользовала маштабирование оюъемных фигур,для плоских эта виртуальная функция написана, но не сделала вывод.
чтобы на глаз легче различать в цмд.
плюс это множественно наследование в объяемных... поэтмоу на объемные потратила больше времени и сил.

Использовала в классах виртуальные функции, т.к. это соответствует конуцепции полиморфизма:
- они позволяют  объектам использовать подходящие реализации методов в соответствии с их
фактическим типом данных, а не типом данных, указанным в указателе или ссылке

- При наследовании подкласс может переопределить методы базового класса, чтобы обеспечить
специфичное для себя поведение

- можно расширить свою программу и добавлять новые подклассы, которые реализуют те же самые
виртуальные функции, не изменяя существующий код, который использует базовые классы


в моей программе я исопльзую эту фишку,например, в классе Cylinder,виртуальная функция Scale (изм размер),
CalculateArea (вычисл площади) и CalculateVolume (вычисл объема) - если я захочу добавить еще геом фигуры, то
используя указатели на базовый класс Shape2D или Shape3D, было бы достаточно высвать Scale и объект масштабировался бы,
независимо от того, какой фигур является*/

#include <iostream>
#include <string>
#include <cmath>
#include <clocale> // For setlocale
#include "Square.h"
#include "Triangle.h"
#include "triangular_pyramid.h"
#include "Sphere.h"
#include "Circle.h"
#include "Cylinder.h"

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

void TestCircle() {
    Circle circle(5);
    circle.ShowInfo();
    circle.Scale(2);
    circle.ShowInfo();
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

void TestCylinder() {
    // Создаем объект цилиндра с радиусом 4 и высотой 8
    Cylinder myCylinder(4.0f, 8.0f);

    // Выводим информацию о цилиндре
    std::cout << "\nИнформация о цилиндре до масштабирования:" << std::endl;
    myCylinder.ShowInfo();

    // Масштабируем цилиндр с коэффициентом 1.5
    std::cout << "\nМасштабирование цилиндра с коэффициентом 1.5..." << std::endl;
    myCylinder.Scale(1.5f);

    // Выводим информацию о цилиндре после масштабирования
    std::cout << "\nИнформация о цилиндре после масштабирования:" << std::endl;
    myCylinder.ShowInfo();
}

//функция для тестов функций
int main() {
    std::setlocale(LC_ALL, "Russian");

    TestSquare();
    TestTriangle();
    TestCircle();
    TestSphere();
    TestTrianglePyramid();
    TestCylinder();
    
    

    return 0;
}

