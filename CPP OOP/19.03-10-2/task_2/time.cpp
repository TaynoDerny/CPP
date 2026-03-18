#include "time.h"

// Нормализация времени
void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (seconds < 0) {
        int borrow = (-seconds + 59) / 60;
        minutes -= borrow;
        seconds += borrow * 60;
    }
    
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (minutes < 0) {
        int borrow = (-minutes + 59) / 60;
        hours -= borrow;
        minutes += borrow * 60;
    }
    
    if (hours < 0) hours = 0;
    hours %= 24; // ограничиваем 24 часами
}

// Конструкторы
Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

// Правило 5
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

Time::Time(Time&& other) noexcept : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
    other.hours = 0;
    other.minutes = 0;
    other.seconds = 0;
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time& Time::operator=(Time&& other) noexcept {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        other.hours = 0;
        other.minutes = 0;
        other.seconds = 0;
    }
    return *this;
}

Time::~Time() {}

// Функция приращения на 1 секунду
void Time::addSecond() {
    seconds++;
    normalize();
}

// Геттеры
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

// Преобразование в секунды
int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

// () — общее количество секунд
int Time::operator()() const {
    return toSeconds();
}

// Префиксный ++
Time& Time::operator++() {
    addSecond();
    return *this;
}

// Постфиксный ++
Time Time::operator++(int) {
    Time temp(*this);
    addSecond();
    return temp;
}

// Префиксный --
Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}

// Постфиксный --
Time Time::operator--(int) {
    Time temp(*this);
    seconds--;
    normalize();
    return temp;
}

// +=
Time& Time::operator+=(int sec) {
    seconds += sec;
    normalize();
    return *this;
}

// -=
Time& Time::operator-=(int sec) {
    seconds -= sec;
    normalize();
    return *this;
}

// Сравнения
bool Time::operator==(const Time& other) const {
    return toSeconds() == other.toSeconds();
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    return toSeconds() > other.toSeconds();
}

bool Time::operator<(const Time& other) const {
    return toSeconds() < other.toSeconds();
}

// Дружественные операторы ввода/вывода
ostream& operator<<(ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
       << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
       << (t.seconds < 10 ? "0" : "") << t.seconds;
    return os;
}

istream& operator>>(istream& is, Time& t) {
    cout << "Часы: ";
    is >> t.hours;
    cout << "Минуты: ";
    is >> t.minutes;
    cout << "Секунды: ";
    is >> t.seconds;
    t.normalize();
    return is;
}
