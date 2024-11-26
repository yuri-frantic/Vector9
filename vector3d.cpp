#include "vector3d.h"

// Конструктор по умолчанию
Vector3D::Vector3D() : coords(std::make_unique<double[]>(3)), size(3) {
    coords[0] = 0.0;
    coords[1] = 0.0;
    coords[2] = 0.0;
}

// Конструктор с параметрами
Vector3D::Vector3D(double x, double y, double z) : coords(std::make_unique<double[]>(3)), size(3) {
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
}

// Деструктор
Vector3D::~Vector3D() {}

// Конструктор копирования
Vector3D::Vector3D(const Vector3D& other) : coords(std::make_unique<double[]>(other.size)), size(other.size) {
    std::copy(other.coords.get(), other.coords.get() + size, coords.get());
}

// Оператор присваивания копированием
Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        coords = std::make_unique<double[]>(other.size);
        size = other.size;
        std::copy(other.coords.get(), other.coords.get() + size, coords.get());
    }
    return *this;
}

// Конструктор перемещения
Vector3D::Vector3D(Vector3D&& other) noexcept : coords(std::move(other.coords)), size(other.size) {
    other.size = 0; // Обнуляем размер перемещенного объекта
}

// Оператор присваивания перемещением
Vector3D& Vector3D::operator=(Vector3D&& other) noexcept {
    if (this != &other) {
        coords = std::move(other.coords);
        size = other.size;
        other.size = 0; // Обнуляем размер перемещенного объекта
    }
    return *this;
}

// Печать вектора
void Vector3D::print() const
{
    if (coords)
    {
        std::cout << "Vector: (" << coords[0] << ", " << coords[1] << ", " << coords[2] << ")\n";
    }
    else
    {
        std::cout << "Vector: (" << "None" << ")\n";
    }
}

// Длина вектора
double Vector3D::length() const {
    return std::sqrt(coords[0] * coords[0] + coords[1] * coords[1] + coords[2] * coords[2]);
}

// Нормализация вектора
void Vector3D::normalize() {
    double len = length();
    if (len > 0) {
        for (size_t i = 0; i < size; ++i) {
            coords[i] /= len;
        }
    }
}

// Функция для нормализации вектора через shared_ptr
void normalizeVector(std::shared_ptr<Vector3D> vec) {
    vec->normalize();
}
