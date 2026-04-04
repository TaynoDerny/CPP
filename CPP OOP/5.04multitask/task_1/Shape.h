#pragma once

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;

    Shape(const Shape&) = delete;
    Shape& operator=(const Shape&) = delete;
    Shape(Shape&&) = default;
    Shape& operator=(Shape&&) = default;

    virtual void draw() = 0;
};
