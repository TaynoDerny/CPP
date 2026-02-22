#include <iostream>
#include "lift.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru"); 
    Lift myLift;
    int choice, floor, minF, maxF;
    
    cout << "=== УПРАВЛЕНИЕ ЛИФТОМ ===" << endl;
    cout << endl;
    
    while (true) {
        cout << "\n--- Меню ---" << endl;
        cout << "1. Установить диапазон этажей" << endl;
        cout << "2. Включить лифт" << endl;
        cout << "3. Выключить лифт" << endl;
        cout << "4. Вызвать лифт" << endl;
        cout << "5. Показать состояние" << endl;
        cout << "6. Показать текущий этаж" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Введите нижний этаж: ";
                cin >> minF;
                cout << "Введите верхний этаж: ";
                cin >> maxF;
                myLift.setRange(minF, maxF);
                break;
                
            case 2:
                myLift.turnOn();
                break;
                
            case 3:
                myLift.turnOff();
                break;
                
            case 4:
                cout << "Введите этаж для вызова: ";
                cin >> floor;
                myLift.call(floor);
                break;
                
            case 5:
                cout << "Состояние: " << (myLift.getState() ? "работает" : "не работает") << endl;
                break;
                
            case 6:
                cout << "Текущий этаж: " << myLift.getCurrentFloor() << endl;
                break;
                
            case 0:
                cout << "Программа завершена" << endl;
                return 0;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
    
    return 0;
}