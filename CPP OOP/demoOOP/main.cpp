#include <iostream>
#include <cmath>
#include "Point.cpp"
using namespace std;

int main(){
    // Создание точек
    Point p1;
    Point p2(3.0, 5.0);
    Point p3(p2);
    cout << "Количество точек: " << Point::getCount() << endl;

    // Вывод точек
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3 (копия p2): " << p3 << endl;

    // Сравнение
    if (p2 == p3)
        cout << "p2 и p3 равны" << endl;
    else
        cout << "p2 и p3 не равны" << endl;

    if (p1 != p2)
        cout << "p1 и p2 не равны" << endl;

    // Расстояние от начала координат
    cout << "Расстояние p2 от начала координат: " << p2.distance() << endl;

    // Ввод точки
    cout << "Введите координаты p1 (x y): ";
    cin >> p1;
    cout << "p1 после ввода: " << p1 << endl;

    // Количество после удаления
    {
        Point temp(1.0, 2.0);
        cout << "Количество точек: " << Point::getCount() << endl;
    }
    cout << "Количество точек после удаления temp: " << Point::getCount() << endl;

    return 0;
}
