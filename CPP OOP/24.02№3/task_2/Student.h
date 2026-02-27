#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    char* fullName;  // Динамическая память для ФИО
    static int count; // Статический счетчик объектов
    
    string birthday;
    string phone_number;
    string city;
    string country;
    string name_college;
    string city_college;
    string number_group;
    
    void CopyFullName(const char* name);
    void InitDefaults();  // Вспомогательный метод для инициализации по умолчанию
    
public:
    // Конструкторы с делегированием
    Student();                                              // Конструктор по умолчанию
    Student(const char* FullName);                          // Конструктор только с ФИО
    Student(const char* FullName, const string& Birthday);  // Конструктор с ФИО и датой
    Student(const char* FullName, const string& Birthday,   // Полный конструктор
            const string& Phone, const string& City,
            const string& Country, const string& College,
            const string& CollegeCity, const string& Group);
    Student(const Student& other);                           // Конструктор копирования
    
    // Деструктор
    ~Student();
    
    // Статический метод для получения количества объектов
    static inline int GetCount() { return count; }
    
    // inline методы для простых полей
    inline string GetBirthday() const { return birthday; }
    inline string GetPhone_number() const { return phone_number; }
    inline string GetCity() const { return city; }
    inline string GetCountry() const { return country; }
    inline string GetName_college() const { return name_college; }
    inline string GetCity_college() const { return city_college; }
    inline string GetNumber_group() const { return number_group; }
    
    inline void SetBirthday(const string& Birthday) { birthday = Birthday; }
    inline void SetPhone_number(const string& Phone) { phone_number = Phone; }
    inline void SetCity(const string& City) { city = City; }
    inline void SetCountry(const string& Country) { country = Country; }
    inline void SetName_college(const string& College) { name_college = College; }
    inline void SetCity_college(const string& CollegeCity) { city_college = CollegeCity; }
    inline void SetNumber_group(const string& Group) { number_group = Group; }
    
    // Методы для работы с ФИО
    const char* GetFullName() const;
    void SetFullName(const char* FullName);
    void SetSurname(const char* Surname);
    void SetName(const char* Name);
    void SetPatronymic(const char* Patronymic);
    
    void PrintStudent() const;
    
    // Оператор присваивания
    Student& operator=(const Student& other);
};