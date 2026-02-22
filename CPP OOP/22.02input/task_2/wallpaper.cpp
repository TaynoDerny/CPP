#include "wallpaper.h"
#include <cmath>

using namespace std;

Room::Room() {
    name = "";
    length = 0;
    width = 0;
    height = 0;
}

Room::Room(string n, double l, double w, double h) {
    name = n;
    length = l;
    width = w;
    height = h;
}

string Room::getName() {
    return name;
}

double Room::getLength() {
    return length;
}

double Room::getWidth() {
    return width;
}

double Room::getHeight() {
    return height;
}

// Расчет площади стен (периметр * высоту)
double Room::getWallArea() {
    double perimeter = 2 * (length + width);
    return perimeter * height;
}

// ========== Roll ==========
Roll::Roll() {
    name = "";
    length = 0;
    width = 0;
    price = 0;
}

Roll::Roll(string n, double l, double w, double p) {
    name = n;
    length = l;
    width = w;
    price = p;
}

string Roll::getName() {
    return name;
}

double Roll::getLength() {
    return length;
}

double Roll::getWidth() {
    return width;
}

double Roll::getPrice() {
    return price;
}

// Площадь одного рулона
double Roll::getRollArea() {
    return length * width;
}

// Расчет нужного количества рулонов
int Roll::getRollsNeeded(double area) {
    double rollArea = getRollArea();
    if (rollArea <= 0) return 0;
    
    // Округляем вверх до целого числа
    double result = area / rollArea;
    int rolls = (int)result;
    if (result > rolls) {
        rolls = rolls + 1;
    }
    return rolls;
}

//
Apartment::Apartment() {
    roomCount = 0;
}

void Apartment::addRoom(Room room) {
    if (roomCount < MAX_ROOMS) {
        rooms[roomCount] = room;
        roomCount++;
    }
}

Room Apartment::getRoom(int index) {
    if (index >= 0 && index < roomCount) {
        return rooms[index];
    }
    return Room();
}

int Apartment::getRoomCount() {
    return roomCount;
}

// Общая площадь всех стен
double Apartment::getTotalWallArea() {
    double total = 0;
    for (int i = 0; i < roomCount; i++) {
        total = total + rooms[i].getWallArea();
    }
    return total;
}