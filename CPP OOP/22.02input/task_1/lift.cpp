#include "lift.h"
#include <iostream>

using namespace std;

// Конструктор
// Устанавливает начальные значения: диапазон 1-9, этаж 1, состояние "выключен"
Lift::Lift() {
    minFloor = 1;
    maxFloor = 9;
    currentFloor = 1;
    isWorking = false;
}

// Установка диапазона движения лифта
void Lift::setRange(int minF, int maxF) {
    if (minF < maxF) {
        minFloor = minF;
        maxFloor = maxF;
        cout << "Установлен диапазон: " << minFloor << " - " << maxFloor << " этажи" << endl;
    } else {
        cout << "Ошибка: нижний этаж должен быть меньше верхнего!" << endl;
    }
}

// Включение лифта
void Lift::turnOn() {
    isWorking = true;
    cout << "Лифт включен" << endl;
}

// Выключение лифта
void Lift::turnOff() {
    isWorking = false;
    cout << "Лифт выключен" << endl;
}

// Получение состояния лифта
bool Lift::getState() const {
    return isWorking;
}

// Получение текущего этажа
int Lift::getCurrentFloor() const {
    return currentFloor;
}

// Обработка вызова лифта
void Lift::call(int floor) {
    if (!isWorking) {
        cout << "Лифт не работает! Сначала включите лифт." << endl;
        return;
    }
    
    // Проверка: существует ли такой этаж
    if (floor < minFloor || floor > maxFloor) {
        cout << "Ошибка: этаж " << floor << " вне диапазона (" << minFloor << "-" << maxFloor << ")" << endl;
        return;
    }
    
    // Если лифт уже на этом этаже
    if (currentFloor == floor) {
        cout << "Лифт уже на " << floor << " этаже" << endl;
        return;
    }
    
    // Движение лифта
    cout << "Лифт едет с " << currentFloor << " на " << floor << " этаж";
    
    // Определяем направление движения
    if (floor > currentFloor) {
        cout << " (вверх)";
    } else {
        cout << " (вниз)";
    }
    cout << endl;
    
    // Имитация движения 
    currentFloor = floor;
    cout << "Лифт прибыл на " << currentFloor << " этаж" << endl;
}