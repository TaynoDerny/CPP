#include "complex.cpp"

using namespace std;

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;

    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    cout << "Модуль c1: " << c1() << endl;

    cout << "Введите комплексное число (real imag): ";
    cin >> c3;
    cout << "Вы ввели: " << c3 << endl;

    return 0;
}
