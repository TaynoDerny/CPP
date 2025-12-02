#include <iostream>

using namespace std;



/// разворачивание части массива 
template <class T>
void flip(T arr[], int start, int end) {
    while (start < end) {
        T temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
} 

///  Вывод массива в строчку 
template <class T>
void print (T arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
    
}

/// улучшенная сортировка пузырьком задание 2 с подсчетом перестановок и если их 0 то цикл заверщается
template <class T>
void bubbleSortImp(T arr[],int size){
    T x =0;
    int counter =0;
    int ncount= 0 ;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                x = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = x; 
                counter++;
            }
        }
        if (ncount==counter){
            break;
        }
        ncount = counter;
    }
    cout<< "Количество перестановок: "<<counter<<endl;
}


/// Сортировка пузырьком
template <class T>
void bubbleSort(T arr[],int size){
    T x =0;
    int counter =0;
    int ncount= 0 ;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                x = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = x; 
                counter++;
            }
        }
    }
    
}

/// Задание 1
void menu_user(long int mpNumber[],long int hpNumber[],int size){
    int choice;
    do
    {
        cout<<endl<<"Выберите действие:\nОтсортировать по номерам мобильных - 1\nОтсортировать по домашним номерам телефонов - 2\nВывести пользовательский данные - 3\nВыход - 0"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
        {
            cout << "Все отсортированные мобильные номера"<<endl;
            long int *ptr_mpNumber = mpNumber;
            bubbleSort(ptr_mpNumber,size);
            print(ptr_mpNumber,size);
            break;
        }
        case 2:
        {    
            cout << "Все отсортированные домашние номера"<<endl;
            long int *ptr_hpNumber = hpNumber;
            bubbleSort(ptr_hpNumber,size);
            print(ptr_hpNumber,size);
            break;
        }
        case 3:
        {   
            cout << "Все отсортированные домашние номера:"<<endl<<endl;
            cout << "Номера мобильных телефонов:"<<endl;
            for (int i = 0; i < size; i++)
            {
                cout << i+1<<" - "<<mpNumber[i]<<"; ";   
            }
            cout<<endl<< "Номера домашних телефонов:"<<endl;
            for (int i = 0; i < size; i++)
            {
                cout << i+1<<" - "<<hpNumber[i]<<"; ";   
            }
            break;}
        case 0:
        {    
            break;}
        default:
        {    
            cout << "ОШИБКА - Выберите 1,2,3 или 0"<<endl;
            break;
        }
        }
    } while (choice!=0);
}
/// сортировка оладий 3 задание
void pancakeSort(int arr[], int n) {
    for (int i = n-1; i > 0; i--) {
        int max_pos = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[max_pos]) {
                max_pos = j;
            }
        }
        
        if (max_pos != i) {
            if (max_pos != 0) {
                flip(arr, 0, max_pos);  
            }
            flip(arr, 0, i);
        }
    }
}  
    /// функция для 4 задания
void task_4 (int array[],int size){
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = array[i];
    }
    


    int x =0;
    int counter =0;
    int ncount= 0 ;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                x = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = x; 
                counter++;
            }
        }
    }
    cout<< "Количество перестановок: "<<counter<<endl;
    print(arr,size);

    bubbleSortImp(array,size);
    print(array,size);
}

   





int main (){
    //Задача 1
    const int size = 4;
    long int mpNumber[size]; // массив мобильных номеров
    long int hpNumber[size];// массив домашних номеров
    ///Заполнения массивов пользователем
    for (int i = 0; i < size; i++)
    {
        cout<<endl<<"Ввведите мобильный номер (не больше 10 целых чисел) "<<i+1<<" пользователя:"<<endl;
        cin>>mpNumber[i];
        if(mpNumber[i]>9999999999){
            cout << "ОШИБКА - номер не должен повторятся и должен состоять из не больше 10 целых чисел "<<endl;
        } 
        cout<<"Ввведите домашний номер (не больше 6 целых чисел) "<<i+1<<" пользователя:"<<endl;
        cin>>hpNumber[i];
        if(hpNumber[i]>999999 ){
            cout << "ОШИБКА - номер не должен повторятся и должен состоять из не больше 6 целых чисел "<<endl;
        }
    }
    menu_user(mpNumber,hpNumber,size);
    
/// Задача 2
    const int size_10 =10;
    int arrNum[size_10];
    cout <<"Заполните массив целыми числами:"<<endl<<endl;
    for (int i = 0; i < size_10; i++)
    {
        cout << "Введите "<<i<<" значения массива:"<<endl;
        cin>>arrNum[i];
    }
    cout <<endl<<"Получившийся массив:"<<endl;
    print(arrNum,size_10);
    cout <<"Улучшенный алгоритм сортировки пузырьком:"<<endl;
    bubbleSort(arrNum,size_10);
    print(arrNum,size_10);



    /// Задача 3
    const int  quantity = 6;
    int oladi[quantity];
    cout << "Введите радиус оладий:"<<endl<<endl;
    for (int i = 0; i < quantity; i++)
    {
        cout << "Введите радиус "<<i+1<<" оладия"<<endl;
        cin >> oladi[i];
    }
    cout <<"Получившаяся стопка оладий:"<<endl<<endl;
    for (int i = 0; i < quantity; i++)
    {
        cout << oladi[i]<<endl;
    }
    pancakeSort(oladi,quantity);
    cout<<"Отсортированная стопка оладий"<<endl;
    for (int i = 0; i < quantity; i++)
    {
        cout << oladi[i]<<endl;
    }
    
   

    /// Задача 4
    const int size_4 = 6;
    int arrBuble[size_4];
    for (int i = 0; i < size_4; i++)
    {
        cout <<"Введите элемент массива: "<< endl;
        cin >> arrBuble[i];
    }
    
    cout <<"Проверка и сранвение обычной сортировки пущзырьком и улучшеной сортировки пузырьком с добавленным подсчетом перестонов и если перестоновок нет то цикл заверщается"<<endl;
    task_4(arrBuble,size_4);
    /*
    Количество перестоновок не раличается так как в обычной сортировки есть условие и если часть массива отсортированно перестановок не будет
    */



 
    return 0;

}