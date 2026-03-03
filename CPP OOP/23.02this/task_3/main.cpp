#include <iostream>
#include "mystring.cpp"

using namespace std;

int main() {
    cout << "=== Демонстрация класса MyString ===\n\n";
    
    // 1. Конструктор с параметром-строкой
    cout << "1. Создаем строку через конструктор с параметром:\n";
    MyString s1("Hello");
    cout << "s1 = \""; s1.display(); cout << "\"";
    cout << ", длина: " << s1.getLength() << endl;
    
    // 2. Конструктор копирования
    cout << "\n2. Создаем копию через конструктор копирования:\n";
    MyString s2(s1);
    cout << "s2 = \""; s2.display(); cout << "\"";
    cout << ", длина: " << s2.getLength() << " (копия s1)" << endl;
    
    // 3. Конструктор с параметром длина
    cout << "\n3. Создаем строку с резервом памяти (20 символов):\n";
    MyString s3(20);
    cout << "s3 = \""; s3.display(); cout << "\"";
    cout << ", длина буфера: " << s3.getLength() << " (пустая строка)" << endl;
    
    // 4. Сеттер (без перевыделения памяти)
    cout << "\n4. Устанавливаем строку 'World' (помещается в буфер):\n";
    s3.set("World");
    cout << "s3 = \""; s3.display(); cout << "\"";
    cout << ", длина строки: " << strlen(s3.c_str()) << endl;
    cout << "размер буфера: " << s3.getLength() << " (не изменился)" << endl;
    
    // 5. Сеттер с перевыделением памяти
    cout << "\n5. Устанавливаем длинную строку (требуется перевыделение):\n";
    cout << "Текущий размер буфера: " << s3.getLength() << endl;
    s3.set("Это очень длинная строка, которая точно не помещается в старый буфер");
    cout << "s3 = \""; s3.display(); cout << "\"\n";
    cout << "Новый размер буфера: " << s3.getLength() << " (автоматически увеличился)" << endl;
    
    // 6. Проверка независимости копий (глубокое копирование)
    cout << "\n6. Проверка глубокого копирования:\n";
    cout << "Меняем s1 на 'Changed':\n";
    s1.set("Changed");
    cout << "s1 = \""; s1.display(); cout << "\"\n";
    cout << "s2 (копия) = \""; s2.display(); cout << "\" (не изменилась)\n";
    
    // 7. Демонстрация c_str()
    cout << "\n7. Использование c_str() для работы с C-строками:\n";
    const char* c_string = s1.c_str();
    cout << "s1 как C-строка: " << c_string << endl;
    cout << "Длина через strlen: " << strlen(c_string) << endl;
    
    // 8. Цепочка операций с разными строками
    cout << "\n8. Работа с несколькими строками:\n";
    MyString s4("Первая");
    MyString s5("Вторая");
    MyString s6(s4);  // копия s4
    
    cout << "s4 = \""; s4.display(); cout << "\"\n";
    cout << "s5 = \""; s5.display(); cout << "\"\n";
    cout << "s6 = \""; s6.display(); cout << "\" (копия s4)\n";
    
    return 0;
}