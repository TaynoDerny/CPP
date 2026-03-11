#include "time.h"
#include <iomanip>

using namespace std;

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

void Time::normalize() {
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (seconds < 0) {
        int mins = (-seconds + 59) / 60;
        minutes -= mins;
        seconds += mins * 60;
    }
    
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (minutes < 0) {
        int hrs = (-minutes + 59) / 60;
        hours -= hrs;
        minutes += hrs * 60;
    }
    
    if (hours >= 24) {
        hours %= 24;
    }
    if (hours < 0) {
        hours = (hours % 24 + 24) % 24;
    }
}

void Time::addSecond() {
    seconds++;
    normalize();
}

istream& operator>>(istream& in, Time& t) {
    in >> t.hours >> t.minutes >> t.seconds;
    t.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << setfill('0') << setw(2) << t.hours << ":"
        << setw(2) << t.minutes << ":"
        << setw(2) << t.seconds;
    return out;
}

Time& Time::operator++() {
    addSecond();
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    addSecond();
    return temp;
}

Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    seconds--;
    normalize();
    return temp;
}

bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    if (hours != other.hours) return hours > other.hours;
    if (minutes != other.minutes) return minutes > other.minutes;
    return seconds > other.seconds;
}

bool Time::operator<(const Time& other) const {
    if (hours != other.hours) return hours < other.hours;
    if (minutes != other.minutes) return minutes < other.minutes;
    return seconds < other.seconds;
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time& Time::operator+=(int sec) {
    seconds += sec;
    normalize();
    return *this;
}

Time& Time::operator-=(int sec) {
    seconds -= sec;
    normalize();
    return *this;
}

int Time::operator()() const {
    return hours * 3600 + minutes * 60 + seconds;
}
