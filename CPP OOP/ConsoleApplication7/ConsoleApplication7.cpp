#include <iostream>
#include "Circle.h"
#include "Airplane.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    cout << "========== РАБОТА С КЛАССОМ CIRCLE ==========\n\n";

    // Создаем окружности
    Circle c1(5.0);
    Circle c2(3.0);
    Circle c3(5.0);

    cout << "Окружность 1: " << c1 << endl;
    cout << "Окружность 2: " << c2 << endl;
    cout << "Окружность 3: " << c3 << endl;

    cout << "\n--- Сравнение радиусов (==) ---\n";
    cout << "c1 == c2? " << (c1 == c2 ? "Да" : "Нет") << endl;
    cout << "c1 == c3? " << (c1 == c3 ? "Да" : "Нет") << endl;

    cout << "\n--- Сравнение длин окружностей (>) ---\n";
    cout << "c1 > c2? " << (c1 > c2 ? "Да (c1 длиннее)" : "Нет") << endl;

    cout << "\n--- Изменение радиуса (+= и -=) ---\n";
    cout << "Было c1: " << c1 << endl;
    c1 += 2.0;
    cout << "c1 += 2: " << c1 << endl;

    cout << "Было c2: " << c2 << endl;
    c2 -= 1.0;
    cout << "c2 -= 1: " << c2 << endl;

    cout << "\n========== РАБОТА С КЛАССОМ AIRPLANE ==========\n\n";

    // Создаем самолеты
    Airplane a1("Boeing", 180, 150);
    Airplane a2("Airbus", 200, 100);
    Airplane a3("Boeing", 180, 170);

    cout << "Самолет 1: " << a1 << endl;
    cout << "Самолет 2: " << a2 << endl;
    cout << "Самолет 3: " << a3 << endl;

    cout << "\n--- Сравнение по типу (==) ---\n";
    cout << "a1 == a2? " << (a1 == a2 ? "Да (оба " + a1.getType() + ")" : "Нет (разные типы)") << endl;
    cout << "a1 == a3? " << (a1 == a3 ? "Да (оба Boeing)" : "Нет") << endl;

    cout << "\n--- Сравнение по макс. пассажирам (>) ---\n";
    cout << "a1 > a2? " << (a1 > a2 ? "Да (у Boeing больше мест)" : "Нет") << endl;
    cout << "a2 > a1? " << (a2 > a1 ? "Да (у Airbus больше мест)" : "Нет") << endl;

    cout << "\n--- Посадка и высадка пассажиров (++ и --) ---\n";
    cout << "a1 до посадки: " << a1 << endl;
    ++a1;
    cout << "++a1 (1 пассажир сел): " << a1 << endl;

    cout << "a2 до высадки: " << a2 << endl;
    --a2;
    cout << "--a2 (1 пассажир вышел): " << a2 << endl;

    cout << "\n--- Проверка границ ---\n";
    cout << "Пытаемся посадить еще 50 пассажиров в a1:\n";
    for (int i = 0; i < 50; i++) ++a1;
    cout << "Результат: " << a1 << " (больше максимума не пускает)\n";

    cout << "\nНажмите Enter для выхода...";
    cin.get();

    return 0;
}