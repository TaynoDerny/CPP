// WildCat.cpp
#include "WildCat.h"

WildCat::WildCat(const std::string& name, int age, const std::string& color, const std::string& habitat)
    : Cat(name, age, color), habitat(habitat) {
    std::cout << "Конструктор WildCat: " << name << std::endl;
}

WildCat::~WildCat() {
    std::cout << "Деструктор WildCat: " << name << " уничтожен" << std::endl;
}

void WildCat::sound() const {
    std::cout << name << " рычит: Рррр!" << std::endl;
}

void WildCat::printInfo() const {
    Cat::printInfo();
    std::cout << ", среда обитания: " << habitat << std::endl;
}

void WildCat::hunt() const {
    std::cout << name << " охотится" << std::endl;
}