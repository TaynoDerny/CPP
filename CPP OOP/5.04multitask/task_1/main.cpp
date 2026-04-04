#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

void identifyAndDraw(Shape* s){
    if (Circle* c = dynamic_cast<Circle*>(s)){
        cout << "Тип: Круг | " << endl;
        c->draw();
    }
    else if (Rectangle* r = dynamic_cast<Rectangle*>(s)){
        cout << "Тип: Прямоугольник | " << endl;
        r->draw();
    }
    else{
        cout << "Неизвестная фигура" << endl;
    }

}

int main(){
    Shape* shapes[] = {
        new Circle(),
        new Rectangle(),
        new Circle(),
        new Rectangle()
    };

    for (Shape* s : shapes)
    {
        identifyAndDraw(s);
    }
    for (Shape* s : shapes)
    {
        delete s;
    }
    

    return 0;
}