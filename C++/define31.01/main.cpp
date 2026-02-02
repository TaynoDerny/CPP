#include <iostream>

using namespace std;

// Макросы
#define MIN_VAL(a, b) (((a) < (b)) ? (a) : (b))
#define MAX_VAL(a, b) (((a) > (b)) ? (a) : (b))
#define SQUARE(x) ((x) * (x))
#define IS_EVEN(n) ((n) % 2 == 0)
#define IS_ODD(n) ((n) % 2 != 0)

int main() {
    setlocale(LC_ALL, "Ru");

    int a, b;
    cout << "Введите два целых числа: ";
    cin >> a >> b;

    // 1 и 2. Минимум и максимум 
    if (a == b) {
        cout << "Числа равны" << endl;
    } else {
        cout << "Меньшее: " << MIN_VAL(a, b) << endl;
        cout << "Большее: " << MAX_VAL(a, b) << endl;
    }

    // 3. Квадрат
    cout << "Квадрат первого числа: " << SQUARE(a) << endl;

    // 4. Степень без 
    long long powerResult = 1;
    if (b >= 0) {
        for (int i = 0; i < b; i++) {
            powerResult *= a;
        }
        cout << a << " в степени " << b << " равно: " << powerResult << endl;
    } else {
        cout << "Для отрицательных степеней обычно нужна библиотека math" << endl;
    }

    // 5 и 6. Четноe/Нечетное
    if (IS_EVEN(a)) {
        cout << "Число " << a << " четное" << endl;
    } else {
        cout << "Число " << a << " нечетное" << endl;
    }

    if (IS_ODD(b)) {
        cout << "Число " << b << " нечетное" << endl;
    } else {
        cout << "Число " << b << " четное" << endl;
    }

    return 0;
}