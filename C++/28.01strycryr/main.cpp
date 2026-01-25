#include <iostream>
#include <string>

using namespace std;


// прямоугольник координаты угла и размеры
struct Rectangle {
    int x, y, width, height;
};

// точка на плоскости
struct Point {
    double x, y;
};

//  простая дробь 
struct Fraction {
    int num, den;
};

// Задание 1 (Прямоугольник) 

// Вывод текущих координат и размеров прямоугольника 
void printRect(Rectangle r) {
    cout << "\n[Прямоугольник] Координаты: (" << r.x << ", " << r.y << "), Размер: " << r.width << "x" << r.height << endl;
}

// Задание 2 (Точка) 

// квадратный корень числа методом итераций 
double my_sqrt(double n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    double x = n, y = 1;
    for (int i = 0; i < 20; i++) { 
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

// Задание 3 (Дроби) 

// Нахождение наибольшего общего делителя для сокращения дроби
int gcd(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b) { a %= b; swap(a, b); }
    return a;
}

// Сокращение дроби
void simplify(Fraction &f) {
    if (f.den == 0) return;
    int common = gcd(f.num, f.den);
    f.num /= common;
    f.den /= common;
    if (f.den < 0) { f.num = -f.num; f.den = -f.den; }
}

// Вывывод дроби
void printFraction(Fraction f) {
    simplify(f);
    if (f.den == 0) { cout << "Ошибка (знаменатель 0)"; return; }
    if (f.num == 0) { cout << "0"; return; }

    int whole = f.num / f.den; // Целая часть
    int rem = (f.num % f.den < 0) ? -(f.num % f.den) : (f.num % f.den); // Остаток

    if (whole != 0) {
        cout << whole;
        if (rem != 0) cout << " [" << rem << "/" << f.den << "]";
    } else {
        cout << f.num << "/" << f.den;
    }
    cout << endl;
}

//   МЕНЮ 

int main() {
    int choice;

    while (true) {
        cout << "\n   МЕНЮ " << endl;
        cout << "1. Задание 1: Прямоугольник (движение и размер)" << endl;
        cout << "2. Задание 2: Точки (расстояние)" << endl;
        cout << "3. Задание 3: Дроби (арифметика)" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                Rectangle r;
                cout << "Введите начальные X Y: "; cin >> r.x >> r.y;
                cout << "Введите начальные Ширину и Высоту: "; cin >> r.width >> r.height;
                printRect(r);

                int dx, dy;
                cout << "Введите смещение (dx dy): "; cin >> dx >> dy;
                r.x += dx; r.y += dy; // Логика перемещения
                cout << "После перемещения:";
                printRect(r);

                int nw, nh;
                cout << "Введите новые размеры (W H): "; cin >> nw >> nh;
                r.width = nw; r.height = nh; // Логика изменения размера
                cout << "После изменения размера:";
                printRect(r);
                break;
            }
            case 2: {
                Point p1, p2;
                cout << "Координаты точки A (x y): "; cin >> p1.x >> p1.y;
                cout << "Координаты точки B (x y): "; cin >> p2.x >> p2.y;
                // Теорема Пифагора для поиска расстояния
                double dist = my_sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
                cout << "Расстояние между A и B: " << dist << endl;
                break;
            }
            case 3: {
                Fraction f1, f2, res;
                char choiceVer;
                cout << "Дробь 1 (числ знам): "; cin >> f1.num >> f1.den;
                cout << "Действие (/, *, +, -,): "; cin >>choiceVer;
                cout << "Дробь 2 (числ знам): "; cin >> f2.num >> f2.den;

                switch (choiceVer)
                {
                case '+':
                    cout << "Сумма: ";
                    res.num = f1.num * f2.den + f2.num * f1.den;
                    res.den = f1.den * f2.den;
                    printFraction(res);
                    break;
                case '-':
                    cout << "Разность: ";
                    res.num = f1.num * f2.den - f2.num * f1.den;
                    res.den = f1.den * f2.den;
                    printFraction(res);
                    break;
                case '*':
                    cout << "Умножение: ";
                    res.num = f1.num * f2.num;
                    res.den = f1.den * f2.den;
                    printFraction(res);
                    break;
                case '/':
                    cout << "Деление: ";
                    res.num = f1.num * f2.den;
                    res.den = f1.den * f2.num;
                    printFraction(res);
                    break;
                default:
                    break;
                }
                break;
            }
            default:
                cout << "Ошибка: выберите пункт от 0 до 3!" << endl;
        }
    }
    return 0;
}