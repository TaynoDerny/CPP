// PersianCat.cpp
#include "PersianCat.h"

PersianCat::PersianCat(const std::string& name, int age, const std::string& color, int woolLength)
    : Cat(name, age, color), woolLength(woolLength) {
    std::cout << "Конструктор PersianCat: " << name << std::endl;
}

PersianCat::~PersianCat() {
    std::cout << "Деструктор PersianCat: " << name << " уничтожен" << std::endl;
}

void PersianCat::sound() const {
    std::cout << name << " мягко говорит: Мяу" << std::endl;
}

void PersianCat::printInfo() const {
    Cat::printInfo();
    std::cout << ", длина шерсти: " << woolLength << " см" << std::endl;
}

void PersianCat::groom() const {
    std::cout << name << " нуждается в груминге" << std::endl;
}