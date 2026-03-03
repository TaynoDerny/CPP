#include "person.h"
#include <cstring>
#include <iostream>

using namespace std;

int Person::objectCount = 0;

Person::Person(int pid, const char* psurname, const char* pname, 
               const char* ppatronymic, const Date& pbirthDate) 
    : id(pid), birthDate(pbirthDate) {
    
    surname = new char[strlen(psurname) + 1];
    strcpy(surname, psurname);
    
    name = new char[strlen(pname) + 1];
    strcpy(name, pname);
    
    patronymic = new char[strlen(ppatronymic) + 1];
    strcpy(patronymic, ppatronymic);
    
    objectCount++;
}

Person::Person() : Person(0, "Иванов", "Иван", "Иванович", Date(1, 1, 2000)) {}

Person::Person(const Person& other) 
    : id(other.id), birthDate(other.birthDate) {
    
    surname = new char[strlen(other.surname) + 1];
    strcpy(surname, other.surname);
    
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    
    patronymic = new char[strlen(other.patronymic) + 1];
    strcpy(patronymic, other.patronymic);
    
    objectCount++;
}

Person::~Person() {
    delete[] surname;
    delete[] name;
    delete[] patronymic;
    objectCount--;
}

int Person::getObjectCount() {
    return objectCount;
}

int Person::getId() const { return id; }
const char* Person::getSurname() const { return surname; }
const char* Person::getName() const { return name; }
const char* Person::getPatronymic() const { return patronymic; }
Date Person::getBirthDate() const { return birthDate; }

void Person::setId(int newId) { id = newId; }

void Person::setSurname(const char* newSurname) {
    delete[] surname;
    surname = new char[strlen(newSurname) + 1];
    strcpy(surname, newSurname);
}

void Person::setName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Person::setPatronymic(const char* newPatronymic) {
    delete[] patronymic;
    patronymic = new char[strlen(newPatronymic) + 1];
    strcpy(patronymic, newPatronymic);
}

void Person::setBirthDate(const Date& newDate) {
    birthDate = newDate;
}

void Person::display() const {
    cout << "  ID: " << id << endl;
    cout << "  Фамилия: " << surname << endl;
    cout << "  Имя: " << name << endl;
    cout << "  Отчество: " << patronymic << endl;
    cout << "  Дата рождения: ";
    birthDate.display();
    cout << endl;
}