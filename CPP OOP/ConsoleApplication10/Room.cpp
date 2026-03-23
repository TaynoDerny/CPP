#include "Room.h"
using namespace std;

Room::Room(string name) : name(name) {
    cout << "Комната \"" << name << "\" создана." << endl;
}

Room::~Room() {
    cout << "Комната \"" << name << "\" уничтожена." << endl;
}

void Room::printInfo() const {
    cout << "  - " << name << endl;
}