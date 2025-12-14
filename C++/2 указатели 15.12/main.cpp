#include <iostream>
using namespace std;

// Функция вывода одномерного массива
void print(int arr[],int size){
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout <<endl; 
}
// Функция ввода одномерного массива
void input_arr(int arr[], int size){
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите "<<i<< " элемент массива"<<endl;
        cin >> arr[i];
    }
}

// Функции Задания 1:

/// Функция проверки элемента есть ли он в переданном массиве
int checkElement(int* arr, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (*(arr+i) == element) {
            return 1;
        }
    }
    return 0;
}


/* 
   Функция которая принимает массив A и B и заполняет новый массив 
        элементами массива A, которых нет в B (без повторений) вычисляя минимальный размер нового массива
*/
int diff(int* arr_1,int size_1,int* arr_2,int size_2,int* new_arr){
    int new_size = 0;

    for (int i = 0; i < size_1; i++)
    {
        if(checkElement(arr_2,size_2,*(arr_1+i))==0){
            if(checkElement(new_arr,new_size,*(arr_1+i))==0){
                *(new_arr+new_size)= *(arr_1+i);
                new_size++;
            }
        }
    }
    return new_size;
}

// Задание 2

int symmetricDiff(int* arr_1,int size_1,int* arr_2,int size_2,int* new_arr){
    int new_size = 0;

    //Элементы из первого массива которых нет во втором
    for (int i = 0; i < size_1; i++) {
        if (checkElement(arr_2, size_2, *(arr_1 + i)) == 0) {
            if (checkElement(new_arr, new_size, *(arr_1 + i)) == 0) {
                *(new_arr + new_size) = *(arr_1 + i);
                new_size++;
            }
        }
    }
    
    //Элементы из второго массива которых нет в первом
    for (int i = 0; i < size_2; i++) {
        if (checkElement(arr_1, size_1, *(arr_2 + i)) == 0) {
            if (checkElement(new_arr, new_size, *(arr_2 + i)) == 0) {
                *(new_arr + new_size) = *(arr_2 + i);
                new_size++;
            }
        }
    }
    
    return new_size;
}
   



int main(){
    // Задани 1
    int M,N;
    cout << "Введите размер массива A: "<<endl;
    cin >> M;
    //Создания и заполнение массива A
    int A[M];
    input_arr(A,M);

    cout << "Введите размер массива B: "<<endl;
    cin >> N;
    //Создания и заполнение массива B
    int B[N];
    input_arr(B,N);


    // Временный размер нового массива
    int max_size = M;
    int new_arr[max_size];

    // Получения минимального размера нового заполненого массива и вывод его 
    cout << "Элементы массива A, которых нет в B (без повторений):"<<endl;
    int real_size = diff(A,M,B,N,new_arr);
    print(new_arr,real_size);


//////////////////////////////////////////////////////////////////////////////////////////////////


    // Задача 2
    int M_2,N_2;
    cout << "Введите размер массива A: "<<endl;
    cin >> M_2;
    //Создания и заполнение массива A
    int A_2[M_2];
    input_arr(A_2,M_2);

    cout << "Введите размер массива B: "<<endl;
    cin >> N_2;
    //Создания и заполнение массива B
    int B_2[N_2];
    input_arr(B_2,N_2);

// Временный размер нового массива
    int max_size_2 = M_2;
    int new_arr_2[max_size_2];


    // Получения минимального размера нового заполненого массива и вывод его 
    cout << "Элементы массивов A и B, которые не являются общими для них, без повторений.:"<<endl;
    int real_size_2 = symmetricDiff(A_2,M_2,B_2,N_2,new_arr_2);
    print(new_arr_2,real_size_2);

    return 0;
}