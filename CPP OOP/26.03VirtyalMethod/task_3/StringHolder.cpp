#include "StringHolder.h"
#include <cstring>

StringHolder::StringHolder(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

StringHolder::~StringHolder() {
    cout << "StringHolder destructor for \"" << str << "\"\n";
    delete[] str;
}

void StringHolder::print() const {
    cout << str << "\n";
}
