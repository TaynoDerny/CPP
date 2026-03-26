#include <iostream>
#include <vector>
#include "Circle.cpp"
#include "Rectangle.cpp"
using namespace std;

int main() {
    Circle c(10, 20, 5);
    Rectangle rect(0, 0, 30, 15);

    vector<Drawable*> drawables = { &c, &rect };
    for (Drawable* d : drawables)
        d->draw();

    cout << "\n";

    vector<Serializable*> serializables = { &c, &rect };
    for (Serializable* s : serializables)
        cout << "Serialized: " << s->serialize() << "\n";

    return 0;
}
