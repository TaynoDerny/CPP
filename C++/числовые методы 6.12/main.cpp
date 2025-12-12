#include <iostream>
#include <cmath>

using namespace std;


const int MAX_SIZE = 10;


void reverse(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Функция вывода матрицы
void print_matrix(int rows, int cols, double M[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (abs(M[i][j]) < 1e-9) cout << 0.0 << "\t";
            else cout << M[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Система  уравненйи
void solve_slae(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE]) {
    double A_copy[MAX_SIZE][MAX_SIZE]; 
    double B_copy[MAX_SIZE];     
          
    double X[MAX_SIZE];

    for(int i=0; i<n; i++) {
        B_copy[i] = B[i];
        for(int j=0; j<n; j++) A_copy[i][j] = A[i][j];
    }


    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A_copy[k][i]) > abs(A_copy[max_row][i])) max_row = k;
        }

        for (int j = i; j < n; j++) reverse(A_copy[i][j], A_copy[max_row][j]);
        reverse(B_copy[i], B_copy[max_row]);

        for (int k = i + 1; k < n; k++) {
            double factor = A_copy[k][i] / A_copy[i][i];
            for (int j = i; j < n; j++) A_copy[k][j] -= factor * A_copy[i][j];
            B_copy[k] -= factor * B_copy[i];
        }
    }


    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) sum += A_copy[i][j] * X[j];
        X[i] = (B_copy[i] - sum) / A_copy[i][i];
    }

    cout << "Корни системы (x1, x2, x3):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << X[i] << endl;
    }
}

// Вычисление определителя
void calc_det(int n, double A[MAX_SIZE][MAX_SIZE]) {
    double A_copy[MAX_SIZE][MAX_SIZE];

    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) A_copy[i][j] = A[i][j];

    double det = 1.0;

    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A_copy[k][i]) > abs(A_copy[max_row][i])) max_row = k;
        }

        if (i != max_row) {
            for (int j = 0; j < n; j++) reverse(A_copy[i][j], A_copy[max_row][j]);
            det *= -1; 
        }

        if (abs(A_copy[i][i]) < 1e-9) { 
            cout << "Определитель = 0" << endl;
            return;
        }

        det *= A_copy[i][i];

        for (int k = i + 1; k < n; k++) {
            double factor = A_copy[k][i] / A_copy[i][i];
            for (int j = i; j < n; j++) A_copy[k][j] -= factor * A_copy[i][j];
        }
    }

    cout << "Определитель = " << det << endl;
}


 // Обратная матрица
void calc_inverse(int n, double A[MAX_SIZE][MAX_SIZE]) {
    double A_copy[MAX_SIZE][MAX_SIZE]; 

    double I[MAX_SIZE][MAX_SIZE];      

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A_copy[i][j] = A[i][j];
            
            if (i == j) {
                I[i][j] = 1.0; 
            } else {
                I[i][j] = 0.0; 
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A_copy[k][i]) > abs(A_copy[max_row][i])) max_row = k;
        }

        for (int j = 0; j < n; j++) {
            reverse(A_copy[i][j], A_copy[max_row][j]);
            reverse(I[i][j], I[max_row][j]);
        }

        double pivot = A_copy[i][i];
        if (abs(pivot) < 1e-9) {
            cout << " Обратная матрица не существует" << endl;
            return;
        }

        for (int j = 0; j < n; j++) {
            A_copy[i][j] /= pivot;
            I[i][j] /= pivot;
        }

        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A_copy[k][i];
                for (int j = 0; j < n; j++) {
                    A_copy[k][j] -= factor * A_copy[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }

    cout << "Обратная матрица (в):" << endl;
    print_matrix(n, n, I);
}

int main() {
    /// a) Решить систему уравнений
    double A_task_a[MAX_SIZE][MAX_SIZE] = {
        { 22.52, -4.62, -1.41},
        { -5.10, -28.37, 4.58},
        {  4.68, -1.91, 23.85}
    };
    double B_task_a[MAX_SIZE] = {0.53, -8.78, 5.14};

    cout << "--- а): Решение системы  уравнений ---" << endl;
    solve_slae(3, A_task_a, B_task_a);
    cout << endl;


 
    ////// б) Вычислить определитель
    double A_task_b[MAX_SIZE][MAX_SIZE] = {
        { -23.98,   1.50,  -8.78,   7.74},
        {  -8.70, -28.73,   3.86,   8.08},
        {   1.62,   3.88, -18.17,  -8.68},
        {  -6.97,   1.96,   1.55, -29.54}
    };

    cout << "--- б): Определитель матрицы  ---" << endl;
    calc_det(4, A_task_b);
    cout << endl;


    ///в) Обратная матрица
    double A_task_v[MAX_SIZE][MAX_SIZE] = {
        { -17.01,  6.28,  -8.25,  -2.57,  3.05},
        {   7.98, 18.40,   0.79,  -0.35,  8.54},
        {  -8.82,  2.07, -15.99,   4.30,  1.03},
        {   2.43, -4.29,   0.52,  31.46,  4.78},
        {  -5.82,  1.84,   3.11,   6.42, 21.47}
    };

    cout << "--- в): Обратная матрица  ---" << endl;
    calc_inverse(5, A_task_v);

    return 0;
}