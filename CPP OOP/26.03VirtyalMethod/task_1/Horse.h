#pragma once
#include "Animal.h"

class Horse : public Animal
{
public:
	Horse(){};
    void speak() const override;
};