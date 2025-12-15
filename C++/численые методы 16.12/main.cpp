#include <iostream>
#include <cmath>

using namespace std;

// Функция факториала  для формулы Ньютона
long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

///// Функция  Лагранжа 
// x[]  массив аргументов y[]  массив значений n  количество точек xp  точка где ищем значение
double lagrangeInterpolation(double* x, double* y, int n, double xp) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double temp = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                temp = temp * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        result += temp;
    }
    return result;
}

//     Функция интерполяции Ньютона 

double newtonInterpolation(double* x, double* y, int n, double xp) {
    // Выделение память под таблицу конечных разностей
    double** diff = new double*[n];
    for (int i = 0; i < n; i++) {
        diff[i] = new double[n];
    }

    // Заполнение первого столбца значениями 
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }

    // Вычисление конечные разности 
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    
    double h = x[1] - x[0];
    

    double q = (xp - x[0]) / h;
    
    // Формула Ньютона для интерполяции вперед:

    double result = diff[0][0];
    double q_temp = 1.0;

    for (int i = 1; i < n; i++) {
        q_temp *= (q - (i - 1)); 
        result += (q_temp * diff[0][i]) / factorial(i);
    }

    // Очистка памяти
    for (int i = 0; i < n; i++) delete[] diff[i];
    delete[] diff;

    return result;
}

int main() {
    setlocale(LC_ALL, "ru"); 

    int n;
    cout << "Введите количество точек  x и y: "<<endl;
    cin >> n;

    // Выделяем память под массивы
    double* x = new double[n];
    double* y = new double[n];

    cout << "Введите значения x и y (через пробел):\n";
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    int choice;
    cout << "\nВыберите метод:\n1 - Лагранж (Задания 3, 4)\n2 - Ньютон (Задания 5, 6, 7): "<<endl;
    cin >> choice;

    double xp;
    cout << "\nВведите значение аргумента x, для которого нужно найти функцию: "<<endl;
    cin >> xp;

    if (choice == 1) {
        double res = lagrangeInterpolation(x, y, n, xp);
        cout << "\n[Лагранж] Значение функции в точке " << xp << " = " << res << endl;
    } 
    else if (choice == 2) {
        double res = newtonInterpolation(x, y, n, xp);
        cout << "\n[Ньютон] Значение функции в точке " << xp << " = " << res << endl;
    } 
    else {
        cout << "Неверный выбор метода." << endl;
    }

    // Освобождение памяти
    delete[] x;
    delete[] y;

    return 0;
}