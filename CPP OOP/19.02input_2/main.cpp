#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main() {
    // Демонстрация работы класса
    cout << "=== Работа с дробями ===" << endl;
    
    // Создание дробей
    Fraction f1, f2, result;
    
    cout << "\nВведите первую дробь:" << endl;
    f1.input();
    
    cout << "\nВведите вторую дробь:" << endl;
    f2.input();
    
    // Вывод введенных дробей
    cout << "\nПервая дробь: ";
    f1.display();
    cout << "\nВторая дробь: ";
    f2.display();
    
    // Выполнение операций
    cout << "\n\n=== Результаты операций ===" << endl;
    
    result.add(f1, f2);
    cout << "Сложение: ";
    f1.display();
    cout << " + ";
    f2.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result.subtract(f1, f2);
    cout << "Вычитание: ";
    f1.display();
    cout << " - ";
    f2.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result.multiply(f1, f2);
    cout << "Умножение: ";
    f1.display();
    cout << " * ";
    f2.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result.divide(f1, f2);
    cout << "Деление: ";
    f1.display();
    cout << " / ";
    f2.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    // Сравнение дробей
    cout << "\nСравнение дробей: ";
    if (f1.isEqual(f2)) {
        f1.display();
        cout << " равно ";
        f2.display();
    } else {
        f1.display();
        cout << " не равно ";
        f2.display();
    }
    cout << endl;
    
    return 0;
}