#pragma once
#include "Drawable.h"
#include "Serializable.h"

class Circle : public Drawable, public Serializable {
    int x, y, r;
public:
    Circle(int x, int y, int r);
    void draw() const override;
    string serialize() const override;
};
