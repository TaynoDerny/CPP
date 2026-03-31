#include <iostream>
#include "task_1/Point.cpp"
#include "task_2/Vehicle.cpp"
#include "task_3/Car.cpp"
#include "task_3/Bike.cpp"
#include "task_4/Garage.h"
using namespace std;

int main() {
    cout << "=== Создание объектов ===\n";

    // конструктор с параметрами
    Car* car1 = new Car("Toyota", 2022, Point(1, 2), 4);
    Car* car2 = new Car("BMW", 2023, Point(3, 4), 2);

    // explicit конструктор от строки (год=2020, позиция=(0,0))
    Car* car3 = new Car("Audi");  // explicit — только явный вызов

    Bike* bike1 = new Bike("Yamaha", 2021, Point(0, 0), "sport");
    Bike* bike2 = new Bike("Trek", 2020, Point(5, 5), "mountain");

    cout << "totalVehicles после создания 5 объектов: " << Vehicle::totalVehicles << "\n\n";

    // === Garage 1 ===
    cout << "=== Гараж 1 ===\n";
    Garage<Vehicle*> garage1;
    // цепочка вызовов add через this
    garage1.add(car1).add(car2).add(bike1);

    // полиморфизм — вызов print() и getMaxSpeed() через указатель на базовый класс
    for (int i = 0; i < garage1.getCount(); i++) {
        garage1[i]->print();
        cout << "  max speed: " << garage1[i]->getMaxSpeed() << "\n";
    }

    // move — константный метод
    cout << "\nПеремещаем car1 в (10, 10):\n";
    car1->move(Point(10, 10));
    car1->print();

    // === Конструктор копирования Garage (глубокое копирование) ===
    cout << "\n=== Копия гаража ===\n";
    Garage<Vehicle*> garage1Copy = garage1;
    garage1.add(car3);  // изменяем оригинал
    cout << "Оригинал после добавления: " << garage1.getCount() << " элементов\n";
    cout << "Копия не изменилась:        " << garage1Copy.getCount() << " элементов\n";

    // === Garage 2 + оператор + ===
    cout << "\n=== Гараж 2 и объединение ===\n";
    Garage<Vehicle*> garage2;
    garage2.add(bike2);

    Garage<Vehicle*> garage3 = garage1 + garage2;
    cout << "garage1(" << garage1.getCount() << ") + garage2("
         << garage2.getCount() << ") = garage3(" << garage3.getCount() << ")\n";

    cout << "\nВсе ТС в объединённом гараже:\n";
    for (int i = 0; i < garage3.getCount(); i++)
        garage3[i]->print();

    // === Операторы Point ===
    cout << "\n=== Операторы Point ===\n";
    Point p1(1, 2), p2(1, 2), p3(3, 4);
    cout << "p1 = " << p1 << ", p2 = " << p2 << ", p3 = " << p3 << "\n";
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << "\n";
    cout << "p1 != p3: " << (p1 != p3 ? "true" : "false") << "\n";

    // === Операторы ++ для Car ===
    cout << "\n=== Операторы ++ (Car doors) ===\n";
    cout << "До: "; car2->print();
    ++(*car2);
    cout << "После префиксного ++: "; car2->print();
    (*car2)++;
    cout << "После постфиксного ++: "; car2->print();

    // === Статические поля ===
    cout << "\n=== Статические счётчики ===\n";
    cout << "Всего точек:          " << Point::getCount() << "\n";
    cout << "Всего ТС:             " << Vehicle::totalVehicles << "\n";
    cout << "Всего гаражей:        " << Garage<Vehicle*>::getTotalGarages() << "\n";

    // === Исключение при выходе за границы ===
    cout << "\n=== Исключение out_of_range ===\n";
    try {
        garage1[99]->print();
    } catch (const out_of_range& e) {
        cout << "Поймано исключение: " << e.what() << "\n";
    }

    // освобождение памяти
    delete car1; delete car2; delete car3;
    delete bike1; delete bike2;

    return 0;
}
