#include <iostream>
#include "String.cpp"
using namespace std;

int main() {
    cout << "=== Демонстрация работы класса String ===" << endl;
    cout << "Начальное количество объектов: " << String::getObjectCount() << endl << endl;
    
    // Создание объектов разными конструкторами
    cout << "1. Создание строки конструктором по умолчанию (80 символов):" << endl;
    String str1;
    str1.output();
    cout << endl;
    
    cout << "2. Создание строки конструктором с произвольным размером (20 символов):" << endl;
    String str2(20);
    str2.output();
    cout << endl;
    
    cout << "3. Создание строки конструктором с инициализацией:" << endl;
    String str3("Привет, мир!");
    str3.output();
    cout << endl;
    
    cout << "4. Демонстрация статической функции:" << endl;
    cout << "Количество созданных объектов: " << String::getObjectCount() << endl << endl;
    
    cout << "5. Ввод строки с клавиатуры для str1:" << endl;
    str1.input();
    str1.output();
    cout << endl;
    
    cout << "6. Ввод строки с клавиатуры для str2:" << endl;
    str2.input();
    str2.output();
    cout << endl;
    
    cout << "7. Создание еще одного объекта:" << endl;
    String* str4 = new String("Динамический объект");
    str4->output();
    cout << "Текущее количество объектов: " << String::getObjectCount() << endl << endl;
    
    cout << "8. Удаление динамического объекта:" << endl;
    delete str4;
    cout << "Количество объектов после удаления: " << String::getObjectCount() << endl << endl;
    
    cout << "=== Завершение программы ===" << endl;
    cout << "Объекты будут автоматически уничтожены при выходе из main" << endl;
    
    return 0;
}