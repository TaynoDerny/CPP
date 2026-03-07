#include "Book.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Создаем массив книг (используем только обычный массив, без вектора)
    const int SIZE = 6;
    Book books[SIZE] = {
        Book("Пушкин", "Евгений Онегин", 300, "Азбука", 1833),
        Book("Толстой", "Война и мир", 1200, "Эксмо", 1869),
        Book("Достоевский", "Преступление и наказание", 400, "АСТ", 1866),
        Book("Пушкин", "Капитанская дочка", 200, "Азбука", 1836),
        Book("Толстой", "Анна Каренина", 800, "Эксмо", 1877),
        Book("Гоголь", "Мертвые души", 350, "АСТ", 1842)
    };

    // Демонстрация explicit конструктора: создаем книгу с одним параметром (автор)
    // Прямая инициализация разрешена даже для explicit
    Book extraBook("Лермонтов");
    // Заполняем остальные поля через сеттеры
    extraBook.setName_book("Герой нашего времени");
    extraBook.setNumber_pages(250);
    extraBook.setPublic_house("Эксмо");
    extraBook.setYear(1840);

    // Вывод всех книг (включая дополнительную)
    cout << "--- ВСЕ КНИГИ (включая дополнительную) ---\n";
    for (int i = 0; i < SIZE; ++i) {
        display(books[i]);
    }
    cout << "\n--- ДОПОЛНИТЕЛЬНАЯ КНИГА (explicit конструктор) ---\n";
    display(extraBook);

    // 1. Поиск по автору
    cout << "\nВведите автора для поиска: ";
    string authorSearch;
    getline(cin, authorSearch); // если ввод с пробелами

    cout << "\nКниги автора \"" << authorSearch << "\":\n";
    bool authorFound = false;
    for (int i = 0; i < SIZE; ++i) {
        if (books[i].getAuthor() == authorSearch) {
            display(books[i]);
            authorFound = true;
        }
    }
    if (!authorFound) {
        cout << "Книг данного автора не найдено.\n";
    }

    // 2. Поиск по издательству
    cout << "\nВведите издательство для поиска: ";
    string pubSearch;
    getline(cin, pubSearch); // после предыдущего getline проблем с буфером нет

    cout << "\nКниги издательства \"" << pubSearch << "\":\n";
    bool pubFound = false;
    for (int i = 0; i < SIZE; ++i) {
        if (books[i].getPublic_house() == pubSearch) {
            display(books[i]);
            pubFound = true;
        }
    }
    if (!pubFound) {
        cout << "Книг данного издательства не найдено.\n";
    }

    // 3. Поиск по году (после заданного)
    cout << "\nВведите год (книги, выпущенные после этого года): ";
    int yearLimit;
    cin >> yearLimit;
    cin.ignore(); // убираем перевод строки после числа, чтобы не мешал дальнейшему вводу (если он будет)

    cout << "\nКниги, выпущенные после " << yearLimit << " года:\n";
    bool yearFound = false;
    for (int i = 0; i < SIZE; ++i) {
        if (books[i].getYear() > yearLimit) {
            display(books[i]);
            yearFound = true;
        }
    }
    if (!yearFound) {
        cout << "Книг, выпущенных после указанного года, не найдено.\n";
    }

    return 0;
}