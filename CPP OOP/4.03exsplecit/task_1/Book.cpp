#include "Book.h"
#include <iostream>
using namespace std;

Book::Book()
{

    author = "Не указанно";
    name_book = "Не указанно";
    number_pages = 0;
    public_house = "Не  указано";
    year = 0;
}
Book::Book(string author):author(author),name_book("Не  указано"),number_pages(0),public_house("Не  указано"),year(0){}

Book::Book(string author,string name_book, int number_pages, string public_house, int year)
{
    this->author = author;
    this->name_book = name_book;
    this->number_pages = number_pages;
    this->public_house = public_house;
    this->year = year;
}
void Book::setAuthor(string author)
{
    this->author = author;
}
void Book::setName_book(string name_book)
{
    this->name_book = name_book;
}
void Book::setPublic_house(string public_house)
{
    this->public_house = public_house;
}

void Book::setNumber_pages(int number_pages)
{
    this->number_pages = number_pages;
}
void Book::setYear(int year)
{
    this->year = year;
}
string Book::getAuthor()const
{
    return author;
}
string Book::getName_book()const
{
    return name_book;
}
string Book::getPublic_house()const
{
    return public_house;
}
int Book::getNumber_pages()const
{
    return number_pages;
}
int Book::getYear()const
{
    return year;
}



void display(const Book& book){
    static int id = 0;
    cout<<endl<<"-------№"<<++id<<endl;
    cout << "Автор: "<<  book.getAuthor() << endl;
    cout << "Название книги: "<< book.getName_book() << endl;
    cout << "Количество страниц: "<< book.getNumber_pages() << endl;
    cout << "Издательство: "<< book.getPublic_house() << endl;
    cout << "Год издания: "<< book.getYear() << endl;
    cout << "----------------------------------------"<<endl;
}