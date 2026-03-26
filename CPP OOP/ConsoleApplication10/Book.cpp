#include "Book.h"
using namespace std;

Book::Book(string title) : title(title) {
    cout << " нига \"" << title << "\" издана." << endl;
}

Book::~Book() {
    cout << " нига \"" << title << "\" уничтожена." << endl;
}

string Book::getTitle() const {
    return title;
}