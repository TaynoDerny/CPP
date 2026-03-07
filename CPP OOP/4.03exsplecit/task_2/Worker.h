#pragma once
#include <string>
using namespace std;

class Worker
{
private:
    string last_name, first_name, patronymic;
    string job_title;
    int year_of_work;
    int salary;
public:
    // Конструкторы
    Worker(string last_name, string first_name, string patronymic);
    Worker(string last_name, string first_name, string patronymic, string job_title, int year_of_work, int salary);
    explicit Worker(string job_title);  // <-- explicit конструктор (только должность)
    
    // Сеттеры
    void setLast_name(string last_name);
    void setFirst_name(string first_name);
    void setPatronymic(string patronymic);
    void setJob_title(string job_title);
    void setYear_of_work(int year_of_work);
    void setSalary(int salary);
    
    // Геттеры
    string getLast_name() const;
    string getFirst_name() const;
    string getPatronymic() const;
    string getJob_title() const;
    int getYear_of_work() const;
    int getSalary() const;  // добавьте определение в .cpp
};

