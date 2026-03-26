#pragma once
using namespace std;

class Drawable {
public:
    virtual ~Drawable() = default;
    virtual void draw() const = 0;
};
