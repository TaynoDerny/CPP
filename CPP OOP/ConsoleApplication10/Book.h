#pragma once

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
public:
    Book(string title);
    ~Book();
    string getTitle() const;
};

