#include "Buffer.cpp"
#include <iostream>
using namespace std;

Buffer makeBuffer(int size) {
    return Buffer(size);
}

int main() {
    cout << "--- конструктор перемещения ---\n";
    Buffer a(10);
    Buffer b(static_cast<Buffer&&>(a));
    cout << "a.size=" << a.size() << ", b.size=" << b.size() << "\n\n";

    cout << "--- перемещающее присваивание ---\n";
    Buffer c(5);
    Buffer d(20);
    d = static_cast<Buffer&&>(c);
    cout << "c.size=" << c.size() << ", d.size=" << d.size() << "\n\n";

    cout << "--- возврат из функции (move/NRVO) ---\n";
    Buffer e = makeBuffer(100);
    cout << "e.size=" << e.size() << "\n\n";

    cout << "--- деструкторы ---\n";
}
