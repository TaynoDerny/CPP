#include "Airplane.h"

using namespace std;

Airplane::Airplane(const string& t, int max, int curr)
    : type(t), maxPassengers(max), currentPassengers(curr) {
    if (currentPassengers > maxPassengers)
        currentPassengers = maxPassengers;
    if (currentPassengers < 0)
        currentPassengers = 0;
}

string Airplane::getType() const {
    return type;
}

int Airplane::getMaxPassengers() const {
    return maxPassengers;
}

int Airplane::getCurrentPassengers() const {
    return currentPassengers;
}

bool Airplane::operator==(const Airplane& other) const {
    return type == other.type;
}

Airplane& Airplane::operator++() {
    if (currentPassengers < maxPassengers)
        ++currentPassengers;
    return *this;
}

Airplane& Airplane::operator--() {
    if (currentPassengers > 0)
        --currentPassengers;
    return *this;
}

bool Airplane::operator>(const Airplane& other) const {
    return maxPassengers > other.maxPassengers;
}

Airplane& Airplane::operator=(const Airplane& other) {
    if (this != &other) {
        type = other.type;
        maxPassengers = other.maxPassengers;
        currentPassengers = other.currentPassengers;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Airplane& a) {
    os << "Airplane(type=" << a.type
        << ", max=" << a.maxPassengers
        << ", current=" << a.currentPassengers << ")";
    return os;
}