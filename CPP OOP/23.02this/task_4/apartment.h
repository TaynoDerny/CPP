#ifndef APARTMENT_H
#define APARTMENT_H

#include "person.h"

class Apartment {
private:
    Person** residents;     // Динамический массив указателей на жильцов
    int residentCount;      // Количество жильцов
    int apartmentNumber;    // Номер квартиры

public:
    // Конструкторы
    Apartment(int number = 0);
    Apartment(const Apartment& other);
    
    // Деструктор
    ~Apartment();
    
    // Оператор присваивания
    Apartment& operator=(const Apartment& other);
    
    // Добавление/удаление жильцов
    void addResident(const Person& person);
    void removeResident(int index);
    void removeResidentById(int id);
    
    // Геттеры
    int getNumber() const;
    int getResidentCount() const;
    Person* getResident(int index) const;
    
    // Сеттеры
    void setNumber(int number);
    
    // Вывод информации
    void display() const;
    
    // Поиск жильца
    Person* findResidentById(int id) const;
    Person* findResidentByName(const char* surname) const;
};

#endif