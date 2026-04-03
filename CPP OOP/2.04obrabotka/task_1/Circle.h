#pragma once

namespace Geometry {

    const double PI = 3.14159;

    double circleArea(double radius);
    double rectangleArea(double width, double height);

    namespace Shapes {

        class Circle {
        public:
            double radius;
            Circle(double r) : radius(r) {}
            double area();
        };
    } 
} 
