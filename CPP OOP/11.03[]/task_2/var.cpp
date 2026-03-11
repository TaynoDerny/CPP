#include "var.h"
using namespace std;

// Конструкторы
var::var() : type(INT) { data.intVal = 0; }
var::var(int val) : type(INT) { data.intVal = val; }
var::var(double val) : type(DOUBLE) { data.doubleVal = val; }
var::var(const char* val) : type(STRING), strVal(val) {}
var::var(const string& val) : type(STRING), strVal(val) {}
var::var(const var& other) : type(other.type), strVal(other.strVal) {
    if (type == INT) data.intVal = other.data.intVal;
    else if (type == DOUBLE) data.doubleVal = other.data.doubleVal;
}

// Операторы присваивания
var& var::operator=(const var& other) {
    if (this != &other) {
        type = other.type;
        strVal = other.strVal;
        if (type == INT) data.intVal = other.data.intVal;
        else if (type == DOUBLE) data.doubleVal = other.data.doubleVal;
    }
    return *this;
}

var& var::operator=(int val) {
    type = INT;
    data.intVal = val;
    strVal.clear();
    return *this;
}

var& var::operator=(double val) {
    type = DOUBLE;
    data.doubleVal = val;
    strVal.clear();
    return *this;
}

var& var::operator=(const char* val) {
    type = STRING;
    strVal = val;
    return *this;
}

// Методы конвертации
int var::toInt() const {
    if (type == INT) return data.intVal;
    if (type == DOUBLE) return (int)data.doubleVal;
    return stoi(strVal);
}

double var::toDouble() const {
    if (type == INT) return (double)data.intVal;
    if (type == DOUBLE) return data.doubleVal;
    return atof(strVal.c_str());
}

string var::toString() const {
    if (type == INT) return to_string(data.intVal);
    if (type == DOUBLE) {
        return to_string(data.doubleVal);
    }
    return strVal;
}

// Арифметические операторы
var var::operator+(const var& other) const {
    if (type == STRING) {
        return var(strVal + other.toString());
    } else if (type == DOUBLE) {
        return var(data.doubleVal + other.toDouble());
    } else {
        return var(data.intVal + other.toInt());
    }
}

var var::operator-(const var& other) const {
    if (type == DOUBLE) {
        return var(data.doubleVal - other.toDouble());
    } else {
        return var(data.intVal - other.toInt());
    }
}

var var::operator*(const var& other) const {
    if (type == STRING) {
        // Для строк: возвращаем символы первой строки, которые есть во второй
        string result;
        for (char c : strVal) {
            if (other.toString().find(c) != string::npos) {
                result += c;
            }
        }
        return var(result);
    } else if (type == DOUBLE) {
        return var(data.doubleVal * other.toDouble());
    } else {
        return var(data.intVal * other.toInt());
    }
}

var var::operator/(const var& other) const {
    if (type == STRING) {
        // Для строк: возвращаем символы первой строки, которых нет во второй
        string result;
        for (char c : strVal) {
            if (other.toString().find(c) == string::npos) {
                result += c;
            }
        }
        return var(result);
    } else if (type == DOUBLE) {
        return var(data.doubleVal / other.toDouble());
    } else {
        return var(data.intVal / other.toInt());
    }
}

// Составные операторы присваивания
var& var::operator+=(const var& other) {
    *this = *this + other;
    return *this;
}

var& var::operator-=(const var& other) {
    *this = *this - other;
    return *this;
}

var& var::operator*=(const var& other) {
    *this = *this * other;
    return *this;
}

var& var::operator/=(const var& other) {
    *this = *this / other;
    return *this;
}

// Операторы сравнения
bool var::operator==(const var& other) const {
    if (type == STRING || other.type == STRING) {
        return toString() == other.toString();
    } else if (type == DOUBLE || other.type == DOUBLE) {
        return toDouble() == other.toDouble();
    } else {
        return data.intVal == other.toInt();
    }
}

bool var::operator!=(const var& other) const {
    return !(*this == other);
}

bool var::operator<(const var& other) const {
    if (type == STRING || other.type == STRING) {
        return toString() < other.toString();
    } else if (type == DOUBLE || other.type == DOUBLE) {
        return toDouble() < other.toDouble();
    } else {
        return data.intVal < other.toInt();
    }
}

bool var::operator>(const var& other) const {
    if (type == STRING || other.type == STRING) {
        return toString() > other.toString();
    } else if (type == DOUBLE || other.type == DOUBLE) {
        return toDouble() > other.toDouble();
    } else {
        return data.intVal > other.toInt();
    }
}

bool var::operator<=(const var& other) const {
    return *this < other || *this == other;
}

bool var::operator>=(const var& other) const {
    return *this > other || *this == other;
}

// Преобразования типов
var::operator int() const {
    return toInt();
}

var::operator double() const {
    return toDouble();
}

var::operator const char*() const {
    static string temp;
    temp = toString();
    return temp.c_str();
}

// Вывод значения
void var::Show() const {
    if (type == INT) cout << data.intVal;
    else if (type == DOUBLE) cout << data.doubleVal;
    else cout << strVal;
}
