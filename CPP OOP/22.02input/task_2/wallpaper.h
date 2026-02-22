#pragma once
#include <string>

using namespace std;

const int MAX_ROOMS = 10;      // Максимум комнат
const int MAX_ROLLS = 5;       // Максимум видов обоев

// КЛАСС Room (Комната)
class Room {
private:
    string name;        // Название комнаты
    double length;      // Длина
    double width;       // Ширина  
    double height;      // Высота

public:
    Room();
    Room(string n, double l, double w, double h);
    
    string getName();
    double getLength();
    double getWidth();
    double getHeight();
    
    // Расчет площади стен
    double getWallArea();
};

// КЛАСС Roll (РулонОбоев)
class Roll {
private:
    string name;        // Название обоев
    double length;      // Длина рулона
    double width;       // Ширина рулона
    double price;       // Цена за рулон

public:
    Roll();
    Roll(string n, double l, double w, double p);
    
    string getName();
    double getLength();
    double getWidth();
    double getPrice();
    
    // Площадь одного рулона
    double getRollArea();
    
    // Расчет нужного количества рулонов
    int getRollsNeeded(double area);
};

// КЛАСС Apartment (Квартира)
class Apartment {
private:
    Room rooms[MAX_ROOMS];
    int roomCount;

public:
    Apartment();
    
    void addRoom(Room room);
    Room getRoom(int index);
    int getRoomCount();
    
    // Общая площадь всех стен
    double getTotalWallArea();
};

