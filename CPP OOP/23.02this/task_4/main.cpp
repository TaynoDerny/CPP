#include <iostream>
#include "house.cpp"
#include "apartment.cpp"
#include "date.cpp"
#include "person.cpp"

using namespace std;

int main() {
    cout << "=== МНОГОКВАРТИРНЫЙ ДОМ ===\n\n";
    
    // Создаем дом
    cout << "1. Создаем дом:\n";
    House myHouse(1, "ул. Пушкина, д. 10");
    cout << "Дом создан\n\n";
    
    // Создаем даты рождения
    Date date1(15, 3, 1980);
    Date date2(20, 7, 1985);
    Date date3(10, 1, 2010);
    Date date4(5, 6, 1975);
    Date date5(12, 11, 1990);
    Date date6(3, 9, 2015);
    
    // Создаем людей
    cout << "2. Создаем жильцов:\n";
    
    Person p1(1, "Иванов", "Иван", "Иванович", date1);
    Person p2(2, "Иванова", "Мария", "Петровна", date2);
    Person p3(3, "Иванов", "Петр", "Иванович", date3);
    
    Person p4(4, "Петров", "Петр", "Петрович", date4);
    Person p5(5, "Петрова", "Анна", "Сергеевна", date5);
    
    Person p6(6, "Сидоров", "Сидор", "Сидорович", date6);
    
    cout << "Создано 6 жильцов\n\n";
    
    // Создаем квартиры
    cout << "3. Создаем квартиры и заселяем жильцов:\n";
    
    Apartment apt1(101);
    apt1.addResident(p1);
    apt1.addResident(p2);
    apt1.addResident(p3);
    cout << "Квартира 101: заселена семья Ивановых (3 человека)\n";
    
    Apartment apt2(102);
    apt2.addResident(p4);
    apt2.addResident(p5);
    cout << "Квартира 102: заселена семья Петровых (2 человека)\n";
    
    Apartment apt3(103);
    apt3.addResident(p6);
    cout << "Квартира 103: заселен Сидоров (1 человек)\n";
    
    // Добавляем квартиры в дом
    cout << "\n4. Добавляем квартиры в дом:\n";
    myHouse.addApartment(apt1);
    myHouse.addApartment(apt2);
    myHouse.addApartment(apt3);
    cout << "Добавлено 3 квартиры\n";
    
    // Выводим информацию о доме
    cout << "\n5. Информация о доме:\n";
    myHouse.display();
    
    // Демонстрация поиска
    cout << "\n6. Поиск квартиры №102:\n";
    Apartment* found = myHouse.findApartment(102);
    if (found) {
        found->display();
    }
    
    // Поиск жильца по ID
    cout << "\n7. Поиск жильца с ID=3:\n";
    Apartment* aptWithPerson = myHouse.findApartmentByResident(3);
    if (aptWithPerson) {
        cout << "Жилец с ID=3 найден в квартире №" << aptWithPerson->getNumber() << endl;
        Person* person = aptWithPerson->findResidentById(3);
        if (person) {
            cout << "Данные жильца:\n";
            person->display();
        }
    }
    
    // Добавление нового жильца
    cout << "\n8. Добавляем нового жильца в квартиру 103:\n";
    Person p7(7, "Сидорова", "Елена", "Ивановна", Date(1, 1, 1988));
    Apartment* apt103 = myHouse.findApartment(103);
    if (apt103) {
        apt103->addResident(p7);
        cout << "Добавлена Сидорова Е.И. в квартиру 103\n";
        apt103->display();
    }
    
    // Удаление жильца
    cout << "\n9. Удаляем жильца с ID=3 из квартиры 101:\n";
    Apartment* apt101 = myHouse.findApartment(101);
    if (apt101) {
        apt101->removeResidentById(3);
        cout << "Жилец удален\n";
        apt101->display();
    }
    
    // Статистика
    cout << "\n10. Статистика дома:\n";
    myHouse.printStatistics();
    
    // Проверка конструктора копирования
    cout << "\n11. Создаем копию дома (конструктор копирования):\n";
    House houseCopy(myHouse);
    cout << "Копия дома создана\n";
    houseCopy.display();
    
    // Показываем количество созданных объектов Person
    cout << "\n=== ИТОГ ===\n";
    cout << "Всего было создано объектов Person: " << Person::getObjectCount() << endl;
    cout << "(деструкторы освободят память при выходе из программы)\n";
    
    return 0;
}