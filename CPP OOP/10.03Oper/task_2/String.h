#pragma once

using namespace std;

class String {
private:
    char* str;
    int len;

public:
    String();
    String(const char* s);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    String operator*(const String& other) const;

    const char* c_str() const;
    int length() const;
};
