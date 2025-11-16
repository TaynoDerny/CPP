#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

int task_1(int a, int n);
int task_2(int a, int b);
void task_3(int a, int b);
void task_4(int num, char mast);
void task_5(int a);
int main(){
// Задача 1
int num_1,n;
cout << "Введите степень и показатель степени a^n: "<<endl;
cin >> num_1>>n;
cout<< num_1<<"^"<<n<<" = "<<task_1(num_1,n)<<endl;
//Задача 2
int range_num1,range_num2;
cout << "Введите 2 числа сумму диапозона которых хочите получить "<<endl;
cin >> range_num1 >> range_num2;
cout<< "Сумма диапазона чисел "<<range_num1<<" и "<<range_num2<<" = "<<task_2(range_num1,range_num2)<<endl;
//Задача 3
int range_perfect1, range_perfect2;
cout << "Введите 2 числа в диапозоне которых хотите найти простые числа"<<endl;
cin >> range_perfect1>> range_perfect2; task_3(range_perfect1,range_perfect2);
//Задача 4
int number; char mast;
cout << "Введите номер игральной карты 1 - 13 и Масть: H - Черви, D - Бубны, C - трефы, S - Пики "<<endl;
cin >> number>>mast; task_4(number,mast);
//Задача 5
int happy_num;
cout << "Введите число чтобы проверить счастливое ли оно: "<<endl;
cin >> happy_num;task_5(happy_num);
return 0;
}

int task_1(int a, int n){
    int sum = 1;
    for (int i = 0; i < n; i++)
           sum*=a;
    return sum;
    
}
int task_2(int a, int b){
    int sum = 0;
    for (int i = a+1; i < b; i++)
           sum+=i;
           cout << sum <<endl;
    return sum;   
}
void task_3(int a, int b){
    for (int i = a+1; i < b; i++)
    {
        for (int j = 2; j < i; j++)
        {
            if (i%j!=0)
                cout << i<<" ";
                break;
        }
   }
   cout<<endl;
}
void task_4(int num, char mast){
    if ((num>=1 && num<=13) &&( mast=='D'|| mast=='C'|| mast=='H'|| mast=='S')){
        switch(num){
        case 1:
        cout << "Туз ";
        break;
        case 11:
        cout << "Валет ";
        break;
        case 12:
        cout << "Дама ";
        break;
        case 13:
        cout << "Король ";
        break;
        default:
        cout << num<<" ";
        break;
        }
        switch(mast){
        case 'D':
        cout << "бубны"<<endl;
        break;
        case 'C':
        cout << "трефы"<<endl;
        break;
        case 'H':
        cout << "черви"<<endl;
        break;
        case 'S':
        cout << "пики"<<endl;
        break;
        }
    }
    else
    {
        cout <<"ОШИБКА - Вы ввели неверные данные"<<endl;
    }    
    
    
    
}
void task_5(int a){
    if (a < 100000 || a > 999999){
        cout << " ОШИБКА - число не шестизначное" << endl;
    }
    else
    {
        int sum1=0,sum2=0;
        for (int i = 1; i < 1000000; i*=10)
        {   if(i<=100)
                sum1+=a/i%10;
            else
                sum2+=a/i%10;
        }
        if(sum1==sum2){
            cout<< "Число счастливое"<<endl;
        }
        else
            cout<< "Число не счастливое"<<endl;
    }
}

