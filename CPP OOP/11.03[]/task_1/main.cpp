#include "Array.cpp"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Демонстрация класса Array ===\n" << endl;
    
    Array arr(5);
    
    cout << "1. Инициализация через []:";
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    cout << " ";
    arr.print();
    
    cout << "2. Доступ к элементам: arr[2] = " << arr[2] << endl;
    
    cout << "3. Метод set(): ";
    arr.set(1, 25);
    arr.print();
    
    cout << "4. Метод get(): arr.get(1) = " << arr.get(1) << endl;
    
    cout << "5. Размер массива: " << arr.getSize() << endl;
    
    cout << "6. Оператор () - увеличение на 5: ";
    arr(5);
    arr.print();
    
    cout << "7. Преобразование к int (сумма): " << (int)arr << endl;
    
    cout << "8. Преобразование к char*: " << (char*)arr << endl;
    
    return 0;
}
