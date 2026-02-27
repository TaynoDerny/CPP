#include "Student.h"
#include <cstring>

// Инициализация статического счетчика
int Student::count = 0;

// Вспомогательный метод для инициализации полей по умолчанию
void Student::InitDefaults() {
    birthday = "";
    phone_number = "";
    city = "";
    country = "";
    name_college = "";
    city_college = "";
    number_group = "";
}

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

// Конструктор по умолчанию делегирует конструктору с ФИО
Student::Student() : Student("Неизвестно") {
    cout << "Конструктор Student по умолчанию (делегирование)" << endl;
}

// Конструктор только с ФИО делегирует полному конструктору
Student::Student(const char* FullName) : Student(FullName, "", "", "", "", "", "", "") {
    cout << "Конструктор Student только с ФИО (делегирование)" << endl;
}

// Конструктор с ФИО и датой делегирует полному конструктору
Student::Student(const char* FullName, const string& Birthday) 
    : Student(FullName, Birthday, "", "", "", "", "", "") {
    cout << "Конструктор Student с ФИО и датой (делегирование)" << endl;
}

// Полный конструктор
Student::Student(const char* FullName, const string& Birthday,
                 const string& Phone, const string& City,
                 const string& Country, const string& College,
                 const string& CollegeCity, const string& Group)
    : fullName(nullptr), birthday(Birthday), phone_number(Phone),
      city(City), country(Country), name_college(College),
      city_college(CollegeCity), number_group(Group) {
    
    count++;  // Увеличиваем счетчик при создании
    cout << "Полный конструктор Student. Всего объектов: " << count << endl;
    
    CopyFullName(FullName);
}

// Конструктор копирования делегирует полному конструктору
Student::Student(const Student& other)
    : Student(other.fullName, other.birthday, other.phone_number,
              other.city, other.country, other.name_college,
              other.city_college, other.number_group) {
    cout << "Конструктор копирования Student (делегирование)" << endl;
}

// Деструктор
Student::~Student() {
    count--;  // Уменьшаем счетчик при удалении
    cout << "Деструктор Student. Осталось объектов: " << count << endl;
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
    
    char* temp = new char[strlen(fullName) + 1];
    strcpy(temp, fullName);
    
    surname = temp;
    
    char* space1 = strchr(surname, ' ');
    if (space1) {
        *space1 = '\0';
        name = space1 + 1;
        
        char* space2 = strchr(name, ' ');
        if (space2) {
            *space2 = '\0';
            patronymic = space2 + 1;
        }
    }
}

// Установка фамилии
void Student::SetSurname(const char* Surname) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    string newFullName = Surname;
    if (name) {
        newFullName += " ";
        newFullName += name;
    }
    if (patronymic) {
        newFullName += " ";
        newFullName += patronymic;
    }
    
    delete[] surname;
    SetFullName(newFullName.c_str());
}

// Установка имени
void Student::SetName(const char* Name) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    string newFullName = surname ? surname : "";
    newFullName += " ";
    newFullName += Name;
    if (patronymic) {
        newFullName += " ";
        newFullName += patronymic;
    }
    
    delete[] surname;
    SetFullName(newFullName.c_str());
}

// Установка отчества
void Student::SetPatronymic(const char* Patronymic) {
    char* surname = nullptr;
    char* name = nullptr;
    char* patronymic = nullptr;
    
    ParseFullName(fullName, surname, name, patronymic);
    
    string newFullName = surname ? surname : "";
    newFullName += " ";
    newFullName += name ? name : "";
    newFullName += " ";
    newFullName += Patronymic;
    
    delete[] surname;
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