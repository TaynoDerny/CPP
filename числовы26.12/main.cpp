#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sin(x); 
}

double gaussIntegration(double a, double b, double e, double &d, int &n) {
    double f0 = f(a);
    double f1 = f(b);
    double S1 = (b - a) * (f0 + f1 + 4 * f((a + b) / 2.0)) / 6.0;
    double S2;
    
    n = 2;

    while (true) {
        double h = (b - a) / n;
        double x1 = a + h / 2.0; 
        double x2 = a + h;       
        
        S2 = f(a) + f(b); 
        
        for (int i = 1; i <= n; i++) {
            S2 += 4 * f(x1);
            if (i < n) {
                S2 += 2 * f(x2);
            }
            x1 += h;
            x2 += h;
        }

        S2 = S2 * h / 6.0;
        
        d = abs(S1 - S2) / 15.0;

        if (d < e) {
            break;
        } else {
            S1 = S2;
            n = 2 * n;
        }
    }
    return S2;
}

int main() {
    double a, b, e, d;
    int n;

    cout << "Введите a, b, e: ";
    cin >> a >> b >> e;

    double result = gaussIntegration(a, b, e, d, n);

    cout << "S: " << result << endl;
    cout << "d: " << d << endl;
    cout << "n: " << n << endl;

    return 0;
}