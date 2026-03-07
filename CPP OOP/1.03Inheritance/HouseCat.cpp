// HouseCat.cpp
#include "HouseCat.h"

HouseCat::HouseCat(const std::string& name, int age, const std::string& color, const std::string& owner)
    : Cat(name, age, color), ownerName(owner) {
    std::cout << "Конструктор HouseCat: " << name << std::endl;
}

HouseCat::~HouseCat() {
    std::cout << "Деструктор HouseCat: " << name << " уничтожен" << std::endl;
}

void HouseCat::sound() const {
    std::cout << name << " мурлычет: Мррр-мррр" << std::endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    std::cout << ", владелец: " << ownerName << std::endl;
}

void HouseCat::play() const {
    std::cout << name << " играет с мячиком" << std::endl;
}