#ifndef HOUSE_H
#define HOUSE_H

#include "apartment.h"

class House {
private:
    Apartment** apartments;  // Динамический массив указателей на квартиры
    int apartmentCount;      // Количество квартир
    int houseNumber;         // Номер дома
    char* address;           // Адрес дома (динамическая память)

public:
    // Конструкторы
    House(int number, const char* addr);
    House(const House& other);
    
    // Деструктор
    ~House();
    
    // Оператор присваивания
    House& operator=(const House& other);
    
    // Управление квартирами
    void addApartment(const Apartment& apt);
    void removeApartment(int number);
    void removeApartmentByIndex(int index);
    
    // Геттеры
    int getHouseNumber() const;
    const char* getAddress() const;
    int getApartmentCount() const;
    Apartment* getApartment(int index) const;
    
    // Поиск
    Apartment* findApartment(int number) const;
    Apartment* findApartmentByResident(int personId) const;
    
    // Вывод информации
    void display() const;
    
    // Статистика
    int getTotalResidents() const;
    void printStatistics() const;
};

#endif