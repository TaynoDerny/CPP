#include "Student.h"
#include <cstring>
using namespace std;

// Вспомогательный метод для копирования строки в динамическую память
void Student::CopyFullName(const char* name) {
    if (name) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    } else {
        fullName = new char[1];
        fullName[0] = '\0';
    }
}

// Конструктор по умолчанию с инициализатором
Student::Student() 
    : fullName(nullptr), birthday(""), phone_number(""), city(""), 
      country(""), name_college(""), city_college(""), number_group("") {
    cout << "Конструктор Student по умолчанию" << endl;
    CopyFullName("Неизвестно");
}

// Конструктор с параметрами с инициализатором
Student::Student(const char* FullName, const string& Birthday,
                 const string& Phone, const string& City,
                 const string& Country, const string& College,
                 const string& CollegeCity, const string& Group)
    : fullName(nullptr), birthday(Birthday), phone_number(Phone),
      city(City), country(Country), name_college(College),
      city_college(CollegeCity), number_group(Group) {
    cout << "Конструктор Student с параметрами" << endl;
    CopyFullName(FullName);
}

// Конструктор копирования с инициализатором
Student::Student(const Student& other)
    : fullName(nullptr), birthday(other.birthday), phone_number(other.phone_number),
      city(other.city), country(other.country), name_college(other.name_college),
      city_college(other.city_college), number_group(other.number_group) {
    cout << "Конструктор копирования Student" << endl;
    CopyFullName(other.fullName);
}

// Деструктор
Student::~Student() {
    cout << "Деструктор Student" << endl;
    delete[] fullName;
}

// Оператор присваивания
Student& Student::operator=(const Student& other) {
    cout << "Оператор присваивания Student" << endl;
    if (this != &other) {
        birthday = other.birthday;
        phone_number = other.phone_number;
        city = other.city;
        country = other.country;
        name_college = other.name_college;
        city_college = other.city_college;
        number_group = other.number_group;
        
        delete[] fullName;
        CopyFullName(other.fullName);
    }
    return *this;
}

// Получение ФИО
const char* Student::GetFullName() const {
    return fullName;
}

// Установка полного ФИО
void Student::SetFullName(const char* FullName) {
    delete[] fullName;
    CopyFullName(FullName);
}

// Вспомогательная функция для поиска пробелов
void ParseFullName(const char* fullName, char*& surname, char*& name, char*& patronymic) {
    surname = nullptr;
    name = nullptr;
    patronymic = nullptr;
    
    if (!fullName) return;
    
    // Создаем копию строки для разбора
    char* temp = new char[strlen(fullName) + 1];
    strcpy(temp, fullName);
    
    // Разбиваем по пробелам
    surname = temp;  // Первая часть - фамилия
    
    // Ищем первый пробел
    char* space1 = strchr(surname, ' ');
    if (space1) {
        *space1 = '\0';  // Завершаем фамилию
        name = space1 + 1;  // Следующая часть - имя
        
        // Ищем второй пробел
        char* space2 = strchr(name, ' ');
        if (space2) {
            *space2 = '\0';  // Завершаем имя
            patronymic = space2 + 1;  // Остальное - отчество
        }
    }
}

// Установка фамилии
void Student::SetSurname(const char* Surname) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    // Формируем новое ФИО
    string newFullName = Surname;
    if (name) {
        newFullName += " ";
        newFullName += name;
    }
    if (patronymic) {
        newFullName += " ";
        newFullName += patronymic;
    }
    
    delete[] surname;  // Освобождаем временную память
    SetFullName(newFullName.c_str());
}

// Установка имени
void Student::SetName(const char* Name) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    // Формируем новое ФИО
    string newFullName = surname ? surname : "";
    newFullName += " ";
    newFullName += Name;
    if (patronymic) {
        newFullName += " ";
        newFullName += patronymic;
    }
    
    delete[] surname;  // Освобождаем временную память
    SetFullName(newFullName.c_str());
}

// Установка отчества
void Student::SetPatronymic(const char* Patronymic) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    // Формируем новое ФИО
    string newFullName = surname ? surname : "";
    newFullName += " ";
    newFullName += name ? name : "";
    newFullName += " ";
    newFullName += Patronymic;
    
    delete[] surname;  // Освобождаем временную память
    SetFullName(newFullName.c_str());
}

// Вывод информации о студенте
void Student::PrintStudent() const {
    cout << "ФИО: " << fullName << endl;
    cout << "Дата рождения: " << birthday << endl;
    cout << "Телефон: " << phone_number << endl;
    cout << "Город: " << city << endl;
    cout << "Страна: " << country << endl;
    cout << "Колледж: " << name_college << endl;
    cout << "Город колледжа: " << city_college << endl;
    cout << "Номер группы: " << number_group << endl;
}