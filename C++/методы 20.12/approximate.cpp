#include <iostream>
#include <cmath>

using namespace std;

// Функция f(x) 
double f(double x){
    //Пример функции:  x^2
    return x*x;
}


double approximate_integral(double a, double b, double e) {


    double I0 = 0.0;
    double I1 = INFINITY; // бесконечность
    int n = 5; 

 
    while (abs(I1 - I0) >= e) {

        n = 2 * n; 
        I0 = I1;   
        
      
        double h = (b - a) / n; 
        I1 = 0.0; 

        for (int i = 0; i <= n - 1; ++i) {
            double x = a + i * h; 
            I1 += f(x);           
        }

        I1 = I1 * h;
    }
    
    
    return I1;
}

int main(){
    double a,b,e;
    cout << "Введите начало отрезка  - a:"<<endl;
    cin >> a;
    cout << "Введите конец отрезка  - b:"<<endl;
    cin >> b;
    cout << "Введите точность - e:"<<endl;
    cin >> e;
    cout <<"Приближеное значение итеграла - "<<approximate_integral(a,b,e)<<endl;
    return 0;
}