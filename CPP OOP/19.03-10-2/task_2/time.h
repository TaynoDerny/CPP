#pragma once
#include <iostream>
using namespace std;

class Time {
    int hours, minutes, seconds;
    
    void normalize(); // нормализация времени (60 сек = 1 мин и т.д.)
public:
    // Конструкторы
    Time();
    Time(int h, int m, int s);

    // Правило 5
    Time(const Time& other);
    Time(Time&& other) noexcept;
    Time& operator=(const Time& other);
    Time& operator=(Time&& other) noexcept;
    ~Time();

    // Функция приращения на 1 секунду
    void addSecond();

    // Геттеры
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Преобразование в секунды для сравнения
    int toSeconds() const;

    // () — возвращает общее количество секунд
    int operator()() const;

    // Обычная перегрузка (методы)
    Time& operator++();      // префиксный ++
    Time operator++(int);    // постфиксный ++
    Time& operator--();      // префиксный --
    Time operator--(int);    // постфиксный --
    
    Time& operator+=(int sec);
    Time& operator-=(int sec);
    
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;

    // Дружественная перегрузка
    friend ostream& operator<<(ostream& os, const Time& t);
    friend istream& operator>>(istream& is, Time& t);
};
