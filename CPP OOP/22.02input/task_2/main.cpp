#include <iostream>
#include <string>
#include <clocale>
#include "wallpaper.cpp"

using namespace std;

// Функция для вывода чисел с 2 знаками после запятой
void printDouble(double value) {
    int intPart = (int)value;
    int fracPart = (int)((value - intPart) * 100 + 0.5);
    
    cout << intPart << ".";
    if (fracPart < 10) {
        cout << "0";
    }
    cout << fracPart;
}

int main() {
    setlocale(LC_ALL, "Ru");
    
    Apartment apartment;
    int roomCount, rollCount;
    
    cout << "=== Программа Расчета Стоимости Обоев ===" << endl;
    cout << endl;
    
    // ВВОД КОМНАТ 
    cout << "Введите количество комнат: ";
    cin >> roomCount;
    
    if (roomCount > MAX_ROOMS) {
        roomCount = MAX_ROOMS;
        cout << "Слишком много комнат. Будет использовано максимум " << MAX_ROOMS << endl;
    }
    
    for (int i = 0; i < roomCount; i++) {
        cout << "\n--- Комната " << i + 1 << " ---" << endl;
        
        string name;
        double length, width, height;
        
        cout << "Название комнаты: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Длина (м): ";
        cin >> length;
        
        cout << "Ширина (м): ";
        cin >> width;
        
        cout << "Высота (м): ";
        cin >> height;
        
        Room room(name, length, width, height);
        apartment.addRoom(room);
        
        // Показываем площадь стен комнаты
        cout << "Площадь стен: ";
        printDouble(room.getWallArea());
        cout << " кв.м" << endl;
    }
    

    cout << "\nВведите количество видов обоев: ";
    cin >> rollCount;
    
    if (rollCount > MAX_ROLLS) {
        rollCount = MAX_ROLLS;
        cout << "Слишком много видов. Будет использовано максимум " << MAX_ROLLS << endl;
    }
    
    Roll rolls[MAX_ROLLS];
    
    for (int i = 0; i < rollCount; i++) {
        cout << "\n--- Вид обоев " << i + 1 << " ---" << endl;
        
        string name;
        double length, width, price;
        
        cout << "Название обоев: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Длина рулона (м): ";
        cin >> length;
        
        cout << "Ширина рулона (м): ";
        cin >> width;
        
        cout << "Цена за рулон (руб): ";
        cin >> price;
        
        rolls[i] = Roll(name, length, width, price);
        
        // Показываем площадь рулона
        cout << "Площадь рулона: ";
        printDouble(rolls[i].getRollArea());
        cout << " кв.м" << endl;
    }
    

    cout << "\n=== РЕЗУЛЬТАТЫ РАСЧЕТА ===" << endl;
    cout << endl;
    
    int totalRolls[MAX_ROLLS] = {0};
    double totalCost = 0;
    
    // Для каждой комнаты считаем нужное количество обоев
    for (int i = 0; i < apartment.getRoomCount(); i++) {
        Room currentRoom = apartment.getRoom(i);
        double roomArea = currentRoom.getWallArea();
        
        cout << "Комната: " << currentRoom.getName() << endl;
        cout << "Площадь стен: ";
        printDouble(roomArea);
        cout << " кв.м" << endl;
        
        // Если есть обои, используем первый вид
        if (rollCount > 0) {
            int rollsNeeded = rolls[0].getRollsNeeded(roomArea);
            totalRolls[0] = totalRolls[0] + rollsNeeded;
            totalCost = totalCost + (rollsNeeded * rolls[0].getPrice());
            
            cout << "Обои: " << rolls[0].getName() << endl;
            cout << "Нужно рулонов: " << rollsNeeded << endl;
            cout << "Стоимость: ";
            printDouble(rollsNeeded * rolls[0].getPrice());
            cout << " руб" << endl;
        }
        
        cout << "------------------" << endl;
    }
    

    cout << "\n=== ИТОГОВАЯ ЗАКУПКА ===" << endl;
    
    for (int i = 0; i < rollCount; i++) {
        if (totalRolls[i] > 0) {
            cout << rolls[i].getName() << ": " 
                 << totalRolls[i] << " рулонов" << endl;
        }
    }
    
    cout << "\nОБЩАЯ СТОИМОСТЬ: ";
    printDouble(totalCost);
    cout << " руб" << endl;
    
    cout << "\nОбщая площадь стен по квартире: ";
    printDouble(apartment.getTotalWallArea());
    cout << " кв.м" << endl;
    
    return 0;
}