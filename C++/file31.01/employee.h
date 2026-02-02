#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

struct Employee {
    string lastName;
    int age;
};

// Константы
const int MAX_SIZE = 100;
extern Employee employees[];
extern int employeeCount;

// Функции для работы с данными
void saveToFile();
void loadFromFile();
void addEmployee();
void showAll();
void searchByAge();
void searchByLetter();
void deleteEmployee();
void editEmployee();

#endif