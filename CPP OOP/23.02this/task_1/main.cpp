#include <iostream>
#include "fraction.cpp"

using namespace std;

int main() {
    cout << "=== Демонстрация класса Fraction ===\n\n";
    
    Fraction f1(3, 4);
    Fraction f2(2, 5);
    
    cout << "f1 = "; f1.display(); cout << endl;
    cout << "f2 = "; f2.display(); cout << endl;
    
    cout << "\nЦепочка операций:\n";
    cout << "f1.add(f2).multiply(2).subtract(1)\n";
    cout << "Результат: ";
    
    // ВАРИАНТ 1: Разбиваем на отдельные операции
    f1.add(f2)->multiply(2)->subtract(1)->display();
    cout << endl;
    
    // ВАРИАНТ 2: Или можно так (более наглядно)
    Fraction f3(3, 4);
    cout << "\nТот же результат пошагово:\n";
    cout << "f3 = "; f3.display(); cout << endl;
    f3.add(f2);
    cout << "После add(f2): "; f3.display(); cout << endl;
    f3.multiply(2);
    cout << "После multiply(2): "; f3.display(); cout << endl;
    f3.subtract(1);
    cout << "После subtract(1): "; f3.display(); cout << endl;
    
    Fraction f4(12, 18);
    cout << "\nf4 = 12/18 (после сокращения): ";
    f4.display();
    cout << endl;
    
    return 0;
}