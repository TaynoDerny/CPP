#pragma once

class Date {
private:
    int day;
    int month;
    int year;

    int toJulianDay() const;
    static Date fromJulianDay(int jd);
    static bool isLeapYear(int y);
    static int daysInMonth(int m, int y);

public:
    Date(int d, int m, int y);
    void display() const;
    
    int operator-(const Date& other) const;
    Date operator+(int days) const;
};