#include <iostream>
#include <cmath>

using namespace std;

// --- Функция solveSpline остается без изменений ---
double solveSpline(int n, double* x, double* y, double x0) {
    
    /// выделение памяти массивов
    double* h = new double[n + 1];
    double* b = new double[n + 1];
    
    double** z = new double*[n + 1];
    for (int i = 0; i <= n; ++i) z[i] = new double[n + 1];

    double* alpha = new double[n + 1];
    double* beta = new double[n + 1];
    double* gamma_arr = new double[n + 1];
    double* c = new double[n + 1];
    double* d = new double[n + 1];
    
    double** t = new double*[n + 1];
    for (int i = 0; i <= n; ++i) t[i] = new double[5];



    /// блок схема 2.3.4
    for (int i = 1; i <= n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

    for (int j = 1; j <= n - 2; j++) {
        
        if (j == 1) {
            z[1][1] = 2 * (h[1] + h[2]);
            z[1][2] = h[2];
        } else {
            if (j == n - 2) {
                z[j][j - 1] = h[n - 2];
                z[j][j] = 2 * (h[n - 2] + h[n - 1]);
            } else {
                z[j][j - 1] = h[j];
                z[j][j] = 2 * (h[j] + h[j + 1]);
                z[j][j + 1] = h[j + 1];
            }
        }

        b[j] = 3 * (
            ((y[j + 2] - y[j + 1]) / h[j + 1]) 
            - 
            ((y[j + 1] - y[j]) / h[j])
        );
    }


    /// блок схема 2.3.5
    for (int i = 2; i <= n - 2; i++) alpha[i] = z[i][i - 1];
    for (int i = 1; i <= n - 2; i++) beta[i] = z[i][i];
    for (int i = 1; i <= n - 3; i++) gamma_arr[i] = z[i][i + 1];

    c[2] = -gamma_arr[1] / beta[1];
    d[2] = b[1] / beta[1];

    for (int i = 2; i <= n - 3; i++) {
        double denom = alpha[i] * c[i] + beta[i];
        c[i + 1] = -gamma_arr[i] / denom;
        d[i + 1] = (b[i] - alpha[i] * d[i]) / denom;
    }

    double num = b[n - 2] - alpha[n - 2] * d[n - 2];
    double den = alpha[n - 2] * c[n - 2] + beta[n - 2];
    t[n - 2][3] = num / den;

    for (int i = n - 3; i >= 1; i--) {
        t[i][3] = c[i + 1] * t[i + 1][3] + d[i + 1];
    }
    
    t[n - 1][3] = 0; 


    //  блок схема 2.3.6
    for (int i = 2; i <= n - 1; i++) {
        t[i][4] = (t[i][3] - t[i - 1][3]) / (3 * h[i]);
    }
    t[1][4] = t[1][3] / (3 * h[1]);

    for (int i = 1; i <= n - 1; i++) {
        t[i][2] = (y[i + 1] - y[i]) / h[i] + h[i] * t[i][3] - h[i] * h[i] * t[i][4];
        t[i][1] = y[i + 1];
    }

    int k = n - 1; 
    for (int i = 2; i <= n; i++) {
        if (x0 <= x[i]) {
            k = i - 1;
            break;
        }
    }

    double diff = x0 - x[k + 1];
    double y0 = t[k][1] + t[k][2] * diff + t[k][3] * pow(diff, 2) + t[k][4] * pow(diff, 3);



    /// очистка памяти массивов
    delete[] h; delete[] b;
    for (int i = 0; i <= n; ++i) delete[] z[i];
    delete[] z;
    delete[] alpha; delete[] beta; delete[] gamma_arr;
    delete[] c; delete[] d;
    for (int i = 0; i <= n; ++i) delete[] t[i];
    delete[] t;

    return y0;
}


int main() {
    int n;
    double x0;

    // Ввод количества узлов
    cout << "Введите количество узлов n: ";
    cin >> n;
    if (n < 2) {
        cerr << "Ошибка: Неверное количество узлов. Должно быть n >= 2." << endl;
        return 1;
    }

    // Выделениие памяти 
    double* x = new double[n + 1];
    double* y = new double[n + 1];

    // Ввод x-координат
    cout << "Введите значения x (от x1 до x" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    // Ввод y-координат
    cout << "Введите значения y (от y1 до y" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }

    // Ввод  x0
    cout << "Введите аргумент интерполяции x0: ";
    cin >> x0;


    double result = solveSpline(n, x, y, x0);

    // Вывод результата
    cout << endl << "Результат интерполяции y0 = " << result << endl;

    // Очистка памяти 
    delete[] x;
    delete[] y;

    return 0;
}