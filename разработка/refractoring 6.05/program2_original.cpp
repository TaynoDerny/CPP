#include <iostream>
using namespace std;

int main() {
    double a, b, result;
    char op;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите оператор (+, -, *, /, ^): ";
    cin >> op;
    cout << "Введите второе число: ";
    cin >> b;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                cout << "Ошибка: деление на ноль!" << endl;
                return 1;
            }
            result = a / b;
            break;
        case '^': {
            if (b < 0) {
                cout << "Ошибка: отрицательная степень не поддерживается в этой версии." << endl;
                return 1;
            }
            result = 1.0;
            for (int i = 0; i < static_cast<int>(b); ++i)
                result *= a;
            break;
        }
        default:
            cout << "Неверный оператор!" << endl;
            return 1;
    }

    cout << "Результат: " << result << endl;
    return 0;
}