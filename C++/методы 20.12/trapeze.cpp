#include <iostream>
#include <cmath>

using namespace std;

// Функция f(x) 
double f(double x){
    //Пример функции:  x^2
    return x*x;
}


double trapeze(double a, double b,double n){
    double S = 0;
    double h = (b-a)/n;
    double x= a+h;

    while(x<b){
        double F=f(x);
        S = S+F;
        x=x+h;
    }

    double Fa = f(a);
    double Fb = f(b);

    S = (h/2)*(Fa+Fb+2*S);
    
    return S;
}

int main(){
    double a,b,n;
    cout << "Введите начало отрезка  - a:"<<endl;
    cin >> a;
    cout << "Введите конец отрезка  - b:"<<endl;
    cin >> b;
    cout << "Введите начальное число разбиений - n:"<<endl;
    cin >> n;
    cout <<"Приближеное значение метода трапеций - "<<trapeze(a,b,n)<<endl;
    return 0;
}