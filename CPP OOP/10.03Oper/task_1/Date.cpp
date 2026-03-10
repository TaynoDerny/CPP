#include "Date.h"
#include <iostream>

using namespace std;

// Конструктор инициализации
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Вывод даты в формате день/месяц/год
void Date::display() const {
    cout << day << "/" << month << "/" << year << endl;
}

// Проверка високосного года
bool Date::isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Количество дней в месяце с учетом високосного года
int Date::daysInMonth(int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y)) return 29; // Февраль в високосном году
    return days[m - 1];
}

// Преобразование даты в юлианский день
int Date::toJulianDay() const {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

// Преобразование юлианского дня обратно в дату
Date Date::fromJulianDay(int jd) {
    int a = jd + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    int day = e - (153 * m + 2) / 5 + 1;
    int month = m + 3 - 12 * (m / 10);
    int year = 100 * b + d - 4800 + m / 10;
    return Date(day, month, year);
}

// Перегрузка оператора - для вычисления разности дат
int Date::operator-(const Date& other) const {
    return toJulianDay() - other.toJulianDay();
}

// Перегрузка оператора + для добавления дней к дате
Date Date::operator+(int days) const {
    return fromJulianDay(toJulianDay() + days);
}