#include <iostream>
using namespace std;

double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (base == 0.0 && exp < 0) return 0.0;
    double result = 1.0;
    long long e = exp;
    if (e < 0) {
        base = 1.0 / base;
        e = -e;
    }
    while (e > 0) {
        if (e & 1) result *= base;
        base *= base;
        e >>= 1;
    }
    return result;
}

bool calculate(double a, double b, char op, double& result) {
    switch (op) {
        case '+': result = a + b; return true;
        case '-': result = a - b; return true;
        case '*': result = a * b; return true;
        case '/':
            if (b == 0) {
                cout << "Ошибка: деление на ноль!" << endl;
                return false;
            }
            result = a / b;
            return true;
        case '^': {
            int exp = static_cast<int>(b);
            if (static_cast<double>(exp) != b) {
                cout << "Ошибка: показатель степени должен быть целым числом." << endl;
                return false;
            }
            if (a == 0.0 && exp < 0) {
                cout << "Ошибка: 0 в отрицательной степени." << endl;
                return false;
            }
            result = power(a, exp);
            return true;
        }
        default:
            cout << "Неверный оператор!" << endl;
            return false;
    }
}

int main() {
    double a, b, result;
    char op;

    cout << "Введите первое число: ";
    if (!(cin >> a)) {
        cout << "Ошибка ввода первого числа." << endl;
        return 1;
    }

    cout << "Введите оператор (+, -, *, /, ^): ";
    cin >> op;

    cout << "Введите второе число: ";
    if (!(cin >> b)) {
        cout << "Ошибка ввода второго числа." << endl;
        return 1;
    }

    if (calculate(a, b, op, result)) {
        cout << "Результат: " << result << endl;
    } else {
        cout << "Вычисление не выполнено." << endl;
    }

    return 0;
}