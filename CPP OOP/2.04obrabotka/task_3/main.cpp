#include <iostream>
#include <string>
using namespace std;

namespace {

    int counter = 0;

    void normalize(double& value) {
        if (value < 0.0) value = 0.0;
        if (value > 1.0) value = 1.0;
        ++counter;
    }

} 

namespace Utils {

    double clamp(double val, double min, double max) {
        double normalized = (val - min) / (max - min);
        normalize(normalized); 
        return min + normalized * (max - min);
    }

    int getCallCount() {
        return counter;
    }

} 

int main() {


    cout << "clamp(5, 0, 10)  = " << Utils::clamp(5.0,  0.0, 10.0) << "\n"; // 5
    cout << "clamp(-3, 0, 10) = " << Utils::clamp(-3.0, 0.0, 10.0) << "\n"; // 0
    cout << "clamp(15, 0, 10) = " << Utils::clamp(15.0, 0.0, 10.0) << "\n"; // 10
    cout << "clamp(0.3, 0, 1) = " << Utils::clamp(0.3,  0.0,  1.0) << "\n"; // 0.3

    cout << "normalize called: " << Utils::getCallCount() << " times\n";


    return 0;
}
