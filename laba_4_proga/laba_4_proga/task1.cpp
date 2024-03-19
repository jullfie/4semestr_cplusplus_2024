#include <iostream>﻿

#include "SecondMax.h"
#include "Vector.h"
#include "new_matrices.h"

int main() {
    std::setlocale(LC_ALL, "Russian");

    //тесты для поиска второго максимума
    // Для int
    int arrInt[] = { 1, 3, 5, 2, 4 };
    std::cout << "Index of second maximum in int array: " << findSecondMaximum(arrInt, 5) << std::endl;

    // Для float
    float arrFloat[] = { 1.1f, 3.3f, 5.5f, 2.2f, 4.4f };
    std::cout << "Index of second maximum in float array: " << findSecondMaximum(arrFloat, 5) << std::endl;

    // Для double
    double arrDouble[] = { 1.01, 3.03, 5.05, 2.02, 4.04 };
    std::cout << "Index of second maximum in double array: " << findSecondMaximum(arrDouble, 5) << std::endl;

    // Для char
    char arrChar[] = { 'a', 'e', 'i', 'o', 'u' };
    std::cout << "Index of second maximum in char array: " << findSecondMaximum(arrChar, 5) << std::endl;


    //тесты для матриц
    // для int
    std::cout << "---- Testing Matrix with int ----" << std::endl;
    Matrix<int> matrixInt(3, 3);
    matrixInt.fillRandom();
    std::cout << "Int Matrix:\n" << matrixInt << std::endl;

    // для float
    std::cout << "---- Testing Matrix with float ----" << std::endl;
    Matrix<float> matrixFloat(3, 3);
    matrixFloat.fillRandom();
    std::cout << "Float Matrix:\n" << matrixFloat << std::endl;

    // для double
    std::cout << "---- Testing Matrix with double ----" << std::endl;
    Matrix<double> matrixDouble(3, 3);
    matrixDouble.fillRandom();
    std::cout << "Double Matrix:\n" << matrixDouble << std::endl;

    // Дополнительные операции, сложение матриц того же типа
    std::cout << "Addition of two int Matrices:\n" << matrixInt + matrixInt << std::endl;
    std::cout << "Addition of two float Matrices:\n" << matrixFloat + matrixFloat << std::endl;
    std::cout << "Addition of two double Matrices:\n" << matrixDouble + matrixDouble << std::endl;


    //тесты векторов
    // для float
    std::cout << "---- Testing Vector operations with float ----" << std::endl;
    Vector<float> vectorFloat1(3), vectorFloat2(3);
    // Заполнение векторов
    vectorFloat1[0][0] = 1.0f; vectorFloat1[0][1] = 3.0f; vectorFloat1[0][2] = -5.0f;
    vectorFloat2[0][0] = 4.0f; vectorFloat2[0][1] = -2.0f; vectorFloat2[0][2] = -1.0f;

    std::cout << "Scalar Product of float vectors: " << vectorFloat1.dotProduct(vectorFloat2) << std::endl;
    Vector<float> crossProductFloat = vectorFloat1.crossProduct(vectorFloat2);
    std::cout << "Cross Product of float vectors: (" << crossProductFloat[0][0] << ", " << crossProductFloat[0][1] << ", " << crossProductFloat[0][2] << ")" << std::endl;


    // для double
    std::cout << "---- Testing Vector operations with double ----" << std::endl;
    Vector<double> vectorDouble1(3), vectorDouble2(3);
    // Заполнение векторов
    vectorDouble1[0][0] = 2.0; vectorDouble1[0][1] = 4.0; vectorDouble1[0][2] = -3.0;
    vectorDouble2[0][0] = -1.0; vectorDouble2[0][1] = 5.0; vectorDouble2[0][2] = 2.0;

    std::cout << "Scalar Product of double vectors: " << vectorDouble1.dotProduct(vectorDouble2) << std::endl;
    Vector<double> crossProductDouble = vectorDouble1.crossProduct(vectorDouble2);
    std::cout << "Cross Product of double vectors: (" << crossProductDouble[0][0] << ", " << crossProductDouble[0][1] << ", " << crossProductDouble[0][2] << ")" << std::endl;


    // для int
    std::cout << "---- Testing Vector operations with int ----" << std::endl;
    Vector<int> vectorInt1(3), vectorInt2(3);
    // Заполнение векторов
    vectorInt1[0][0] = 2; vectorInt1[0][1] = 4; vectorInt1[0][2] = -3;
    vectorInt2[0][0] = -1; vectorInt2[0][1] = 5; vectorInt2[0][2] = 2;

    std::cout << "Scalar Product of int vectors: " << vectorInt1.dotProduct(vectorInt2) << std::endl;
    Vector<int> crossProductInt = vectorInt1.crossProduct(vectorInt2);
    std::cout << "Cross Product of int vectors: (" << crossProductInt[0][0] << ", " << crossProductInt[0][1] << ", " << crossProductInt[0][2] << ")" << std::endl;
    
    return 0;
}
