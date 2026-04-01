#include <iostream>
#include "SafeDivision.cpp"

using namespace std;

int main() {
    try {
        cout << "10 / 2 = " << SafeDivision::divide(10, 2) << "\n";
        cout << "5 / 0 = " << SafeDivision::divide(5, 0) << "\n";
    } catch (const DivisionByZeroException& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
