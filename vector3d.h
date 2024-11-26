#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <memory>
#include <cmath>

class Vector3D {
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    // Конструктор копирования
    Vector3D(const Vector3D& other);
    // Оператор присваивания копированием
    Vector3D& operator=(const Vector3D& other);

    // Конструктор перемещения
    Vector3D(Vector3D&& other) noexcept;
    // Оператор присваивания перемещением
    Vector3D& operator=(Vector3D&& other) noexcept;

    void print() const;
    double length() const;
    void normalize();

private:
    std::unique_ptr<double[]> coords; // Динамический массив для хранения координат
    size_t size; // Размер массива (всегда 3 для 3D вектора)
};

void normalizeVector(std::shared_ptr<Vector3D> vec);

#endif // VECTOR3D_H
