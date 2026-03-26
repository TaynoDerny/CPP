#include "ReverseString.h"
#include <cstring>

ReverseString::ReverseString(const char* s) : StringHolder(s) {}

ReverseString::~ReverseString() {
    cout << "ReverseString destructor\n";
}

void ReverseString::print() const {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
        cout << str[i];
    cout << "\n";
}
