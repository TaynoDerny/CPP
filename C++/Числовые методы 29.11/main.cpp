#include <iostream>
#include <cmath>

using namespace std;

// Функция для уравнения 1: 2x - 5 ln x - 3 = 0
double f1(double x) {
    return 2*x - 5*log(x) - 3;
}

// Производная для уравнения 1
double df1(double x) {
    return 2 - 5/x;
}

// Вторая производная для уравнения 1
double d2f1(double x) {
    return 5/(x*x);
}

// МЕТОД КАСАТЕЛЬНЫХ (Ньютона)
double newton_method(double a, double b, double epsilon, int& iterations) {
    double x0, x1;
    
    // Выбор начального приближения
    if (f1(a) * d2f1(a) > 0) {
        x0 = a;
    } else {
        x0 = b;
    }
    
    iterations = 0;
    
    do {
        x1 = x0 - f1(x0) / df1(x0);
        iterations++;
             
        if (fabs(x1 - x0) < epsilon) break;
        x0 = x1;
        
    } while (iterations < 1000);
    
    return x1;
}

// МЕТОД ХОРД
double chord_method(double a, double b, double epsilon, int& iterations) {
    double x;
    
    iterations = 0;
    
    if (f1(a) * f1(b) >= 0) {
        cout << "Ошибка: на концах отрезка функция одного знака!" << endl;
        return 0;
    }
    
    do {
        x = (a * f1(b) - b * f1(a)) / (f1(b) - f1(a));
        
        if (f1(a) * f1(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        
        iterations++;
             
    } while (fabs(b - a) > epsilon && iterations < 1000);
    
    return x;
}

// КОМБИНИРОВАННЫЙ МЕТОД
double combined_method(double a, double b, double epsilon, int& iterations) {
    double x_chord, x_tangent;
    
    iterations = 0;
    
    if (f1(a) * f1(b) >= 0) {
        cout << "Ошибка: на концах отрезка функция одного знака!" << endl;
        return 0;
    }
    
    do {
        // Метод хорд
        x_chord = (a * f1(b) - b * f1(a)) / (f1(b) - f1(a));
        
        // Метод касательных
        if (f1(a) * d2f1(a) > 0) {
            x_tangent = a - f1(a) / df1(a);
        } else {
            x_tangent = b - f1(b) / df1(b);
        }
        
        // Сужаем интервал
        if (f1(a) * f1(x_chord) < 0) {
            b = x_chord;
        } else {
            a = x_chord;
        }
        
        if (f1(a) * f1(x_tangent) < 0) {
            b = x_tangent;
        } else {
            a = x_tangent;
        }
        
        iterations++;
        
    } while (fabs(b - a) > epsilon && iterations < 1000);
    
    return (a + b) / 2;
}

int main() {
    cout << "=== РЕШЕНИЕ УРАВНЕНИЯ: 2x - 5 ln x - 3 = 0 ===" << endl << endl;
    
    // Задание 1: Метод касательных с точностью 10^-6
    cout << "--- ЗАДАНИЕ 1: Метод касательных (точность 10^-6) ---" << endl;
    int iter1;
    double root1 = newton_method(0.5, 1.0, 1e-6, iter1);
    cout << "Корень: " << root1 << endl;
    cout << "Итераций: " << iter1 << endl << endl;
    
    // Задание 2: Метод хорд с точностью 10^-3
    cout << "--- ЗАДАНИЕ 2: Метод хорд (точность 10^-3) ---" << endl;
    int iter2;
    double root2 = chord_method(0.5, 1.0, 1e-3, iter2);
    cout << "Корень: " << root2 << endl;
    cout << "Итераций: " << iter2 << endl << endl;
    
    // Задание 3: Комбинированный метод с точностью 10^-6
    cout << "--- ЗАДАНИЕ 3: Комбинированный метод (точность 10^-6) ---" << endl;
    int iter3;
    double root3 = combined_method(0.5, 1.0, 1e-6, iter3);
    cout << "Корень: " << root3 << endl;
    cout << "Итераций: " << iter3 << endl;
    
    return 0;
}