
#include <iostream>
#include "Cat.cpp"
#include "HouseCat.cpp"
#include "WildCat.cpp"
#include "PersianCat.cpp"

int main() {
    std::cout << "Начальное количество кошек: " << Cat::getCount() << std::endl;

    std::cout << "\nСоздание объектов:\n";
    Cat basic("Том", 5, "серый");
    HouseCat house("Мурка", 3, "белый", "Алиса");
    WildCat wild("Лео", 7, "золотистый", "саванна");
    PersianCat persian("Снежок", 2, "белый", 12);

    std::cout << "\nКоличество кошек после создания: " << Cat::getCount() << std::endl;

    std::cout << "\n--- Прямые вызовы ---\n";
    basic.printInfo(); std::cout << ", звук: "; basic.sound();

    house.printInfo(); std::cout << "звук: "; house.sound(); house.play();

    wild.printInfo(); std::cout << "звук: "; wild.sound(); wild.hunt();

    persian.printInfo(); std::cout << "звук: "; persian.sound(); persian.groom();

    std::cout << "\n--- Вызовы через указатели на базовый класс ---\n";
    Cat* ptr1 = &house;
    Cat* ptr2 = &wild;
    Cat* ptr3 = &persian;

    ptr1->printInfo(); std::cout << "звук: "; ptr1->sound();
    ptr2->printInfo(); std::cout << "звук: "; ptr2->sound();
    ptr3->printInfo(); std::cout << "звук: "; ptr3->sound();

    std::cout << "\n--- Вызовы через ссылки на базовый класс ---\n";
    Cat& ref1 = house;
    Cat& ref2 = wild;
    Cat& ref3 = persian;

    ref1.printInfo(); std::cout << "звук: "; ref1.sound();

    std::cout << "\n--- Порядок уничтожения (обратный созданию) ---\n";
    return 0;
}