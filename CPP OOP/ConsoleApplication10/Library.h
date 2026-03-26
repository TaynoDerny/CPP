#pragma once


#include "Book.h"
#include <vector>
#include <string>
using namespace std;

class Library {
private:
    string name;
    vector<Book*> books; // Агрегация: храним указатели на внешние объекты

public:
    Library(string name);
    ~Library();
    void addBook(Book* book);
    void listBooks() const;
};

