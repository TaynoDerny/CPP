#include "phonebook.h"
#include <cstdlib>

using namespace std;

//КЛАСС ABONENT

// Конструктор по умолчанию
Abonent::Abonent() : fullName(""), homePhone(""), workPhone(""),mobilePhone(""), additionalInfo("") {
    cout << "Конструктор по умолчанию вызван" << endl;
}

// Конструктор с параметрами
Abonent::Abonent(const string& name, const string& home, const string& work,const string& mobile, const string& info): fullName(name), homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(info) {
    cout << "Конструктор с параметрами вызван для: " << (name.empty() ? "Без имени" : name) << endl;
}

// Конструктор копирования
Abonent::Abonent(const Abonent& other): fullName(other.fullName), homePhone(other.homePhone), workPhone(other.workPhone), mobilePhone(other.mobilePhone),additionalInfo(other.additionalInfo) {
    cout << "Конструктор копирования вызван" << endl;
}

// Деструктор
Abonent::~Abonent() {
    cout << "Деструктор вызван для: " << (fullName.empty() ? "Без имени" : fullName) << endl;
}

// Геттеры
inline string Abonent::getFullName() const { return fullName; }
inline string Abonent::getHomePhone() const { return homePhone; }
inline string Abonent::getWorkPhone() const { return workPhone; }
inline string Abonent::getMobilePhone() const { return mobilePhone; }
inline string Abonent::getAdditionalInfo() const { return additionalInfo; }

// Сеттеры
void Abonent::setFullName(const string& name) { fullName = name; }
void Abonent::setHomePhone(const string& phone) { homePhone = phone; }
void Abonent::setWorkPhone(const string& phone) { workPhone = phone; }
void Abonent::setMobilePhone(const string& phone) { mobilePhone = phone; }
void Abonent::setAdditionalInfo(const string& info) { additionalInfo = info; }

// Отображение
void Abonent::display() const {
    cout << "\n=== Информация об абоненте ===" << endl;
    cout << "ФИО: " << (fullName.empty() ? "Не указано" : fullName) << endl;
    cout << "Домашний телефон: " << (homePhone.empty() ? "Не указан" : homePhone) << endl;
    cout << "Рабочий телефон: " << (workPhone.empty() ? "Не указан" : workPhone) << endl;
    cout << "Мобильный телефон: " << (mobilePhone.empty() ? "Не указан" : mobilePhone) << endl;
    cout << "Дополнительная информация: " << (additionalInfo.empty() ? "Нет" : additionalInfo) << endl;
}

// КЛАСС PHONEBOOK 

// Конструктор
PhoneBook::PhoneBook() : count(0), capacity(10) {
    abonents = new Abonent*[capacity];
    for (int i = 0; i < capacity; i++) {
        abonents[i] = nullptr;
    }
    cout << "Телефонная книга создана, вместимость: " << capacity << endl;
}

// Деструктор
PhoneBook::~PhoneBook() {
    clear();
    delete[] abonents;
    cout << "Телефонная книга удалена" << endl;
}

// Очистка
void PhoneBook::clear() {
    for (int i = 0; i < count; i++) {
        delete abonents[i];
        abonents[i] = nullptr;
    }
    count = 0;
}

// Геттеры
inline int PhoneBook::getCount() const { return count; }
inline int PhoneBook::getCapacity() const { return capacity; }

// Увеличение массива
void PhoneBook::resize() {
    int newCapacity = capacity * 2;
    Abonent** newAbonents = new Abonent*[newCapacity];
    

    for (int i = 0; i < count; i++) {
        newAbonents[i] = abonents[i];
    }
  
    for (int i = count; i < newCapacity; i++) {
        newAbonents[i] = nullptr;
    }
    
    delete[] abonents;
    abonents = newAbonents;
    capacity = newCapacity;
    
    cout << "Вместимость увеличена до: " << capacity << endl;
}

// Добавление
void PhoneBook::addAbonent() {
    if (count >= capacity) {
        resize();
    }
    
    string name, home, work, mobile, info;
    
    cin.ignore();
    
    cout << "\n=== Добавление нового абонента ===" << endl;
    cout << "Введите ФИО: ";
    getline(cin, name);
    
    cout << "Введите домашний телефон: ";
    getline(cin, home);
    
    cout << "Введите рабочий телефон: ";
    getline(cin, work);
    
    cout << "Введите мобильный телефон: ";
    getline(cin, mobile);
    
    cout << "Введите дополнительную информацию: ";
    getline(cin, info);
    
    abonents[count] = new Abonent(name, home, work, mobile, info);
    count++;
    
    cout << "Абонент успешно добавлен! Всего: " << count << endl;
}

// Удаление
void PhoneBook::removeAbonent() {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    displayAll();
    
    int index;
    cout << "\nВведите номер абонента для удаления (1-" << count << "): ";
    cin >> index;
    
    if (index >= 1 && index <= count) {
        delete abonents[index - 1];
        
        for (int i = index - 1; i < count - 1; i++) {
            abonents[i] = abonents[i + 1];
        }
        abonents[count - 1] = nullptr;
        count--;
        
        cout << "Абонент удален! Осталось: " << count << endl;
    } else {
        cout << "Неверный номер!" << endl;
    }
}

// Поиск
void PhoneBook::searchByFullName() {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    cin.ignore();
    
    string searchName;
    cout << "\nВведите ФИО для поиска: ";
    getline(cin, searchName);
    
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (abonents[i]->getFullName() == searchName) {
            cout << "\n----- Абонент #" << i + 1 << " -----";
            abonents[i]->display();
            found = true;
        }
    }
    
    if (!found) {
        cout << "Абонент с ФИО \"" << searchName << "\" не найден!" << endl;
    }
}

// Показать всех
void PhoneBook::displayAll() const {
    if (count == 0) {
        cout << "Телефонная книга пуста!" << endl;
        return;
    }
    
    cout << "\n=== Список всех абонентов (" << count << ") ===" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\n----- Абонент #" << i + 1 << " -----";
        abonents[i]->display();
    }
}

// Сохранение
void PhoneBook::saveToFile() {
    if (count == 0) {
        cout << "Телефонная книга пуста, нечего сохранять!" << endl;
        return;
    }
    
    string filename;
    cout << "Введите имя файла для сохранения: ";
    cin >> filename;
    
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        file << abonents[i]->getFullName() << endl;
        file << abonents[i]->getHomePhone() << endl;
        file << abonents[i]->getWorkPhone() << endl;
        file << abonents[i]->getMobilePhone() << endl;
        file << abonents[i]->getAdditionalInfo() << endl;
        file << "---" << endl;
    }
    
    file.close();
    cout << "Данные сохранены в файл \"" << filename << "\"" << endl;
}

// Загрузка
void PhoneBook::loadFromFile() {
    string filename;
    cout << "Введите имя файла для загрузки: ";
    cin >> filename;
    
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }
    
    clear();
    
    string name, home, work, mobile, info, separator;
    
    while (getline(file, name)) {
        // Если нужно увеличить массив
        if (count >= capacity) {
            resize();
        }
        
        getline(file, home);
        getline(file, work);
        getline(file, mobile);
        getline(file, info);
        getline(file, separator);
        
        abonents[count] = new Abonent(name, home, work, mobile, info);
        count++;
    }
    
    file.close();
    cout << "Загружено " << count << " абонентов из файла \"" << filename << "\"" << endl;
}