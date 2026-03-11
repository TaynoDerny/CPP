#pragma once
#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    
    void normalize();

public:
    Time();
    Time(int h, int m, int s);
    
    void addSecond();
    
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
    
    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);
    
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;
    
    Time& operator=(const Time& other);
    Time& operator+=(int sec);
    Time& operator-=(int sec);
    
    int operator()() const;
};
