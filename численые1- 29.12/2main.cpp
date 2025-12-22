#include <iostream>
#include <cmath>

using namespace std;


// Первая функция f1(x, y, z)
double f1(double x, double y, double z) {
    // Пример: y' = z
    return z; 
}

// Вторая функция f2(x, y, z)
double f2(double x, double y, double z) {
    // Пример: z' = -y
    return -y; 
}

// Функция метода Рунге-Кутты для системы 
void rungeKuttaSystem(double x0, double y0, double z0, double h, int n) {
    double x = x0;
    double y = y0;
    double z = z0;

    // Коэффициенты для y
    double k1, k2, k3, k4;
    // Коэффициенты для z 
    double L1, L2, L3, L4;

    cout << "\n--- Решение системы ОДУ методом Рунге-Кутты 4 порядка ---\n";
    cout << "Шаг\tX\t\tY\t\tZ\n";
    cout << "0\t" << x << "\t\t" << y << "\t\t" << z << endl;

    for (int i = 1; i <= n; ++i) {
        // 1. Расчет k1 и L1
        k1 = h * f1(x0, y0, z0);
        L1 = h * f2(x0, y0, z0);

        // 2. Расчет k2 и L2
        k2 = h * f1(x0 + h / 2.0, y0 + k1 / 2.0, z0 + L1 / 2.0);
        L2 = h * f2(x0 + h / 2.0, y0 + k1 / 2.0, z0 + L1 / 2.0);

        // 3. Расчет k3 и L3
        k3 = h * f1(x0 + h / 2.0, y0 + k2 / 2.0, z0 + L2 / 2.0);
        L3 = h * f2(x0 + h / 2.0, y0 + k2 / 2.0, z0 + L2 / 2.0);

        // 4. Расчет k4 и L4
        k4 = h * f1(x0 + h, y0 + k3, z0 + L3);
        L4 = h * f2(x0 + h, y0 + k3, z0 + L3);


        y = y0 + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        z = z0 + (1.0 / 6.0) * (L1 + 2 * L2 + 2 * L3 + L4);
        

        x = x0 + h;


        cout << i << "\t" << x << "\t\t" << y << "\t\t" << z << endl;

        x0 = x;
        y0 = y;
        z0 = z;
    }
}

int main() {
    setlocale(LC_ALL, "ru"); 

    double x0, y0, z0, h;
    int n;

    cout << "Введите начальное условие x0: ";
    cin >> x0;
    cout << "Введите начальное условие y0: ";
    cin >> y0;
    cout << "Введите начальное условие z0: ";
    cin >> z0;
    cout << "Введите количество шагов (n): ";
    cin >> n;
    cout << "Введите шаг (h): ";
    cin >> h;


    rungeKuttaSystem(x0, y0, z0, h, n);

    return 0;
}