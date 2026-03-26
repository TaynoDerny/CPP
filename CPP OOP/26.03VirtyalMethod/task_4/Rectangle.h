#pragma once
#include "Drawable.h"
#include "Serializable.h"

class Rectangle : public Drawable, public Serializable {
    int x, y, w, h;
public:
    Rectangle(int x, int y, int w, int h);
    void draw() const override;
    string serialize() const override;
};
