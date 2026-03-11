#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class Array {
private:
    int* data;
    int size;
    mutable char* strBuffer;

public:
    Array(int size);
    ~Array();
    
    void set(int index, int value);
    int get(int index) const;
    int getSize() const;
    void print() const;
    
    int& operator[](int index);
    int operator[](int index) const;
    
    void operator()(int value);
    
    operator int() const;
    operator char*() const;
};

#endif
