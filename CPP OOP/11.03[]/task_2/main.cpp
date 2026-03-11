#include "var.h"
using namespace std;

int main() {
    // Демонстрация работы класса var
    
    // Создание переменных разных типов
    var a = 10;
    var b = 3.5;
    var c = "Hello";
    
    cout << "Исходные значения:\n";
    cout << "a = "; a.Show(); cout << "\n";
    cout << "b = "; b.Show(); cout << "\n";
    cout << "c = "; c.Show(); cout << "\n\n";
    
    // Арифметические операции
    cout << "Арифметические операции:\n";
    cout << "a + 5 = "; (a + 5).Show(); cout << "\n";
    cout << "a - 2 = "; (a - 2).Show(); cout << "\n";
    cout << "a * 2 = "; (a * 2).Show(); cout << "\n";
    cout << "a / 2 = "; (a / 2).Show(); cout << "\n\n";
    
    // Операции со смешанными типами
    cout << "Операции со смешанными типами:\n";
    var x = 20;
    var y = "10";
    cout << "20 + \"10\" = "; (x + y).Show(); cout << "\n";
    cout << "20 - \"5\" = "; (x - var("5")).Show(); cout << "\n\n";
    
    // Операции со строками
    cout << "Операции со строками:\n";
    var str1 = "abcdef";
    var str2 = "ace";
    cout << "\"abcdef\" * \"ace\" = "; (str1 * str2).Show(); cout << "\n";
    cout << "\"abcdef\" / \"ace\" = "; (str1 / str2).Show(); cout << "\n\n";
    
    // Операторы сравнения
    cout << "Операторы сравнения:\n";
    var p = 15;
    var q = 15;
    var r = 20;
    cout << "15 == 15: " << (p == q ? "true" : "false") << "\n";
    cout << "15 != 20: " << (p != r ? "true" : "false") << "\n";
    cout << "15 < 20: " << (p < r ? "true" : "false") << "\n";
    cout << "15 > 20: " << (p > r ? "true" : "false") << "\n\n";
    
    // Составные операторы присваивания
    cout << "Составные операторы присваивания:\n";
    var z = 100;
    cout << "z = "; z.Show(); cout << "\n";
    z += 50;
    cout << "z += 50: "; z.Show(); cout << "\n";
    z -= 30;
    cout << "z -= 30: "; z.Show(); cout << "\n";
    z *= 2;
    cout << "z *= 2: "; z.Show(); cout << "\n";
    z /= 4;
    cout << "z /= 4: "; z.Show(); cout << "\n\n";
    
    // Преобразования типов
    cout << "Преобразования типов:\n";
    var num = 42;
    cout << "var(42) -> int: " << (int)num << "\n";
    cout << "var(42) -> double: " << (double)num << "\n";
    cout << "var(42) -> const char*: " << (const char*)num << "\n";
    
    return 0;
}
