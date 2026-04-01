#pragma once
#include <exception>

class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override;
};

class SafeDivision {
public:
    static double divide(double a, double b);
};
