#include <iostream>
using namespace std;


 ///      Вывод массива
void print (int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }
    cout<<endl;
    
}
 ///      Создание и вывод арндомного массива
void rand_arr(int arr[],int size){
    srand(time(NULL));
    cout <<"Рандомный массив "<<endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
        cout << arr[i]<<" ";
    }
    cout <<endl;
}
 ///      Задаание 1
void bubbleSort(int arr[],int size){
    int x =0;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                x = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = x; 
            }
        }
    }
    
}

 ///      Задаание 2

void insertSort(int arr[],int size)
{
	long i, j;
	int x;
	for ( i = 1; i < size; i++)
	{
		x = arr[i];
		for (j =  i - 1 ; j>=0 && arr[j]>x ; j--)
		{

			arr[j + 1] = arr[j];
		}

		arr[j + 1] = x;
	}
}
 ///      Задаание 3
void academic_performance (){
    const int size = 10;
    int ass[size];
    cout <<"Введите 10 оценок"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout <<"Введите оценку (1 - 12): "<<endl;
        cin>>ass[i];
        if (ass[i]>12){
            ass[i] =12;
        }
        else if (ass[i]<1) {
            ass[i] =1;
        }
    }
    int choice;
    while (choice !=0){
        cout << "====МЕНЮ===\nВыдти - 0\nВывести все оценки - 1\nПерсдача экзамена - 2\nПроверить выходит ли степендия - 3"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            print(ass,size);
            break;
        
        case 2:{
            int elment,new_ass;
            cout << "Какую вы оценку хотите пересдать по счету (1 - 10) "<<endl;
            cin >> elment;
            cout << "Введите новую оценку (1 - 12)"<<endl;
            cin >> new_ass;
            ass[elment-1] = new_ass;
            break;
        }
        case 3:{
            double sum=0;

            for (int i = 0; i < size; i++)
            {
                sum+=ass[i];
            }
            if (sum/size>=10.7){
                cout <<"Степендия выходит среднйи бал = "<<sum/size<< endl;
            }
            else
                cout <<"Степендия не выходит среднйи бал = "<<sum/size<< endl;
            break;
        }
        
        default:
            cout <<"Введите 0,1,2 или 3"<< endl;
            break;
        }
    }
    
}

 ///      Задаание 4
void quickSort(int arr[], int left, int right) {
    if (left >= right) return; 
    
    int medium = arr[(left + right) / 2];  
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (arr[i] < medium) i++;  
        while (arr[j] > medium) j--;  
        
        if (i <= j) {
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}


 ///      Задаание 5
void task_5(int arr[], int size){
    if (size%3==0){ 
        int sum=0;
        int x=0;
        for (int i = 0; i < size; i++)
        {
            sum+=arr[i];
        }
        if ((sum/size)>0){
            bubbleSort(arr,(size/3)*2);
            for (int i = (size/3)*2; i < (size/3)*2 + (size - (size/3)*2)/2; i++)
            {
                x = arr[i];
                arr[i] = arr[(size-1)-(i-((size/3)*2))];
                arr[(size-1)-(i-((size/3)*2))] = x;
            }
        }
        else{
            bubbleSort(arr,size/3);
            for (int i = size/3; i < (size/3)*2; i++)
            {
                x = arr[i];
                arr[i] = arr[(size-1)-(i-(size/3))];
                arr[(size-1)-(i-(size/3))] = x;
            }
        }
    }
    else{
        cout<<"Ошибка - размер массива должен делится на 3"<<endl;
    }
}



int main(){
    int size;
    cout << "Введите  размер массива для сортировок"<<endl;
    cin >> size;
    const int SIZE = size;
    int arr[SIZE];

//  Задание 1

    rand_arr(arr,SIZE);
    bubbleSort(arr,SIZE);
    cout <<"Алгоритм сортировки пузырьком"<<endl;
    print(arr,SIZE);

    //  Задание 2

    rand_arr(arr,SIZE);
    insertSort(arr,SIZE);
    cout<<"Алгоритм сортировки методом вставок"<<endl;
    print(arr,SIZE);

    //  Задание 3

    academic_performance();
    
    //  Задание 4
    
    rand_arr(arr,SIZE);
    quickSort(arr,0,SIZE-1);
    cout <<"Алгоритм сортировки быстрого поиска"<<endl;
    print(arr,SIZE);

    //  Задание 5

    rand_arr(arr,SIZE);
    task_5(arr,SIZE);
    cout <<  "Массив задания 5"<<endl;
    print(arr,SIZE);
 
    return 0;
}