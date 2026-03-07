// Cat.cpp
#include "Cat.h"

int Cat::count = 0;

Cat::Cat(const std::string& name, int age, const std::string& color)
    : name(name), age(age), color(color) {
    ++count;
    std::cout << "Конструктор Cat: " << name << std::endl;
}

Cat::~Cat() {
    --count;
    std::cout << "Деструктор Cat: " << name << " уничтожен" << std::endl;
}

void Cat::printInfo() const {
    std::cout << "Кошка: " << name << ", возраст " << age << ", окрас " << color;
}

void Cat::sound() const {
    std::cout << "Кошка издает звук: Мяу!" << std::endl;
}

int Cat::getCount() {
    return count;
}