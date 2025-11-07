#include <iostream>

using namespace std;

void rectangle(int x,int y);
int fact(int a);
int primeNumber(int num);
int cube(int num);
int maxNum(int num_1,int num_2);
int pos_neg(int num);

int main(){
    setlocale(LC_ALL,"ru");
    ///Задание 1
    int rectangle_x, rectangle_y; 
    cout<< "Введите ширину и высоту прямоугольника: "<<endl;
        cin >> rectangle_x >> rectangle_y;
    rectangle(rectangle_x,rectangle_y);
    //Задание 2
    int factorial;
    cout << "Введите факториал:"<<endl;
    cin >> factorial;
    cout <<"Факториал "<<factorial<<" = "<< fact(factorial)<<endl;
    //Задание 3
    int pNum;
    cout << "Введите число: "<<endl;
    cin >> pNum;
    if(primeNumber(pNum)==1)
        cout<<pNum<<" Простое число "<<endl;
    else
        cout<<pNum<<" Не простое число "<<endl;
    ///ЗАдание 4
    int cubeNumber;
    cout << "Введите число которое нужно взвести в квадрат: "<<endl;
    cin>>cubeNumber;
    cout <<cubeNumber<<"^2"<<" = "<< cube(cubeNumber)<<endl;
    ///Задание 5
    int num_1,num_2;
    cout << "Введите два числа: "<<endl;
    cin >> num_1>>num_2;
    cout << maxNum(num_1,num_2)<<" большее из чисел "<<endl;
    ///заданеи 6
    int num;
    cout << "Введите число кроме нуля: "<<endl;
    cin >> num;
    cout << pos_neg(num)<<endl;
    return 0;
}
///Задание 1
void rectangle(int x,int y){
    for (int i = 0; i < x; i++)
    {
        for (int i = 0; i < y; i++)
        {
            cout << "*"<<" ";
        }
        cout<<endl;     
    }
}
//Задание 2
int fact(int a){
    int fact = 1;
    if (a==0&&a==1)
        return fact;
    else   
    {
        for (int i = 1; i <= a; i++)
        {
            fact*=i;
        }
        
    }
    return fact;
}
//Задание 3
int primeNumber(int num){
    if (num==0)
        return 0;
    for (int i = 1; i < num; i++)
    {
        if (num%i==0 && i!=1){
            return 0;
        }
        else
            return 1;
    }    
}
//Задача 4
int cube(int num){
    return num*num;
}
//Задание 5
int maxNum(int num_1,int num_2){
    if (num_1>num_2){
        return num_1;
    }
    else if (num_1<num_2){
        return num_2;
    }
    else
        return num_1;       
}
//Задание 6
int pos_neg(int num){
    if (num>0){
        return true;
    }
    else if (num<0) {
        return false;
    }
    else {
        return 0;
    }
}