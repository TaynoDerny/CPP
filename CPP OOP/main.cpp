#include <iostream>
#include <string>

using namespace std;

class Fraction {
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

    // Вспомогательная функция для нахождения НОД (чтобы сокращать дроби)
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

public:
    // Функция для ввода данных
    void input() {
        cout << "Введите числитель: ";
        cin >> numerator;
        cout << "Введите знаменатель: ";
        cin >> denominator;
        
        if (denominator == 0) {
            cout << "Ошибка: знаменатель не может быть равен 0. Установлено значение 1." << endl;
            denominator = 1;
        }
    }

    // Функция для вывода дроби
    void display() {
        cout << numerator << "/" << denominator;
    }

    // Сложение
    Fraction add(Fraction other) {
        Fraction result;
        result.numerator = (numerator * other.denominator) + (other.numerator * denominator);
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Вычитание
    Fraction subtract(Fraction other) {
        Fraction result;
        result.numerator = (numerator * other.denominator) - (other.numerator * denominator);
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Умножение
    Fraction multiply(Fraction other) {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    // Деление
    Fraction divide(Fraction other) {
        Fraction result;
        if (other.numerator == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return *this; 
        }
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }
};

int main() {
    Fraction a, b, res;

    cout << "Дробь A:" << endl;
    a.input();

    cout << "Дробь B:" << endl;
    b.input();

    cout << "\nРезультаты:" << endl;

    res = a.add(b);
    cout << "Сложение: "; a.display(); cout << " + "; b.display(); cout << " = "; res.display(); cout << endl;

    res = a.multiply(b);
    cout << "Умножение: "; a.display(); cout << " * "; b.display(); cout << " = "; res.display(); cout << endl;

    return 0;
}