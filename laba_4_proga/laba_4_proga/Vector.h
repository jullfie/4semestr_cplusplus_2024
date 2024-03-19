// Vector.h
#pragma once // Защита от повторного включения файла
#include "new_matrices.h" // Подключение определения класса Matrix

// Шаблонный класс Vector наследуется от шаблонного класса Matrix
template<typename T>
class Vector : public Matrix<T> {
public:
    
    Vector(unsigned int n) : Matrix<T>(1, n) {} // Конструктор вектора, инициализирующий матрицу размером 1xN для представления вектора

    // Метод для вычисления скалярного произведения двух векторов
    T dotProduct(const Vector& other) const {
        T sum = 0;                                          // Инициализация суммы для результата
        for (unsigned int i = 0; i < this->n; ++i) {        // Перебор всех элементов вектора
            sum += this->data[0][i] * other.data[0][i];     // Умножение соответствующих элементов и добавление результата в сумму
        }
        return sum; // Возвращение результата скалярного произведения
    }

    // Метод для вычисления векторного произведения двух векторов (определено только для 3D векторов)
    Vector crossProduct(const Vector& other) const {
        if (this->n != 3 || other.n != 3) {                                                 // Проверка, что оба вектора трехмерные
            throw std::invalid_argument("Cross product is defined for 3D vectors only.");   // Исключение, если условие не выполнено
        }
        Vector<T> result(3);                                                                // Создание результата векторного произведения
        
        // Вычисление компонентов векторного произведения согласно формулам
        result.data[0][0] = this->data[0][1] * other.data[0][2] - this->data[0][2] * other.data[0][1];
        result.data[0][1] = this->data[0][2] * other.data[0][1] - this->data[0][1] * other.data[0][2];
        result.data[0][2] = this->data[0][0] * other.data[0][1] - this->data[0][1] * other.data[0][0];
        return result; // Возвращение результата векторного произведения
    }
};

