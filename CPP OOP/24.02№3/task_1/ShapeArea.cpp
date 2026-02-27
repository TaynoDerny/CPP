#include "ShapeArea.h"
#include <cmath>
#include <iostream>
using namespace std;

// Инициализация статической переменной
int ShapeArea::count = 0;

// Площадь треугольника по формуле Герона
double ShapeArea::triangleHeron(double a, double b, double c) {
    count++;
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Площадь треугольника по основанию и высоте
double ShapeArea::triangleBaseHeight(double base, double height) {
    count++;
    return 0.5 * base * height;
}

// Площадь треугольника по двум сторонам и углу между ними
double ShapeArea::triangleTwoSidesAngle(double side1, double side2, double angleDegrees) {
    count++;
    double angleRadians = angleDegrees * M_PI / 180.0;
    return 0.5 * side1 * side2 * sin(angleRadians);
}

// Площадь прямоугольника
double ShapeArea::rectangle(double length, double width) {
    count++;
    return length * width;
}

// Площадь квадрата
double ShapeArea::square(double side) {
    count++;
    return side * side;
}

// Площадь ромба по диагоналям
double ShapeArea::rhombusDiagonals(double diagonal1, double diagonal2) {
    count++;
    return (diagonal1 * diagonal2) / 2.0;
}

// Площадь ромба по стороне и высоте
double ShapeArea::rhombusSideHeight(double side, double height) {
    count++;
    return side * height;
}

// Площадь ромба по стороне и углу
double ShapeArea::rhombusSideAngle(double side, double angleDegrees) {
    count++;
    double angleRadians = angleDegrees * M_PI / 180.0;
    return side * side * sin(angleRadians);
}

// Получить количество подсчетов площади
int ShapeArea::getCount() {
    return count;
}

// Сбросить счетчик
void ShapeArea::resetCount() {
    count = 0;
}