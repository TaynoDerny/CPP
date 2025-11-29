#include <iostream>
#include <cmath>

using namespace std;

// Функция для  F(x) = 2lg(x+7) - 5sin(x)
double F(double x) {
    return 2 * log10(x + 7) - 5 * sin(x);
}




// Производная функции F'(x)
double F_derivative(double x) {
    return (2 / ((x + 7) * log(10))) - 5 * cos(x);
}

// Вторая производная функции F''(x)
double F_second_derivative(double x) {
    return (-2 / ((x + 7) * (x + 7) * log(10))) + 5 * sin(x);
}





// Метод касательных 
double newton_method(double a, double b, double e) {
    double x0;
    if (F(a) * F(b) < 0) {
        x0 = (F(a) < 0) ? a : b;
    } else {
        x0 = a;
    }
    
    double x = x0;
    int iter = 0;
    
    while (iter < 100) {
        double x_new = x - F(x) / F_derivative(x);
        
        if (fabs(x_new - x) < e) {
            cout << "Найден корень за " << iter << " итераций" << endl;
            return x_new;
        }
        
        x = x_new;
        iter++;
    }
    
    return x;
}

// метод хорд
double chord_method_simple(double a, double b, double e) {
    double x0, c;
    

    double F_a = F(a);
    double F_b = F(b);
    
    if (F_a < 0) {
        x0 = a;
        c = b;
    } else {
        x0 = b;
        c = a;
    }
    
    double x_prev = x0;
    double x_current;
    
    do {
        x_current = (x_prev * F(c) - c * F(x_prev)) / (F(c) - F(x_prev));
        
        if (fabs(x_current - x_prev) <= e) {
            break;
        }
        
        x_prev = x_current;
    } while (true);
    
    return x_current;
}


// Комбинированный метод хорд и касательных
double combined_method_simple(double a, double b, double eps) {
    double x0, x1, c;
    
    double F_a = F(a);
    double F_second_a = F_second_derivative(a);
    
    if (F_a * F_second_a < 0) {
        x0 = a; x1 = b; c = b;
    } else {
        x0 = b; x1 = a; c = a;
    }
    
    double x_chord = x0;
    double x_tangent = x1;
    
    for (int i = 0; i < 100; i++) {
        x_chord = (x_chord * F(c) - c * F(x_chord)) / (F(c) - F(x_chord));
        x_tangent = x_tangent - F(x_tangent) / F_derivative(x_tangent);
        
        if (fabs(x_tangent - x_chord) < 2 * eps) {
            break;
        }
    }
    
    return (x_chord + x_tangent) / 2.0;
}

int main() {
    double a = 2.7;
    double b = 2.8;
    double e = 0.000001;
    
    double method = chord_method_simple(a, b, e);
    
    cout << "Метод хорд"<<endl;
    cout << "Решение уравнения: 2lg(x+7) - 5sin(x) = 0" << endl;
    cout << "Интервал: [" << a << ", " << b << "]" << endl;
    cout << "Точность: " << e << endl;
    cout << "Найденный корень: " << method << endl;

    cout <<endl<< "Метод касательных"<<endl;
    cout << "Уравнение: 2lg(x+7) - 5sin(x) = 0" << endl;
    cout << "Интервал: " << a << " до " << b << endl;
    method = newton_method(a, b, e);
    cout << "Корень: " << method << endl;

    cout << endl << "Комбинированный метод" << endl;
    cout << "Уравнение: 2lg(x+7) - 5sin(x) = 0" << endl;
    cout << "Интервал: " << a << " до " << b << endl;
    method = combined_method_simple(a, b, e);
    cout << "Корень: " << method << endl;

    


    return 0;
}