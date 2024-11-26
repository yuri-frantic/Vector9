#include <iostream>
#include "vector3d.h"

int main() {
    // Создание векторов с использованием конструктора
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(v1); // Копирование v1 в v2

    std::cout << "Оригинальные вектор v1 и его копия:\n";
    v1.print();
    v2.print();

    // Изменение v1 и проверка v2 (должен остаться неизменным)
    v1 = Vector3D(4.0, 5.0, 6.0);
    
    std::cout << "После изменения v1:\n";
    v1.print();
    v2.print();

    // Использование перемещения
    Vector3D v3(std::move(v1));
    
    std::cout << "После перемещения v1 в v3:\n";
    v1.print(); // v1 теперь должен быть пустым или неинициализированным
    v3.print();

    // Использование shared_ptr
    std::shared_ptr<Vector3D> vecPtr = std::make_shared<Vector3D>(7.0, 8.0, 9.0);
    
    std::cout << "До нормализации:\n";
    vecPtr->print();
    
    normalizeVector(vecPtr); // Нормализация через shared_ptr
    
    std::cout << "После нормализации:\n";
    vecPtr->print();

    return 0;
}

