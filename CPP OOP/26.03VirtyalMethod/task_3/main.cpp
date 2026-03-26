#include <iostream>
#include "StringHolder.h"
#include "ReverseString.h"
using namespace std;

int main() {
    StringHolder* a = new StringHolder("Hello");
    StringHolder* b = new ReverseString("World");

    a->print();
    b->print();

    delete a;
    delete b;

    return 0;
}
