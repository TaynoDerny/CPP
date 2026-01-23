#include <iostream>
#include <string>

using namespace std;

struct Complex {
    double real;
    double imag;
};

// Математические функции
Complex add(Complex a, Complex b) { return {a.real + b.real, a.imag + b.imag}; }
Complex sub(Complex a, Complex b) { return {a.real - b.real, a.imag - b.imag}; }
Complex mul(Complex a, Complex b) {    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real}; }
Complex divide(Complex a, Complex b) {
    double den = b.real * b.real + b.imag * b.imag;
    return {(a.real * b.real + a.imag * b.imag) / den, (a.imag * b.real - a.real * b.imag) / den};
}

void printComplex(string op, Complex c) {
    cout << op << ": " << c.real;

    if (c.imag >= 0) {
        cout << " + " << c.imag << "i" << endl;
    } else {
        cout << " - " << -c.imag << "i" << endl;
    }
}
struct Car {
    double length;
    double clearance;
    double engineVolume;
    int power;
    double wheelDiameter;
    string color;
    string transmission;
};

void displayCar(Car c) {
    cout << "[" << c.color << "] Мощность: " << c.power << " л.с., Двигатель: " << c.engineVolume << "л, КПП: " << c.transmission << ", Колеса: " << c.wheelDiameter << "\", Длина: " << c.length << "м, Клиренс: " << c.clearance << "мм" << endl;
}
int main() {
    Complex n1, n2;

    cout << "--- Калькулятор комплексных чисел ---" << endl;
    cout << "Введите первое число (реальная и мнимая части через пробел): "<<endl;
    cin >> n1.real >> n1.imag;
    char choice;

    cout << "Введите /, +, -, *"<<endl;
    cin >>choice;

    cout << "Введите второе число (реальная и мнимая части через пробел): "<<endl;
    cin >> n2.real >> n2.imag;
    switch (choice)
    {
    case '/':
        if (n2.real == 0 && n2.imag == 0) {
        cout << "Деление: Ошибка (деление на ноль)!" << endl;
        } else {
        printComplex("Деление", divide(n1, n2));
        }
        break;
    case '+':
        printComplex("Результат:", divide(n1, n2));
        break;
    case '-':
        printComplex("Результат:", divide(n1, n2));
        break;
    case '*':
        printComplex("Результат:", divide(n1, n2));
        break;
    default:
        break;
    }
    
     int count;
    cout << "Сколько автомобилей добавить в базу? "<<endl;
    cin >> count;

    
    Car* garage = new Car[count];

    for (int i = 0; i < count; i++) {
        cout << "\nВведите данные для авто #" << i + 1 << ":" << endl;
        cout << "Длина (м): "; cin >> garage[i].length;
        cout << "Клиренс (мм): "; cin >> garage[i].clearance;
        cout << "Объем двигателя (л): "; cin >> garage[i].engineVolume;
        cout << "Мощность (л.с.): "; cin >> garage[i].power;
        cout << "Диаметр колес (дюймы): "; cin >> garage[i].wheelDiameter;
        cin.ignore(); 
        cout << "Цвет: "; getline(cin, garage[i].color);
        cout << "Тип КПП: "; getline(cin, garage[i].transmission);
    }

    cout << "\n--- Список всех автомобилей ---" << endl;
    for (int i = 0; i < count; i++) {
        displayCar(garage[i]);
    }

    // Поиск
    string searchColor;
    cout << "\nВведите цвет для поиска: "<<endl;
    getline(cin, searchColor);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (garage[i].color == searchColor) {
            cout << "Найдено: "<<endl;
            displayCar(garage[i]);
            found = true;
        }
    }
    if (!found) cout << "Машин такого цвета нет в базе." << endl;

    delete[] garage; 
    return 0;
}