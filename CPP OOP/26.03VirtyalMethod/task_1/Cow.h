#pragma once
#include "Animal.h"

class Cow : public Animal {
public:
    Cow(){};
    void speak()const override;
};