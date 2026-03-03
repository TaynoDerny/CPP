#ifndef PERSON_H
#define PERSON_H

#include "date.cpp"
#include <iostream>

class Person {
private:
    static int objectCount;
    
    int id;
    char* surname;
    char* name;
    char* patronymic;
    Date birthDate;

public:
    // Конструктор с параметрами
    Person(int pid, const char* psurname, const char* pname, 
           const char* ppatronymic, const Date& pbirthDate);
    
    // Конструктор по умолчанию (делегирование)
    Person();
    
    // Конструктор копирования
    Person(const Person& other);
    
    // Деструктор
    ~Person();
    
    // Подсчет созданных экземпляров
    static int getObjectCount();
    
    // Геттеры
    int getId() const;
    const char* getSurname() const;
    const char* getName() const;
    const char* getPatronymic() const;
    Date getBirthDate() const;
    
    // Сеттеры
    void setId(int newId);
    void setSurname(const char* newSurname);
    void setName(const char* newName);
    void setPatronymic(const char* newPatronymic);
    void setBirthDate(const Date& newDate);
    
    // Вывод информации
    void display() const;
};

#endif