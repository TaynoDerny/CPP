#pragma once


#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    string name;
public:
    Room(string name);
    ~Room();
    void printInfo() const;
};

