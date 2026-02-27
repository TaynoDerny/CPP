#pragma once

namespace std { // Мы не будем использовать using namespace std в заголовочных файлах
}

class ShapeArea {
private:
    static int count; // Счетчик подсчетов площади

public:
    // Статические методы для подсчета площади
    
    // Площадь треугольника по формуле Герона (по трем сторонам)
    static double triangleHeron(double a, double b, double c);
    
    // Площадь треугольника по основанию и высоте
    static double triangleBaseHeight(double base, double height);
    
    // Площадь треугольника по двум сторонам и углу между ними (в градусах)
    static double triangleTwoSidesAngle(double side1, double side2, double angleDegrees);
    
    // Площадь прямоугольника
    static double rectangle(double length, double width);
    
    // Площадь квадрата
    static double square(double side);
    
    // Площадь ромба по диагоналям
    static double rhombusDiagonals(double diagonal1, double diagonal2);
    
    // Площадь ромба по стороне и высоте
    static double rhombusSideHeight(double side, double height);
    
    // Площадь ромба по стороне и углу (в градусах)
    static double rhombusSideAngle(double side, double angleDegrees);
    
    // Получить количество подсчетов площади
    static int getCount();
    
    // Сбросить счетчик
    static void resetCount();
};

