#pragma once

#include "Cat.h"

class WildCat : public Cat {
private:
    std::string habitat;

public:
    WildCat(const std::string& name, int age, const std::string& color, const std::string& habitat);
    virtual ~WildCat();

    void sound() const;
    void printInfo() const;
    void hunt() const;
};

