#include <iostream>
#include "Student.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru"); 
    
    cout << "=== Тестирование конструкторов ===" << endl;
    
    // Создание объекта через конструктор по умолчанию
    Student student1;
    cout << endl;
    
    // Создание объекта через конструктор с параметрами
    Student student2("Иванов Иван Иванович", "15.05.2000", "+7 (999) 123-45-67",
                     "Москва", "Россия", "Московский политехнический колледж",
                     "Москва", "ИТ-201");
    cout << endl;
    
    // Создание объекта через конструктор копирования
    Student student3(student2);
    cout << endl;
    
    cout << "\n=== Информация о студентах ===" << endl;
    
    cout << "Студент 1 (по умолчанию):" << endl;
    student1.PrintStudent();
    cout << endl;
    
    cout << "Студент 2 (с параметрами):" << endl;
    student2.PrintStudent();
    cout << endl;
    
    cout << "Студент 3 (копия студента 2):" << endl;
    student3.PrintStudent();
    cout << endl;
    
    // Тестирование методов установки отдельных частей ФИО
    cout << "=== Тестирование методов установки ФИО ===" << endl;
    
    Student student4;
    student4.SetSurname("Петров");
    student4.SetName("Петр");
    student4.SetPatronymic("Петрович");
    student4.SetBirthday("23.11.2001");
    student4.SetPhone_number("+7 (999) 987-65-43");
    student4.SetCity("Санкт-Петербург");
    student4.SetCountry("Россия");
    student4.SetName_college("СПб технический колледж");
    student4.SetCity_college("Санкт-Петербург");
    student4.SetNumber_group("ПР-202");
    
    cout << "Студент 4 (создан через отдельные методы):" << endl;
    student4.PrintStudent();
    cout << endl;
    
    // Тестирование оператора присваивания
    cout << "=== Тестирование оператора присваивания ===" << endl;
    Student student5;
    student5 = student4;
    cout << "Студент 5 (копия студента 4 через присваивание):" << endl;
    student5.PrintStudent();
    cout << endl;
    
    cout << "=== Деструкторы будут вызваны автоматически ===" << endl;
    
    return 0;
}