#pragma once 

// КЛАСС Lift (Лифт)
class Lift {
private:
    int minFloor;     // Минимальный этаж (нижний)
    int maxFloor;     // Максимальный этаж (верхний)
    int currentFloor; // Текущий этаж
    bool isWorking;   // Состояние

public:
    // Конструктор
    Lift();
    
    // Методы для установки параметров
    void setRange(int minF, int maxF);     // Установка диапазона движения
    void turnOn();                          // Включить лифт
    void turnOff();                         // Выключить лифт
    
    // Методы для получения информации
    bool getState() const;                   // Получить состояние (работает/нет)
    int getCurrentFloor() const;             // Получить текущий этаж
    
    // Метод для обработки вызова
    void call(int floor);                    // Вызвать лифт на указанный этаж
};

