#include "House.h"
using namespace std;

House::House(string address, vector<string> roomNames) : address(address) {
    cout << "Дом по адресу \"" << address << "\" построен." << endl;
    // Создаем комнаты внутри вектора. Время жизни комнат зависит от вектора дома.
    for (const auto& name : roomNames) {
        rooms.push_back(Room(name));
    }
}

House::~House() {
    cout << "Дом по адресу \"" << address << "\" снесен." << endl;
    // Вектор rooms автоматически вызовет деструкторы всех объектов Room
}

void House::printInfo() const {
    cout << "Дом: " << address << endl;
    cout << "Комнаты:" << endl;
    for (const auto& room : rooms) {
        room.printInfo();
    }
}