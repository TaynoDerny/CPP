#include "employee.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Глобальные переменные для хранения данных
Employee employees[MAX_SIZE];  // массив сотрудников
int employeeCount = 0;         // текущее количество сотрудников

// функция сохранения данных в файл
void saveToFile() {
    ofstream file("employees.txt");  // открытие файла для записи
    
    // запись всех сотрудников в файл
    for (int i = 0; i < employeeCount; i++) {
        file << employees[i].lastName << " " << employees[i].age << endl;
    }
    
    file.close();  // закрытие файла
    cout << "Данные сохранены!\n";
}

// функция загрузки данных из файла
void loadFromFile() {
    ifstream file("employees.txt");  // открытие файла для чтения
    
    employeeCount = 0;  // сброс счетчика
    
    // чтение данных из файла
    while (file >> employees[employeeCount].lastName >> employees[employeeCount].age && 
           employeeCount < MAX_SIZE) {
        employeeCount++;  // увеличение счетчика сотрудников
    }
    
    file.close();  // закрытие файла
    cout << "Загружено сотрудников: " << employeeCount << endl;
}

// функция добавления нового сотрудника
void addEmployee() {
    // проверка места в массиве
    if (employeeCount >= MAX_SIZE) {
        cout << "Нет места!\n";
        return;
    }
    
    // ввод данных нового сотрудника
    cout << "Фамилия: ";
    cin >> employees[employeeCount].lastName;
    cout << "Возраст: ";
    cin >> employees[employeeCount].age;
    
    employeeCount++;  // увеличение счетчика сотрудников
    cout << "Добавлен!\n";
}

// функция отображения всех сотрудников
void showAll() {
    cout << "\nВсе сотрудники:\n";
    
    // вывод информации о каждом сотруднике
    for (int i = 0; i < employeeCount; i++) {
        cout << i+1 << ". " << employees[i].lastName 
             << ", возраст: " << employees[i].age << endl;
    }
}

// функция поиска сотрудников по возрасту
void searchByAge() {
    int age;
    cout << "Возраст для поиска: ";
    cin >> age;
    
    cout << "\nРезультаты:\n";
    bool found = false;  // флаг найденных сотрудников
    
    // поиск сотрудников с указанным возрастом
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].age == age) {
            cout << employees[i].lastName << " (" << employees[i].age << " лет)\n";
            found = true;  // найден хотя бы один
        }
    }
    
    // если никого не найдено
    if (!found) cout << "Не найдено\n";
}

// функция поиска сотрудников по первой букве фамилии
void searchByLetter() {
    char letter;
    cout << "Первая буква фамилии: ";
    cin >> letter;
    
    cout << "\nРезультаты:\n";
    bool found = false;  // флаг найденных сотрудников
    
    // поиск сотрудников по первой букве фамилии
    for (int i = 0; i < employeeCount; i++) {
        // проверка первой буквы фамилии
        if (!employees[i].lastName.empty() && 
            tolower(employees[i].lastName[0]) == tolower(letter)) {
            cout << employees[i].lastName << " (" << employees[i].age << " лет)\n";
            found = true;  // найден хотя бы один
        }
    }
    
    // если никого не найдено
    if (!found) cout << "Не найдено\n";
}

// функция удаления сотрудника
void deleteEmployee() {
    string lastName;
    cout << "Фамилия для удаления: ";
    cin >> lastName;
    
    // поиск сотрудника с указанной фамилией
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].lastName == lastName) {
            // сдвиг элементов массива после удаляемого
            for (int j = i; j < employeeCount-1; j++) {
                employees[j] = employees[j+1];
            }
            
            employeeCount--;  // уменьшение счетчика сотрудников
            cout << "Удален!\n";
            return;  // выход из функции
        }
    }
    
    // если сотрудник не найден
    cout << "Не найден!\n";
}

// функция редактирования данных сотрудника
void editEmployee() {
    string lastName;
    cout << "Фамилия для редактирования: ";
    cin >> lastName;
    
    // поиск сотрудника с указанной фамилией
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].lastName == lastName) {
            // ввод новых данных
            cout << "Новая фамилия: ";
            cin >> employees[i].lastName;
            cout << "Новый возраст: ";
            cin >> employees[i].age;
            
            cout << "Изменен!\n";
            return;  // выход из функции
        }
    }
    
    // если сотрудник не найден
    cout << "Не найден!\n";
}