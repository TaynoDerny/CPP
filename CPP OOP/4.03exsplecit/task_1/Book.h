#pragma once
#include <string>  
using namespace std;
class Book
{
private:
    string author;
    string name_book;
    int number_pages;
    string public_house;
    int year;
public:
    Book();
    explicit Book(string author);
    Book(string author,string name_book, int number_pages, string public_house, int year);
    void setName_book(string name_book);
    void setAuthor(string author);
    void setNumber_pages(int number_pages);
    void setPublic_house(string public_house);
    void setYear(int year);
    string getName_book()const;
    string getAuthor()const;
    int getNumber_pages()const;
    string getPublic_house()const;
    int getYear()const;

    
    
}; 
void display(const Book& book);