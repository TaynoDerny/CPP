#include <iostream>
#include "String.cpp"

using namespace std;

int main() {
    char input1[256], input2[256];
    
    cout << "Введите первую строку: ";
    cin >> input1;
    
    cout << "Введите вторую строку: ";
    cin >> input2;
    
    String s1(input1);
    String s2(input2);
    
    String result = s1 * s2;
    
    cout << "Строка 1: " << s1.c_str() << endl;
    cout << "Строка 2: " << s2.c_str() << endl;
    cout << "Пересечение: " << result.c_str() << endl;
    
    return 0;
}
