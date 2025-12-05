#include <iostream>
using namespace std;
    // Вывод массива
void print(int* arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout <<*(arr+i)<<" ";
    }
    cout<<endl;
    
}
    // Задание 1
void copyArray(int* arr, int* copy, int size) {
    for (int i = 0; i < size; ++i) {
        *(copy + i) = *(arr + i);
    }
}
    // Задание 2
void reverse(int* arr, int size){
    int temp;
    for (int i = 0; i < size-1-i; i++)
    {
        temp = *(arr+i);
        *(arr+i) = *(arr+size-1-i);
        *(arr+size-1-i) = temp;
    }
    
}
/// Задание 3
void copyReversArr(int* arr, int* copyRevArr, int size){
    for (int i = 0; i < size; i++)
    {
        *(copyRevArr+i) = *(arr+size-1-i);
    }
}

int main() {
    // Задание 1
    const int size = 5;
    int arr_1[size];
    int arr_1copy[size];
    int arr_3copy[size];
    for (int  i = 0; i < size; i++)
    {
        cout << "Введите значения массива: "<<endl;
        cin >>arr_1[i];
    }
    cout<endl;
    copyArray(arr_1, arr_1copy, size);
    cout << "Основной массив:"<<endl;
    print(arr_1,size);
    cout << "Копия массива:"<<endl;
    print(arr_1copy,size);

    // Задание 2
    cout<<endl;
    cout <<"Изначальный массив:"<<endl;
    print(arr_1copy,size);
    cout << "Перевернутый массив:"<<endl;
    reverse(arr_1copy,size);
    print(arr_1copy,size);

    //Задание 3
    cout<<endl;
    cout << "Основной массив:"<<endl;
    print(arr_1,size);
    cout << "Перевернутая копия массива:"<< endl;
    copyReversArr(arr_1,arr_3copy,size);
    print(arr_3copy,size);
    return 0;
}