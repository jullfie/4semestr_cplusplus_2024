#pragma once // Предотвращает многократное включение файла заголовка
#include "new_matrices.h" // Подключает определение базового класса Matrix

template<typename T> // Определяет шаблон класса Vector с типом данных T
class Vector : public Matrix<T> { // Наследует от шаблона класса Matrix
public:
    // Конструктор класса Vector. Инициализирует базовый класс Matrix однострочной матрицей.
    Vector(unsigned int n) : Matrix<T>(1, n) {}

    // Метод для вычисления скалярного произведения двух векторов.
    T dotProduct(const Vector& other) const {
        T sum = 0;                                                      // Начальное значение суммы для скалярного произведения 
        for (unsigned int i = 0; i < this->getCols(); ++i) {            // Проходим по всем элементам вектора
            sum += this->at(0, i) * other.at(0, i);                     // Добавляем произведение соответствующих элементов к сумме
        }
        return sum;                             // Возвращаем сумму как результат скалярного произведения
    }

    // Метод для вычисления векторного произведения двух векторов
    Vector crossProduct(const Vector& other) const {

        // Проверяем, что размерность обоих векторов равна 3
        if (this->getCols() != 3 || other.getCols() != 3) {
            throw std::invalid_argument("Cross product is defined for 3D vectors only."); // Генерируем исключение, если векторы не трехмерные
        }

        Vector<T> result(3); // Создаем вектор для результата векторного произведения
        // Вычисляем компоненты результата векторного произведения
        result.at(0, 0) = this->at(0, 1) * other.at(0, 2) - this->at(0, 2) * other.at(0, 1);
        result.at(0, 1) = this->at(0, 2) * other.at(0, 1) - this->at(0, 1) * other.at(0, 2);
        result.at(0, 2) = this->at(0, 0) * other.at(0, 1) - this->at(0, 1) * other.at(0, 0);
        return result; // Возвращаем вектор-результат.
    }
};
