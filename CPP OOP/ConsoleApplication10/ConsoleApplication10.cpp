#include <iostream>
#include <vector>
#include "House.h"
#include "Library.h"
using namespace std;

void testComposition() {
    cout << "\n=== Тест Композиции (Дом и Комнаты) ===" << endl;
    {
        vector<string> rooms = { "Кухня", "Спальня", "Гостиная" };
        House myHouse("ул. Ленина 1", rooms);
        myHouse.printInfo();
        // При выходе из блока {} дом уничтожится, и комнаты уничтожатся вместе с ним
    }
    cout << "Дом уничтожен, комнаты тоже." << endl;
}

void testAggregation() {
    cout << "\n=== Тест Агрегации (Библиотека и Книги) ===" << endl;

    // Книги создаются ВНЕ библиотеки (в стеке функции)
    Book b1("Война и Мир");
    Book b2("Преступление и Наказание");

    {
        // Библиотека создается позже
        Library lib("Городская Библиотека");
        lib.addBook(&b1);
        lib.addBook(&b2);
        lib.listBooks();

        // Библиотека уничтожается здесь
    }

    // Книги все еще существуют, так как библиотека не удаляла их
    cout << "Библиотеки нет, но книги все еще на полке." << endl;
    // Книги уничтожатся только при выходе из testAggregation
}

int main() {
    setlocale(LC_ALL, "Russian");

    testComposition();
    testAggregation();

    cout << "\nКонец программы." << endl;
    return 0;
}