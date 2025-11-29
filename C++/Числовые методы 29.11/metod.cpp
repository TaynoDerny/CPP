#include <iostream>
#include <cmath>

using namespace std;

// Функция для уравнения: x * sin(x) - 1 = 0
double f(double x) {
    return x * sin(x) - 1;
}

// МЕТОД ПОЛОВИННОГО ДЕЛЕНИЯ
double bisection_method(double a, double b, double epsilon) {
    double fa = f(a);
    double fb = f(b);
    
    // Проверка наличия корня на отрезке
    if (fa * fb > 0) {
        cout << "Ошибка: на концах отрезка функция одного знака" << endl;
        return 0;
    }
    
    int iterations = 0;
    double c, fc;
    
    cout << "Метод половинного деления:" << endl;
    cout << "Уравнение: x * sin(x) - 1 = 0" << endl;
    cout << "Начальный отрезок: [" << a << ", " << b << "]" << endl;
    cout << "Точность: " << epsilon << endl << endl;
    
    while (fabs(b - a) > epsilon) {
        c = (a + b) / 2;
        fc = f(c);
        
        iterations++;
        
        cout << "Итерация " << iterations << ":" << endl;
        cout << "  a = " << a << ", f(a) = " << f(a) << endl;
        cout << "  b = " << b << ", f(b) = " << f(b) << endl;
        cout << "  c = " << c << ", f(c) = " << fc << endl;
        cout << "  |b-a| = " << fabs(b - a) << endl << endl;
        
        if (fabs(fc) < epsilon) break;
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    
    cout << "Всего итераций: " << iterations << endl;
    return c;
}

int main() {
    cout << "=== ПРАКТИЧЕСКАЯ РАБОТА №2 ===" << endl;
    cout << "Решение уравнения x * sin(x) - 1 = 0" << endl;
    cout << "Метод половинного деления" << endl;
    cout << "================================" << endl << endl;
    
    // Задание 1: Метод половинного деления с точностью 10^-4
    double root = bisection_method(1.1, 1.2, 1e-4);
    
    cout << "================================" << endl;
    cout << "РЕЗУЛЬТАТ:" << endl;
    cout << "Корень уравнения: " << root << endl;
    cout << "Проверка: f(" << root << ") = " << f(root) << endl;
    
    return 0;
}