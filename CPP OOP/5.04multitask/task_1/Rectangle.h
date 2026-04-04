#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle() = default;
    ~Rectangle() override = default;
    void draw() override;
};

