#pragma once


#include "Room.h"
#include <vector>
#include <string>
using namespace std;

class House {
private:
    string address;
    vector<Room> rooms; // Композиция: храним объекты по значению

public:
    House(string address, vector<string> roomNames);
    ~House();
    void printInfo() const;
};

