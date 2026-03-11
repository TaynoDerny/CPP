#include "Array.h"
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

Array::Array(int size) : size(size), strBuffer(nullptr) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

Array::~Array() {
    delete[] data;
    if (strBuffer) delete[] strBuffer;
}

void Array::set(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

int Array::get(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return 0;
}

int Array::getSize() const {
    return size;
}

void Array::print() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int& Array::operator[](int index) {
    return data[index];
}

int Array::operator[](int index) const {
    return data[index];
}

void Array::operator()(int value) {
    for (int i = 0; i < size; i++) {
        data[i] += value;
    }
}

Array::operator int() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

Array::operator char*() const {
    if (strBuffer) delete[] strBuffer;
    
    stringstream ss;
    for (int i = 0; i < size; i++) {
        ss << data[i];
        if (i < size - 1) ss << " ";
    }
    
    string str = ss.str();
    strBuffer = new char[str.length() + 1];
    strcpy(strBuffer, str.c_str());
    
    return strBuffer;
}
