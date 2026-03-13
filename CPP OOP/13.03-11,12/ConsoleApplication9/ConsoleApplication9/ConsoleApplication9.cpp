#include <iostream>
#include <cmath> 

using namespace std;


// Задание №1:

template <typename T>
double getAverage(T arr[], int size) {
    if (size <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}


// Задание №2:


// Для уравнения a*x + b = 0
template <typename T>
void findRoots(T a, T b) {
    cout << "Линейное уравнение (" << a << "*x + " << b << " = 0): ";
    if (a == 0) {
        if (b == 0) cout << "Бесконечное множество решений." << endl;
        else cout << "Решений нет." << endl;
    }
    else {
        double x = static_cast<double>(-b) / a;
        cout << "Корень x = " << x << endl;
    }
}

// Для уравнения a*x^2 + b*x + c = 0
template <typename T>
void findRoots(T a, T b, T c) {
    cout << "Квадратное уравнение (" << a << "*x^2 + " << b << "*x + " << c << " = 0): ";
    if (a == 0) {
        cout << endl << "  -> Вырождается в линейное: ";
        findRoots(b, c);
        return;
    }

    double d = static_cast<double>(b * b - 4 * a * c);
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (d == 0) {
        double x = static_cast<double>(-b) / (2 * a);
        cout << "Один корень: x = " << x << endl;
    }
    else {
        cout << "Действительных корней нет." << endl;
    }
}


// Задание №3: 

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}


// Задание №4: 

template <typename T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}


int main() {
    setlocale(LC_ALL, "ru");
    cout << "--- Тест Задания 1 ---" << endl;
    int intArr[] = { 1, 2, 3, 4, 5 };
    double doubleArr[] = { 1.5, 2.5, 3.5 };
    cout << "Среднее массива int: " << getAverage(intArr, 5) << endl;
    cout << "Среднее массива double: " << getAverage(doubleArr, 3) << endl;

    cout << "\n--- Тест Задания 2 ---" << endl;
    findRoots(2, -4);         // Линейное (int)
    findRoots(1.5, -3.0);     // Линейное (double)
    findRoots(1, -5, 6);      // Квадратное: два корня
    findRoots(1, -4, 4);      // Квадратное: один корень
    findRoots(2, 1, 3);       // Квадратное: нет корней
    findRoots(0, 5, -10);     // Квадратное вырождается в линейное

    cout << "\n--- Тест Заданий 3 и 4 ---" << endl;
    int a = 10, b = 25;
    double x = 3.14, y = 2.71;
    cout << "Максимум из " << a << " и " << b << ": " << getMax(a, b) << endl;
    cout << "Минимум из " << x << " и " << y << ": " << getMin(x, y) << endl;

    return 0;
}