#include <iostream>
#include <ctime>

using namespace std ;
int main(){
    srand(time(NULL));
    /*
    Сложные уровень:
    */
    //Задание 1
    int min_dist = 101;
    const int size_1 = 4;
    const int size_2 = 4;
    int arr_1[size_1];
    int arr_2[size_2];
    for (int i = 0; i < size_1; i++)
    {
        arr_1[i] = rand()%49+1;
        cout << arr_1[i] << " " ;
    }
    cout << endl;
    for (int i = 0; i < size_2; i++)
    {
        arr_2[i] = rand()%49+1;
        cout << arr_2[i] << " " ;
    }
    cout << endl;
    for (int i = 0; i < size_1; i++)
    {
        for (int j = 0; j < size_2; j++)
        {
            if (arr_1[i]+arr_2[j]<min_dist)
                min_dist = arr_1[i]+arr_2[j];
        }
    }
    cout << "Минимальное расстояние между любыми двумя элементами массивов = "<<min_dist<<endl;
    cout << endl;
    ///Задача 2
    const int size = 5;
    int arr[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   if (i==j)
                arr[i][j] = 0;
            else
                arr[i][j] = rand()%8+1;
            cout << arr[i][j] <<" ";
        }
        cout << endl;   
    }   
    cout << endl<<"Измененая матрциа смежности:"<<endl<<endl; 
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <size; j++)
            {
                int new_element = arr[i][k]+arr[k][j];
                if (new_element<arr[i][j])
                    arr[i][j] = new_element;
                
            }
            
        }   
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {   
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< endl;       
    return 0;
}