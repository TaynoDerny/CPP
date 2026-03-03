#include "apartment.h"
#include <iostream>
#include <cstring>

using namespace std;

// Конструктор
Apartment::Apartment(int number) 
    : apartmentNumber(number), residentCount(0), residents(nullptr) {}

// Конструктор копирования
Apartment::Apartment(const Apartment& other) 
    : apartmentNumber(other.apartmentNumber), residentCount(other.residentCount) {
    
    if (residentCount > 0) {
        residents = new Person*[residentCount];
        for (int i = 0; i < residentCount; i++) {
            residents[i] = new Person(*(other.residents[i]));
        }
    } else {
        residents = nullptr;
    }
}

// Деструктор
Apartment::~Apartment() {
    for (int i = 0; i < residentCount; i++) {
        delete residents[i];
    }
    delete[] residents;
}

// Оператор присваивания
Apartment& Apartment::operator=(const Apartment& other) {
    if (this != &other) {
        // Очищаем текущие данные
        for (int i = 0; i < residentCount; i++) {
            delete residents[i];
        }
        delete[] residents;
        
        // Копируем новые данные
        apartmentNumber = other.apartmentNumber;
        residentCount = other.residentCount;
        
        if (residentCount > 0) {
            residents = new Person*[residentCount];
            for (int i = 0; i < residentCount; i++) {
                residents[i] = new Person(*(other.residents[i]));
            }
        } else {
            residents = nullptr;
        }
    }
    return *this;
}

// Добавление жильца
void Apartment::addResident(const Person& person) {
    // Создаем новый массив на одного жильца больше
    Person** newResidents = new Person*[residentCount + 1];
    
    // Копируем старых жильцов
    for (int i = 0; i < residentCount; i++) {
        newResidents[i] = residents[i];
    }
    
    // Добавляем нового жильца
    newResidents[residentCount] = new Person(person);
    
    // Освобождаем старый массив (но не самих жильцов)
    delete[] residents;
    
    residents = newResidents;
    residentCount++;
}

// Удаление жильца по индексу
void Apartment::removeResident(int index) {
    if (index < 0 || index >= residentCount) return;
    
    // Удаляем жильца
    delete residents[index];
    
    // Сдвигаем оставшихся жильцов
    for (int i = index; i < residentCount - 1; i++) {
        residents[i] = residents[i + 1];
    }
    
    residentCount--;
    
    // Пересоздаем массив с новым размером
    if (residentCount > 0) {
        Person** newResidents = new Person*[residentCount];
        for (int i = 0; i < residentCount; i++) {
            newResidents[i] = residents[i];
        }
        delete[] residents;
        residents = newResidents;
    } else {
        delete[] residents;
        residents = nullptr;
    }
}

// Удаление жильца по ID
void Apartment::removeResidentById(int id) {
    for (int i = 0; i < residentCount; i++) {
        if (residents[i]->getId() == id) {
            removeResident(i);
            return;
        }
    }
}

// Геттеры
int Apartment::getNumber() const { return apartmentNumber; }
int Apartment::getResidentCount() const { return residentCount; }
Person* Apartment::getResident(int index) const {
    if (index >= 0 && index < residentCount) return residents[index];
    return nullptr;
}

// Сеттер для номера квартиры
void Apartment::setNumber(int number) { apartmentNumber = number; }

// Вывод информации о квартире
void Apartment::display() const {
    cout << "Квартира №" << apartmentNumber << endl;
    cout << "Количество жильцов: " << residentCount << endl;
    for (int i = 0; i < residentCount; i++) {
        cout << "  Жилец " << (i + 1) << ":" << endl;
        residents[i]->display();
    }
}

// Поиск жильца по ID
Person* Apartment::findResidentById(int id) const {
    for (int i = 0; i < residentCount; i++) {
        if (residents[i]->getId() == id) {
            return residents[i];
        }
    }
    return nullptr;
}

// Поиск жильца по фамилии
Person* Apartment::findResidentByName(const char* surname) const {
    for (int i = 0; i < residentCount; i++) {
        if (strcmp(residents[i]->getSurname(), surname) == 0) {
            return residents[i];
        }
    }
    return nullptr;
}