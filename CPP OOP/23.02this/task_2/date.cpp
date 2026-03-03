#include "date.h"
#include <iostream>

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::display() const {
    cout << (day < 10 ? "0" : "") << day << "."
         << (month < 10 ? "0" : "") << month << "."
         << year;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }