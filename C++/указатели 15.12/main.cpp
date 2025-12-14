#include <iostream>

using namespace std;
 

// Функция вывода массива
void print(int *arr,int size){
    cout <<endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(arr+i)<<" ";
    }
    cout <<endl;
}
/// Функция ввода массива пользователем
void input_arr(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        cout << "Введите "<<i<<" элемент массива:"<<endl;
        cin >> *(arr+i);
    }
}
/// функия превращения 2 массивов в 1
int sum_arr(int *arr_1,int size_1,int *arr_2,int size_2,int *sum_arr){
    int sum_size = size_1+size_2;
    for (int i = 0; i < size_1; i++)
    {
        *(sum_arr+i) = *(arr_1+i);
    }
    for (int i = 0; i < size_2; i++)
    {
        *(sum_arr+size_1+i) = *(arr_2+i);
    }
    return sum_size;
}
// Функция меню для 2 здания 
int del_menu(int *arr, int size){
    int newIndex = 0;
    cout << "\t||МЕНЮ||\t" << endl;
    int choice;
    do{
        cout << "Выберите действие для массива\n1) Удалить четные значения\n2) Удалить нечетные значения\n3) Вывести массив\n0) Выйти " << endl;
        cin >> choice;

        switch (choice)
        {
        // Выход из меню
        case 0:
        {
            break;
        }
        /// Убрать четные элементы из мвссива 
        case 1:
        {
            newIndex = 0;
            for (int i = 0; i < size; i++) {
                if (*(arr + i) % 2 != 0) {
                    *(arr + newIndex) =   *(arr + i);
                    newIndex++;
                }
            }
            size = newIndex; // Обновляем размер
            break;
        }
        /// Убрать нечетные элементы из мвссива 
        case 2:
        {
            newIndex = 0;
            for (int i = 0; i < size; i++) {
                if (*(arr + i) % 2 == 0) {
                    *(arr + newIndex) = *(arr + i);
                    newIndex++;
                }
            }
            size = newIndex; // Обновляем размер
            break;
        }
        /// выввод массив 
        case 3:
        {
            cout << "Текущий массив: ";
            for (int i = 0; i < size; i++) {
                cout << *(arr + i) << " ";
            }
            cout << endl;
            break;
        }
        default:
        {
            cout << "Неверный выбор!" << endl;
            break;
        }
        }
    }while (choice!=0);
    
    return size; // Возвращения нового размера массива
}

int main(){
    
    
    // Задание 1
    int M,N,max_size=100;
    // Ввод размера массива A
    cout << "Введите размер первого массива(размер должен быть <100): "<<endl;
    cin >> M;
    if(M>=100){
        cout <<"ОШИБКА - (размер массива должен быть <100) "<<endl;
        return 0;
    }
    // Ввод размера массива B
    cout << "Введите размер второго массива(размер должен быть <100): "<<endl;
    cin >> N;
    if(N>=100){
        cout <<"ОШИБКА - (размер массива должен быть <100) "<<endl;
        return 0;
    }
    // Заполнение пользователем массивов A и B
    int A[M],B[N],arr[max_size];
    cout << "Заполните первый массив:"<<endl;
    input_arr(A,M);
    cout << "Заполните второй массив:"<<endl;
    input_arr(B,N);
    // Вывод полившихся массивов пользователю
    cout << "Первый массив:"<<endl;
    print(A,M);
    cout << "Второй массив:"<<endl;
    print(B,N);
    // Вывод 3 массива 
    sum_arr(A,M,B,N,arr);
    cout <<"Третий массив:"<<endl;
    print(arr,sum_arr(A,M,B,N,arr));


   


    

    cout<<endl<<endl; /// Задача 2
    /////////////////
    int M_2;
    cout << "Введите размер массива A:"<<endl;
    cin >> M_2;
    int A_2[M_2];
    
    cout << "Заполните этот массив:"<<endl;
    input_arr(A_2,M_2);

    print(A_2, del_menu(A_2,M_2));

    return 0;
}