#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool extractNumber(const string& str, int& result) {
    if (str.empty()) return false;

    int sign = 1;
    size_t i = 0;

    while (i < str.length() && !isdigit(str[i])) {
        if (str[i] == '-') sign = -1;
        i++;
    }

    if (i >= str.length() || !isdigit(str[i])) return false;

    int num = 0;
    while (i < str.length() && isdigit(str[i])) {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    result = num * sign;
    return true;
}

int main() {
    string input;
    cout << "Введите строку (например, b5): ";
    cin >> input;

    int number;
    if (extractNumber(input, number)) {
        cout << "Вы ввели: " << number << " (только число)" << endl;
        cout << "Квадрат числа: " << number * number << endl;
    } else {
        cout << "В строке не найдено ни одного числа." << endl;
    }

    return 0;
}