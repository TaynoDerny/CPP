#include <iostream>
#include <vector>
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Triangle.cpp"

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));

    for (Shape* s : shapes) {
        s->printInfo();
        std::cout << "\n";
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
