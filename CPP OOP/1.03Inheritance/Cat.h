#pragma once

#include <string>
#include <iostream>

class Cat {
protected:
    std::string name;
    int age;
    std::string color;
    static int count; // объявление статического поля

public:
    Cat(const std::string& name, int age, const std::string& color);
    virtual ~Cat(); // виртуальный деструктор

    void printInfo() const;
    void sound() const;

    static int getCount();
};

