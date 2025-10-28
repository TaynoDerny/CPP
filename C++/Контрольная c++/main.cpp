#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    //№1
    char symbol = 'A';
    cout << symbol<<endl;
    cout << endl;

    //#4
    int number;
    cout << "Введите число: "<<endl;
    cin >> number;
    if (number%2==0){
        cout << "Число "<< number << " четное"<<endl;
    }
    else
    {
        cout << "Число "<< number << " нечетное"<<endl;
    }
    cout << endl;

    //7
    for (int i = 1; i <= 10; i++)
    {
        cout << "куб числа "<< i << " = "<< i*i<<endl;
    }
    cout << endl;

    //11
    const int size = 8;
    int arr[size];
    int max_element = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
        cout << arr[i]<<" ";
        if (arr[i]>max_element){
            max_element = arr[i];
        }
    }
    cout << "Максимальное число массива = "<< max_element <<endl;
    cout << endl;

    //#13
    const int row = 3;
    const int col = 3;
    int arr_[row][col];
    int counter = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            counter++;
            arr_[i][j] = counter;
            cout << arr_[i][j]<<" ";
        }
        cout <<endl;
    }
    return 1;
}