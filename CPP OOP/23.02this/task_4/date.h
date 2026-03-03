#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2000);
    
    void display() const;
    
    // Геттеры
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    // Сеттеры
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};

#endif