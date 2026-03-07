#pragma once

#include "Cat.h"

class HouseCat : public Cat {
private:
    std::string ownerName;

public:
    HouseCat(const std::string& name, int age, const std::string& color, const std::string& owner);
    virtual ~HouseCat(); // виртуальный деструктор

    void sound() const;
    void printInfo() const;
    void play() const;
};
