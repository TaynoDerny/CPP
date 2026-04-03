#include <iostream>
#include "Circle.cpp"

using namespace std;

int main() {
    //Полная квалификация
    double area1 = Geometry::circleArea(5.0);
    cout << "Circle area (r=5): " << area1 << "\n";

    double area2 = Geometry::rectangleArea(4.0, 6.0);
    cout << "Rectangle area (4x6): " << area2 << "\n";

    //using-объявление для конкретного символа
    using Geometry::rectangleArea;
    cout << "Rectangle area (3x7): " << rectangleArea(3.0, 7.0) << "\n";

    //использование класса Circle из вложенного namespace
    Geometry::Shapes::Circle c(10.0);
    cout << "Circle area (r=10): " << c.area() << "\n";

    // using-объявление для класса
    using Geometry::Shapes::Circle;
    Circle c2(2.5);
    cout << "Circle area (r=2.5): " << c2.area() << "\n";

    //  Прямой доступ к константе
    cout << "PI = " << Geometry::PI << "\n";

    return 0;
}
