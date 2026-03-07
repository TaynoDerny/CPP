#pragma once
#include "Cat.h"

class PersianCat : public Cat {
private:
    int woolLength;

public:
    PersianCat(const std::string& name, int age, const std::string& color, int woolLength);
    virtual ~PersianCat();

    void sound() const;
    void printInfo() const;
    void groom() const;
};

