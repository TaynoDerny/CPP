#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cout << "Введите строку (например, b5): ";
    cin >> input;

    bool found = false;
    int number = 0;
    int sign = 1;
    size_t i = 0;

    while (i < input.length() && !isdigit(input[i])) {
        if (input[i] == '-') sign = -1;
        i++;
    }

    if (i < input.length() && isdigit(input[i])) {
        while (i < input.length() && isdigit(input[i])) {
            number = number * 10 + (input[i] - '0');
            i++;
        }
        number *= sign;
        found = true;
    }

    if (found) {
        cout << "Вы ввели: " << number << " (только число)" << endl;
        cout << "Квадрат числа: " << number * number << endl;
    } else {
        cout << "В строке не найдено ни одного числа." << endl;
    }

    return 0;
}