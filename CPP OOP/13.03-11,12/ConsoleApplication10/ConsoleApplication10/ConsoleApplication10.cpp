#include <iostream>
#include <string>
#include "Array.h" 

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    try {
        cout << "--- Тестирование Array<int> ---" << endl;
        Array<int> arr;

   
        arr.SetSize(3, 5);
        cout << "Начальный размер (capacity): " << arr.GetSize() << endl;

  
        arr.Add(10);
        arr.Add(20);
        arr.Add(30);
        cout << "Элементов добавлено. Верхний индекс: " << arr.GetUpperBound() << endl;


        cout << "\nДобавляем 4-й элемент (массив должен вырасти на 5)..." << endl;
        arr.Add(40);
        cout << "Новый размер (capacity): " << arr.GetSize() << endl;

        arr[0] = 99; 
        arr.InsertAt(2, 25); 

        cout << "\nТекущие элементы массива: ";
        for (int i = 0; i <= arr.GetUpperBound(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Тест FreeExtra
        cout << "\nОчищаем лишнюю память (FreeExtra)..." << endl;
        arr.FreeExtra();
        cout << "Размер после FreeExtra: " << arr.GetSize() << endl;

        // Тест Append
        Array<int> arr2;
        arr2.Add(50);
        arr2.Add(60);
        arr.Append(arr2);

        cout << "Массив после Append: ";
        for (int i = 0; i <= arr.GetUpperBound(); ++i) cout << arr[i] << " ";
        cout << endl;

        // Тест строкового массива
        cout << "\n--- Тестирование Array<string> ---" << endl;
        Array<string> strArr;
        strArr.Add("Привет");
        strArr.Add("Мир");
        cout << strArr[0] << ", " << strArr[1] << "!" << endl;

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}