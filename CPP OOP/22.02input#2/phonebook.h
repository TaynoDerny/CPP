#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Класс Абонент
class Abonent {
private:
    string fullName;          // ФИО
    string homePhone;          // Домашний телефон
    string workPhone;          // Рабочий телефон
    string mobilePhone;        // Мобильный телефон
    string additionalInfo;     // Дополнительная информация

public:
    // Конструкторы
    Abonent();                                
    Abonent(const string& name, const string& home, const string& work, 
            const string& mobile, const string& info); 
    Abonent(const Abonent& other);              
    
    // Деструктор
    ~Abonent();
    
    // Геттеры
    string getFullName() const;
    string getHomePhone() const;
    string getWorkPhone() const;
    string getMobilePhone() const;
    string getAdditionalInfo() const;
    
    // Сеттеры
    void setFullName(const string& name);
    void setHomePhone(const string& phone);
    void setWorkPhone(const string& phone);
    void setMobilePhone(const string& phone);
    void setAdditionalInfo(const string& info);
    
    // Методы
    void display() const;                          
};

// Класс Телефонная книга
class PhoneBook {
private:
    Abonent** abonents;  // Динамический массив указателей
    int count;           // Текущее количество
    int capacity;        // Вместимость

public:
    // Конструктор и деструктор
    PhoneBook();
    ~PhoneBook();
    
    // Методы
    void addAbonent();                          
    void removeAbonent();                        
    void searchByFullName();                      
    void displayAll() const;                      
    void saveToFile();                            
    void loadFromFile();                           
    void clear();                                  
    
    // Геттеры
    int getCount() const;
    int getCapacity() const;
    
private:
    void resize(); // Увеличение массива
};
