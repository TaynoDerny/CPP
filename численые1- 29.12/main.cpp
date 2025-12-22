#include <iostream>
#include <cmath>

using namespace std;

// Функции f1 и f2 на основе твоего примера уравнения 2-го порядка
// y' = z
double f1(double x, double y, double z) {
    return z;
}

// z' = 1.75 * (z / x^3) - (y / 2x^4)
double f2(double x, double y, double z) {
    return 1.75 * (z / pow(x, 3)) - (y / (2.0 * pow(x, 4)));
}

// 1. Блок-схема метода Эйлера (адаптировано под систему)
void euler(double x0, double y0, double z0, double h, int n) {
    cout << "\n--- Метод Эйлера ---\n";
    for (int i = 0; i < n; i++) {
        cout << "шаг " << i << ": x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
        double k = f1(x0, y0, z0);
        double l = f2(x0, y0, z0);
        
        y0 = y0 + h * k;
        z0 = z0 + h * l;
        x0 = x0 + h;
    }
    cout << "итог: x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
}

// 2. Блок-схема метода Эйлера-Коши
void eulerCauchy(double x0, double y0, double z0, double h, int n) {
    cout << "\n--- Метод Эйлера-Коши ---\n";
    for (int i = 0; i < n; i++) {
        cout << "шаг " << i << ": x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
        
        double k1 = f1(x0, y0, z0);
        double l1 = f2(x0, y0, z0);
        
        double x_next = x0 + h;
        double y_pred = y0 + h * k1;
        double z_pred = z0 + h * l1;
        
        y0 = y0 + (h / 2.0) * (k1 + f1(x_next, y_pred, z_pred));
        z0 = z0 + (h / 2.0) * (l1 + f2(x_next, y_pred, z_pred));
        x0 = x_next;
    }
    cout << "итог: x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
}


void rungeKutta(double x0, double y0, double z0, double h, int n) {
    cout << "\n--- Метод Рунге-Кутта 4 порядка ---\n";
    for (int i = 0; i < n; i++) {
        cout << "шаг " << i << ": x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
        
        double k1 = h * f1(x0, y0, z0);
        double l1 = h * f2(x0, y0, z0);
        
        double k2 = h * f1(x0 + h / 2.0, y0 + k1 / 2.0, z0 + l1 / 2.0);
        double l2 = h * f2(x0 + h / 2.0, y0 + k1 / 2.0, z0 + l1 / 2.0);
        
        double k3 = h * f1(x0 + h / 2.0, y0 + k2 / 2.0, z0 + l2 / 2.0);
        double l3 = h * f2(x0 + h / 2.0, y0 + k2 / 2.0, z0 + l2 / 2.0);
        
        double k4 = h * f1(x0 + h, y0 + k3, z0 + l3);
        double l4 = h * f2(x0 + h, y0 + k3, z0 + l3);
        
        y0 = y0 + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        z0 = z0 + (1.0 / 6.0) * (l1 + 2.0 * l2 + 2.0 * l3 + l4);
        x0 = x0 + h;
    }
    cout << "итог: x=" << x0 << " y=" << y0 << " z=" << z0 << endl;
}

int main() {
 
    double x0 = 2.0;
    double y0 = 4.5;
    double z0 = 3.2;
    double h = 0.1;
    int n = 10;
    
    int choice;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Метод Эйлера\n";
        cout << "2. Метод Эйлера-Коши\n";
        cout << "3. Метод Рунге-Кутта 4 порядка\n";
        cout << "0. Выход\n";
        cout << "Выберите метод: ";
        cin >> choice;
        
        if (choice == 1) euler(x0, y0, z0, h, n);
        else if (choice == 2) eulerCauchy(x0, y0, z0, h, n);
        else if (choice == 3) rungeKutta(x0, y0, z0, h, n);
        
    } while (choice != 0);
    
    return 0;
}