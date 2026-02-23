#include "Point.h"

// Конструктор по умолчанию с инициализатором
Point::Point() : x(0), y(0), z(0) {
    cout << "Конструктор Point по умолчанию" << endl;
}

// Конструктор с параметрами с инициализатором
Point::Point(int X, int Y, int Z) : x(X), y(Y), z(Z) {
    cout << "Конструктор Point с параметрами" << endl;
}

// Конструктор копирования с инициализатором
Point::Point(const Point& other) : x(other.x), y(other.y), z(other.z) {
    cout << "Конструктор копирования Point" << endl;
}

// Деструктор
Point::~Point() {
    cout << "Деструктор Point" << endl;
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