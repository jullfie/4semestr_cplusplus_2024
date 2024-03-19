#pragma once
#ifndef new_matrices_h
#define new_matrices_h

#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>

// Объявление шаблонного класса Matrix для работы с матрицами произвольного типа данных
template <typename T>
class Matrix {
private:
    unsigned int m;         // Количество строк в матрице
    unsigned int n;         // Количество столбцов в матрице
    T** data;               // Двумерный массив для хранения элементов матрицы

public:

    // Функция доступа к элементам матрицы   // т.к. была проблема инкапсуляции (досутп у ветора data. который наследуется из матриц)
    T& at(unsigned int row, unsigned int col) {
        if (row >= m || col >= n) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }
    // Для константной версии
    const T& at(unsigned int row, unsigned int col) const {
        if (row >= m || col >= n) {
            throw std::out_of_range("Index out of range");
        }
        return data[row][col];
    }

    // Методы для получения размеров матрицы
    unsigned int getRows() const { return m; }
    unsigned int getCols() const { return n; }


    // Конструктор для инициализации матрицы заданным количеством строк и столбцов
    Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = new T * [m];                                      // Выделение памяти для строк
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new T[n];                                  // Выделение памяти для столбцов в каждой строке
        }
    }

    // Деструктор для освобождения выделенной памяти
    ~Matrix() {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];                   // Освобождение памяти столбцов
        }
        delete[] data;                          // Освобождение памяти строк
    }

    // Оператор вывода матрицы в поток
    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            os << " " << std::endl;
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << std::setw(3) << matrix.data[i][j] << " | ";
            }
            os << '\n';
        }
        return os;
    }

    // Оператор индексации для доступа к строкам матрицы
    T*& operator[](unsigned int index) {
        return data[index];
    }

    // Метод для заполнения матрицы случайными числами
    void fillRandom() {
        static bool seeded = false;
        if (!seeded) {
            srand(time(0));                                 // Инициализация генератора случайных чисел
            seeded = true;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = static_cast<T>(rand() % 10);   // Заполнение элементов матрицы
            }
        }
    }

    // Метод для заполнения матрицы нулями
    void fillZeros() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = static_cast<T>(0);
            }
        }
    }

    // Оператор присваивания сложения: добавляет элементы другой матрицы к текущей матрице
    Matrix& operator+=(const Matrix& other) {

        // Проходим по всем элементам матрицы
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];         // Прибавляем элементы матрицы other к соответствующим элементам текущей матрицы
            }
        }
        return *this;           // Возвращаем измененную матрицу
    }

    // Оператор сложения: возвращает новую матрицу, являющуюся результатом сложения текущей матрицы и other
    Matrix operator+(const Matrix& other) const {

        // Создаем новую матрицу для результата
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {                          // Проходим по всем элементам матриц
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];      // Складываем элементы двух матриц и сохраняем результат в новой матрице
            }
        }
        return result;
    }

    // Оператор присваивания вычитания: вычитает элементы другой матрицы из текущей матрицы
    Matrix& operator-=(const Matrix& other) {

        // Проходим по всем элементам матрицы
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];     // Вычитаем элементы матрицы other из соответствующих элементов текущей матрицы
            }
        }
        return *this;       //  Возвращаем измененную матрицу
    }

    // Оператор вычитания: возвращает новую матрицу, являющуюся результатом вычитания матрицы other из текущей матрицы
    Matrix operator-(const Matrix& other) const {

        // Создаем новую матрицу для результата
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {      // Проходим по всем элементам матриц
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];  // Вычитаем элементы матрицы other из соответствующих элементов текущей матрицы и сохраняем результат в новой матрице
            }
        }
        return result;
    }

    // Оператор умножения: возвращает новую матрицу, являющуюся результатом умножения текущей матрицы на матрицу other
    Matrix operator*(const Matrix& other) const {

        // Создаем новую матрицу для результата с количеством строк текущей матрицы и столбцов матрицы other
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {              // Инициализируем элементы результата нулями
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = static_cast<T>(0);
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];     // Вычисляем элементы результата как сумму произведений элементов строки текущей матрицы на столбец матрицы other
                }
            }
        }
        return result;      // Возвращаем результат умножения
    }

    // Оператор сравнения на равенство: проверяет, равны ли текущая матрица и матрица other
    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {         // Сначала проверяем, совпадают ли размеры матриц
            return false;                           // Размеры разные, матрицы не равны
        }
        // Проверяем все элементы на равенство
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;                  // Найдено несовпадение элементов, матрицы не равны
                }
            }
        }
        return true;  // Все элементы совпадают, матрицы равны
    }

    // Оператор сравнения на неравенство: проверяет, отличается ли текущая матрица от матрицы other
    bool operator!=(const Matrix& other) const {
        return !(*this == other);                  // Используем оператор сравнения на равенство и инвертируем его результат
    }

};

#endif  // new_matrices.h
