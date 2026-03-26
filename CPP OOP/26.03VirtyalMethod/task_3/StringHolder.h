#pragma once
#include <iostream>
using namespace std;

class StringHolder {
protected:
    char* str;
public:
    StringHolder(const char* s);
    virtual ~StringHolder();
    virtual void print() const;
};
