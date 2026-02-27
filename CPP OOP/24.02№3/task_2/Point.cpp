#include "Point.h"

// Инициализация статического счетчика
int Point::count = 0;

// Конструктор по умолчанию делегирует конструктору с параметрами
Point::Point() : Point(0, 0, 0) {
    cout << "Конструктор Point по умолчанию (делегирование)" << endl;
}

// Конструктор с параметрами
Point::Point(int X, int Y, int Z) : x(X), y(Y), z(Z) {
    count++;  // Увеличиваем счетчик при создании
    cout << "Конструктор Point с параметрами. Всего объектов: " << count << endl;
}

// Конструктор копирования делегирует конструктору с параметрами
Point::Point(const Point& other) : Point(other.x, other.y, other.z) {
    cout << "Конструктор копирования Point (делегирование)" << endl;
}

// Деструктор
Point::~Point() {
    count--;  // Уменьшаем счетчик при удалении
    cout << "Деструктор Point. Осталось объектов: " << count << endl;
}

void Point::PrintPoint() const {
    cout << "Координаты точки: " << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << "Z: " << z << endl;
}

bool Point::SaveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return false;
    }
    
    file << x << " " << y << " " << z;
    file.close();
    cout << "Точка сохранена в файл " << filename << endl;
    return true;
}

bool Point::LoadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return false;
    }
    
    file >> x >> y >> z;
    file.close();
    cout << "Точка загружена из файла " << filename << endl;
    return true;
}