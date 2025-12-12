#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A[3][3] = {
        {22.52, -4.62, -1.41},
        {-5.10, -28.37, 4.58},
        {4.68, -1.91, 23.85}
    };
    
    double b[3] = {0.53, -8.78, 5.14};
    double x[3] = {0.0, 0.0, 0.0}; 
    
    double eps = 0.0001; 
    double max_err;
    int iter = 0;
    

    do {
        max_err = 0.0;
        for (int i = 0; i < 3; i++) {
            double old_x = x[i];
            double sum = b[i];
            
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    sum = sum - A[i][j] * x[j];
                }
            }
            

            x[i] = sum / A[i][i];
            

            double current_err = fabs(x[i] - old_x);
            if (current_err > max_err) {
                max_err = current_err;
            }
        }
        iter++;
        
    } while (max_err > eps);
    

    cout << "Решение: " << iter << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;
    cout << "x3 = " << x[2] << endl;
    
    return 0;
}