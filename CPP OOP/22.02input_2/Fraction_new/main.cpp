#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    
    cout << "=== Тестирование конструкторов класса Fraction ===" << endl;
    
    // Тест конструктора по умолчанию
    cout << "\n1. Создание объекта через конструктор по умолчанию:" << endl;
    Fraction f1;
    cout << "f1 = ";
    f1.display();
    cout << endl;
    
    // Тест конструктора с параметрами
    cout << "\n2. Создание объекта через конструктор с параметрами (3/4):" << endl;
    Fraction f2(3, 4);
    cout << "f2 = ";
    f2.display();
    cout << endl;
    
    // Тест конструктора с параметрами (отрицательная дробь)
    cout << "\n3. Создание объекта через конструктор с параметрами (-2/5):" << endl;
    Fraction f3(-2, 5);
    cout << "f3 = ";
    f3.display();
    cout << endl;
    
    // Тест конструктора копирования
    cout << "\n4. Создание объекта через конструктор копирования (f4 = f2):" << endl;
    Fraction f4(f2);
    cout << "f4 = ";
    f4.display();
    cout << endl;
    
    // Тест сокращения дроби
    cout << "\n5. Проверка автоматического сокращения (6/8 -> 3/4):" << endl;
    Fraction f5(6, 8);
    cout << "f5 = ";
    f5.display();
    cout << endl;
    
    // Демонстрация работы с дробями
    cout << "\n=== Демонстрация арифметических операций ===" << endl;
    
    Fraction a, b, result;
    
    cout << "\nВведите первую дробь:" << endl;
    a.input();
    
    cout << "\nВведите вторую дробь:" << endl;
    b.input();
    
    cout << "\nПервая дробь: ";
    a.display();
    cout << "\nВторая дробь: ";
    b.display();
    
    cout << "\n\n=== Результаты операций ===" << endl;
    
    result = a.add(b);
    cout << "Сложение: ";
    a.display();
    cout << " + ";
    b.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result = a.subtract(b);
    cout << "Вычитание: ";
    a.display();
    cout << " - ";
    b.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result = a.multiply(b);
    cout << "Умножение: ";
    a.display();
    cout << " * ";
    b.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    result = a.divide(b);
    cout << "Деление: ";
    a.display();
    cout << " / ";
    b.display();
    cout << " = ";
    result.display();
    cout << endl;
    
    // Сравнение дробей
    cout << "\nСравнение дробей: ";
    if (a.isEqual(b)) {
        a.display();
        cout << " равно ";
        b.display();
    } else {
        a.display();
        cout << " не равно ";
        b.display();
    }
    cout << endl;
    
    // Демонстрация перегруженных операторов
    cout << "\n=== Демонстрация перегруженных операторов ===" << endl;
    Fraction f6(1, 2);
    Fraction f7(1, 3);
    
    cout << "f6 = ";
    f6.display();
    cout << "\nf7 = ";
    f7.display();
    
    cout << "\n\nf6 + f7 = ";
    (f6 + f7).display();
    
    cout << "\nf6 - f7 = ";
    (f6 - f7).display();
    
    cout << "\nf6 * f7 = ";
    (f6 * f7).display();
    
    cout << "\nf6 / f7 = ";
    (f6 / f7).display();
    
    cout << "\n\nf6 == f7? " << ((f6 == f7) ? "Да" : "Нет") << endl;
    
    cout << "\n=== Деструкторы будут вызваны автоматически ===" << endl;
    
    return 0;
}