#include "Circle.h"

namespace Geometry {

    double circleArea(double radius) {
        return PI * radius * radius;
    }

    double rectangleArea(double width, double height) {
        return width * height;
    }

    namespace Shapes {

        double Circle::area() {
            return Geometry::circleArea(radius);
        }

    } // namespace Shapes

} // namespace Geometry
