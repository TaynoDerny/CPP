#include <iostream>
#include <math.h>
using namespace std ;
/// Задача 1
template <typename T> void rand_arr(T arr[],int size ){
    cout <<"\nРандомный список:\n";
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i]=rand()%49+1/10.0;
        cout << arr[i]<<" ";
    }
}

template <typename T> T arith_mean_arr(T arr[],int size){
    T mean=0;
    for (int i = 0; i < size; i++)
    {
        mean+=arr[i];
    }
    return mean/size;
}
//Задача 2
template <typename T> void equation(T a,T b){
    if (a!=0){
        cout<<" x = "<< -b/a<<endl;
    }
    else{
        cout << "a - не должна быть = 0"<<endl;
    }
}
template <typename T> void equation(T a,T b,T c){
    if (a==0){
        cout<<" x = "<< c/-b<<endl;
    }
    else{
        if((b*b-4*a*c)==0){
            cout << "Один корень "<<-b+sqrt((b*b-4*a*c))/2*a<<endl;
        }
        else if((b*b-4*a*c)>0){
            cout << "Два корня x1 = "<<(-b+sqrt(b*b-4*a*c))/(2*a)<<" x2 = "<<(-b-sqrt(b*b-4*a*c))/(2*a)<<endl;
        }
        else {
            cout << "Корней нет "<<endl;
        }
    }
}
//Задача 3
double roundS(double num, int n){
    return (round(num*(pow(10,n)))/(pow(10,n)));
}
//Задача 4
template <typename T> T max_arr(T arr[3]){
    T max = arr[0];
    for (int i = 0; i < 3; i++)
    {
        if (arr[i]>max){
            max=arr[i];
        }   
    }
    return max;
}
template <typename T> T max_arr(T arr[3][3]){
    T max = arr[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j]>max){
                max=arr[i][j];
            }
        }   
    }
    return max;
}
template <typename T> T max_arr(T arr[3][3][3]){
    T max = arr[0][0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int g = 0; g < 3; g++)
            {
                if (arr[i][j][g]>max){
                max=arr[i][j][g];
                }
            }  
        }   
    }
    return max;
}
//Задача 5
int max(int a,int b){
    if (a>b){
        return a;
    }
    else
        return b;
}
int max (int a, int b, int c){
    if(a>b && a>c){
        return a;
    }
    else if (b>a && b>c){
        return b;
    }
    else
        return c;
}   


int main(){
    const int size = 8;
    float arr_1[size]= {1.2,5.2,3.4,1.0};
    int arr_2[size]= {12,5,1};
    cout << "Среднее арефметическое значение списка в массиве 1: "<< arith_mean_arr(arr_1,size)<<endl;
    cout << "Среднее арефметическое значение списка в массиве 2: "<< arith_mean_arr(arr_2,size)<<endl;
    //Задача 2
    char choice;
    int a,b,c;
    cout << "Какиим уравнением хотите воспользоватся 0 - линейное; 1 - квадратное; "<<endl;
    cin>>choice;
    if (choice=='1'){
        cout << "Введите a и b и c\n";
        cin >> a>>b>>c;
        equation(a,b,c);
    }
    else if (choice=='0'){
        cout << "Введите a и b\n";
        cin >>a>>b;
        equation(a,b);
    }
    else
        cout << "Ошибка - введите либо 1 либо 0"<<endl;
    //Задача 3
    double num_3;
    int dot;
    cout << "Введите число которое нужно округлить"<<endl;
    cin>>num_3;
    cout << "Введите число сколько чисел после точки нужно оставить"<<endl;
    cin>>dot;
    cout << "Округленное число = "<<roundS(num_3,dot)<<endl;
    //Задача 4
    int arr_4[3] = {1,3,2};
    int arr_4_2[3][3] = {{1,3,-1},{4,12,3}};
    float arr_4_3[3][3][3] = {{4,2.9,9.2},{99,-1.3,12},{99.001,0.1,1}};
    cout <<"Максимальное число в 1 мерном массиве "<<max_arr(arr_4)<<endl;
    cout <<"Максимальное число в 2 мерном массиве "<<max_arr(arr_4_2)<<endl;
    cout <<"Максимальное число в 3 мерном массиве "<<max_arr(arr_4_3)<<endl;
    //Задача 5
    int choice_5;
    int a_5,b_5,c_5;
    cout << "Сколько целых числе вы хотите ввести 2 или 3"<<endl;
    cin >> choice_5;
    if (choice_5==2){
        cin>>a_5>>b_5;
        cout <<"Максимальное число  = "<<max(a_5,b_5)<<endl;
    }
    else if (choice_5==3){
        cin >>a_5>>b_5>>c_5;
        cout <<"Максимальное число  = "<<max(a_5,b_5,c_5)<<endl;
    }
    else{
        cout << "Ошибка - введите либо 3 либо 3"<<endl;
    }
    return 0;
}