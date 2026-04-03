#pragma once
#include <stdexcept>

template<typename T>
class Garage {
public:
    Garage();
    explicit Garage(size_t capacity);
    Garage(const Garage<T>& other);
    ~Garage();

    Garage<T>& operator=(const Garage<T>& other);
    Garage<T>& add(const T& item);
    int getCount() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    Garage<T> operator+(const Garage<T>& other) const;

    static int getTotalGarages();

private:
    T* data;
    int count;
    int capacity;
    static int garageCount;
};
