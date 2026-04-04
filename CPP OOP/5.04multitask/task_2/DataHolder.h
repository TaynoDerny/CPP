#pragma once
#include <iostream>

class DataHolder {
private:
    int data[5];
public:
    DataHolder();
    const int* getData() const;
    void print() const;
};
