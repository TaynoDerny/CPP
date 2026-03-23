#include "Library.h"
using namespace std;

Library::Library(string name) : name(name) {
    cout << "Библиотека \"" << name << "\" открыта." << endl;
}

Library::~Library() {
    cout << "Библиотека \"" << name << "\" закрыта." << endl;
    // Важное отличие агрегации: мы НЕ удаляем книги (delete),
    // так как они не принадлежат библиотеке полностью.
    books.clear();
}

void Library::addBook(Book* book) {
    books.push_back(book);
}

void Library::listBooks() const {
    cout << "Фонд библиотеки \"" << name << "\":" << endl;
    for (const auto& book : books) {
        cout << "  - " << book->getTitle() << endl;
    }
}