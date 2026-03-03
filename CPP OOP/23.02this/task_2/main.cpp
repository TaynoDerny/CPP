#include <iostream>
#include "person.cpp"

using namespace std;

int main() {
    cout << "=== Демонстрация класса Person ===\n\n";
    
    cout << "Количество объектов в начале: " << Person::getObjectCount() << "\n\n";
    
    // Создаем дату рождения
    Date birthDate(15, 5, 1990);
    
    // Создаем человека через конструктор с параметрами
    cout << "Создаем человека p1 через конструктор с параметрами:\n";
    Person p1(1, "Петров", "Петр", "Петрович", birthDate);
    p1.display();
    cout << "Количество объектов: " << Person::getObjectCount() << "\n\n";
    
    // Создаем человека через конструктор по умолчанию
    cout << "Создаем человека p2 через конструктор по умолчанию:\n";
    Person p2;
    p2.display();
    cout << "Количество объектов: " << Person::getObjectCount() << "\n\n";
    
    // Создаем копию
    cout << "Создаем копию p3 через конструктор копирования (p3 = p1):\n";
    Person p3(p1);
    p3.setId(3);
    p3.setSurname("Сидоров");
    p3.display();
    cout << "Количество объектов: " << Person::getObjectCount() << "\n\n";
    
    // Демонстрация сеттеров
    cout << "Изменяем данные p2 через сеттеры:\n";
    p2.setId(2);
    p2.setSurname("Иванов");
    p2.setName("Иван");
    p2.setPatronymic("Иванович");
    p2.setBirthDate(Date(20, 3, 1985));
    p2.display();
    cout << endl;
    
    // Проверка геттеров
    cout << "Проверка геттеров для p1:\n";
    cout << "ID: " << p1.getId() << endl;
    cout << "Фамилия: " << p1.getSurname() << endl;
    cout << "Имя: " << p1.getName() << endl;
    cout << "Отчество: " << p1.getPatronymic() << endl;
    cout << "Дата рождения: ";
    p1.getBirthDate().display();
    cout << "\n\n";
    
    cout << "Количество объектов в конце: " << Person::getObjectCount() << endl;
    
    return 0;
}