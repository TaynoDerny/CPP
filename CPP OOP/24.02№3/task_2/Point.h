#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Point
{
private:
    int x;
    int y;
    int z;
    static int count;  // Статический счетчик объектов
    
public:
    // Конструкторы с делегированием
    Point();                                // Конструктор по умолчанию
    Point(int X, int Y, int Z);              // Конструктор с параметрами
    Point(const Point& other);               // Конструктор копирования
    
    // Деструктор
    ~Point();
    
    // inline методы
    inline int GetX() const { return x; }
    inline int GetY() const { return y; }
    inline int GetZ() const { return z; }
    
    inline void SetX(int X) { x = X; }
    inline void SetY(int Y) { y = Y; }
    inline void SetZ(int Z) { z = Z; }
    
    // Статический метод для получения количества объектов
    static inline int GetCount() { return count; }
    
    void PrintPoint() const;
    bool SaveToFile(const string& filename) const;
    bool LoadFromFile(const string& filename);
};