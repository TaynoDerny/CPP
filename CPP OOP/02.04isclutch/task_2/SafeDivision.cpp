#include "SafeDivision.h"

const char* DivisionByZeroException::what() const noexcept {
    return "Division by zero";
}

double SafeDivision::divide(double a, double b) {
    if (b == 0)
        throw DivisionByZeroException();
    return a / b;
}
