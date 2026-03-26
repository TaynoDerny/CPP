#pragma once
#include "StringHolder.h"

class ReverseString : public StringHolder {
public:
    ReverseString(const char* s);
    ~ReverseString();
    void print() const override;
};
