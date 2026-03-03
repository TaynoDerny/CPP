#include "house.h"
#include <cstring>
#include <iostream>

using namespace std;

// Конструктор
House::House(int number, const char* addr) 
    : houseNumber(number), apartmentCount(0), apartments(nullptr) {
    address = new char[strlen(addr) + 1];
    strcpy(address, addr);
}

// Конструктор копирования
House::House(const House& other) 
    : houseNumber(other.houseNumber), apartmentCount(other.apartmentCount) {
    
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
    
    if (apartmentCount > 0) {
        apartments = new Apartment*[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            apartments[i] = new Apartment(*(other.apartments[i]));
        }
    } else {
        apartments = nullptr;
    }
}

// Деструктор
House::~House() {
    for (int i = 0; i < apartmentCount; i++) {
        delete apartments[i];
    }
    delete[] apartments;
    delete[] address;
}

// Оператор присваивания
House& House::operator=(const House& other) {
    if (this != &other) {
        // Очищаем текущие данные
        for (int i = 0; i < apartmentCount; i++) {
            delete apartments[i];
        }
        delete[] apartments;
        delete[] address;
        
        // Копируем новые данные
        houseNumber = other.houseNumber;
        apartmentCount = other.apartmentCount;
        
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
        
        if (apartmentCount > 0) {
            apartments = new Apartment*[apartmentCount];
            for (int i = 0; i < apartmentCount; i++) {
                apartments[i] = new Apartment(*(other.apartments[i]));
            }
        } else {
            apartments = nullptr;
        }
    }
    return *this;
}

// Добавление квартиры
void House::addApartment(const Apartment& apt) {
    // Создаем новый массив на одну квартиру больше
    Apartment** newApartments = new Apartment*[apartmentCount + 1];
    
    // Копируем старые квартиры
    for (int i = 0; i < apartmentCount; i++) {
        newApartments[i] = apartments[i];
    }
    
    // Добавляем новую квартиру
    newApartments[apartmentCount] = new Apartment(apt);
    
    // Освобождаем старый массив
    delete[] apartments;
    
    apartments = newApartments;
    apartmentCount++;
}

// Удаление квартиры по номеру
void House::removeApartment(int number) {
    for (int i = 0; i < apartmentCount; i++) {
        if (apartments[i]->getNumber() == number) {
            removeApartmentByIndex(i);
            return;
        }
    }
}

// Удаление квартиры по индексу
void House::removeApartmentByIndex(int index) {
    if (index < 0 || index >= apartmentCount) return;
    
    // Удаляем квартиру
    delete apartments[index];
    
    // Сдвигаем оставшиеся квартиры
    for (int i = index; i < apartmentCount - 1; i++) {
        apartments[i] = apartments[i + 1];
    }
    
    apartmentCount--;
    
    // Пересоздаем массив с новым размером
    if (apartmentCount > 0) {
        Apartment** newApartments = new Apartment*[apartmentCount];
        for (int i = 0; i < apartmentCount; i++) {
            newApartments[i] = apartments[i];
        }
        delete[] apartments;
        apartments = newApartments;
    } else {
        delete[] apartments;
        apartments = nullptr;
    }
}

// Геттеры
int House::getHouseNumber() const { return houseNumber; }
const char* House::getAddress() const { return address; }
int House::getApartmentCount() const { return apartmentCount; }
Apartment* House::getApartment(int index) const {
    if (index >= 0 && index < apartmentCount) return apartments[index];
    return nullptr;
}

// Поиск квартиры по номеру
Apartment* House::findApartment(int number) const {
    for (int i = 0; i < apartmentCount; i++) {
        if (apartments[i]->getNumber() == number) {
            return apartments[i];
        }
    }
    return nullptr;
}

// Поиск квартиры по жильцу
Apartment* House::findApartmentByResident(int personId) const {
    for (int i = 0; i < apartmentCount; i++) {
        if (apartments[i]->findResidentById(personId) != nullptr) {
            return apartments[i];
        }
    }
    return nullptr;
}

// Вывод информации о доме
void House::display() const {
    cout << "\n=== Дом №" << houseNumber << " ===" << endl;
    cout << "Адрес: " << address << endl;
    cout << "Количество квартир: " << apartmentCount << endl;
    cout << "Всего жильцов: " << getTotalResidents() << endl;
    cout << "========================\n" << endl;
    
    for (int i = 0; i < apartmentCount; i++) {
        apartments[i]->display();
        cout << "------------------------\n" << endl;
    }
}

// Подсчет общего количества жильцов
int House::getTotalResidents() const {
    int total = 0;
    for (int i = 0; i < apartmentCount; i++) {
        total += apartments[i]->getResidentCount();
    }
    return total;
}

// Вывод статистики
void House::printStatistics() const {
    cout << "\n=== СТАТИСТИКА ДОМА №" << houseNumber << " ===" << endl;
    cout << "Адрес: " << address << endl;
    cout << "Всего квартир: " << apartmentCount << endl;
    cout << "Всего жильцов: " << getTotalResidents() << endl;
    
    if (apartmentCount > 0) {
        int maxResidents = 0;
        int minResidents = 1000;
        int maxApartment = 0;
        int minApartment = 0;
        
        for (int i = 0; i < apartmentCount; i++) {
            int count = apartments[i]->getResidentCount();
            if (count > maxResidents) {
                maxResidents = count;
                maxApartment = apartments[i]->getNumber();
            }
            if (count < minResidents) {
                minResidents = count;
                minApartment = apartments[i]->getNumber();
            }
        }
        
        cout << "Самая населенная квартира: №" << maxApartment 
             << " (" << maxResidents << " жильцов)" << endl;
        cout << "Наименее населенная квартира: №" << minApartment 
             << " (" << minResidents << " жильцов)" << endl;
    }
}