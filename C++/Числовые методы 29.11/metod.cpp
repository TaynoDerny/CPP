#include <iostream>
#include <cmath>

using namespace std;

// Функция : (0,2x)^3 = cos x
double f(double x) {
    return pow(0.2 * x, 3) - cos(x);
}

// МЕТОД ПОЛОВИННОГО ДЕЛЕНИЯ
double bisection_method(double a, double b, double e) {
    double fa = f(a);
    double fb = f(b);
    
    if (fa * fb > 0) {
        cout << "Ошибка: на концах отрезка функция одного знака!" << endl;
        return 0;
    }
    
    int iterations = 0;
    double c;
    
    while (fabs(b - a) > e) {
        c = (a + b) / 2;
        iterations++;
        
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    cout << "Итераций: " << iterations << endl;
    return (a + b) / 2;
}

int main() {
    cout << "=== РЕШЕНИЕ УРАВНЕНИЯ (0,2x)^3 = cos x ===" << endl;
    cout << "Метод половинного деления" << endl;
    cout << "Промежуток: [1.5, 1.6]" << endl;
    cout << "Точность: 10^-5" << endl << endl;
    
    double root = bisection_method(1.5, 1.6, 1e-5);
    
    cout << "Корень: " << root << endl;
    
    return 0;
}