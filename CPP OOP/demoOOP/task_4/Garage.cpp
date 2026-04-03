#include "Garage.h"

template<typename T>
int Garage<T>::garageCount = 0;

template<typename T>
Garage<T>::Garage() : data(nullptr), count(0), capacity(0) {
    garageCount++;
}

template<typename T>
Garage<T>::Garage(size_t capacity) : count(0), capacity(capacity) {
    data = new T[capacity];
    garageCount++;
}

template<typename T>
Garage<T>::Garage(const Garage<T>& other) : count(other.count), capacity(other.capacity) {
    data = new T[capacity];
    for (int i = 0; i < count; i++)
        data[i] = other.data[i];
    garageCount++;
}

template<typename T>
Garage<T>::~Garage() {
    delete[] data;
}

template<typename T>
Garage<T>& Garage<T>::operator=(const Garage<T>& other) {
    if (this == &other) return *this;
    delete[] data;
    count = other.count;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < count; i++)
        data[i] = other.data[i];
    return *this;
}

template<typename T>
Garage<T>& Garage<T>::add(const T& item) {
    if (count == capacity) {
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (int i = 0; i < count; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }
    data[count++] = item;
    return *this;
}

template<typename T>
int Garage<T>::getCount() const { return count; }

template<typename T>
T& Garage<T>::operator[](int index) {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
const T& Garage<T>::operator[](int index) const {
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
Garage<T> Garage<T>::operator+(const Garage<T>& other) const {
    Garage<T> result(count + other.count);
    for (int i = 0; i < count; i++)
        result.add(data[i]);
    for (int i = 0; i < other.count; i++)
        result.add(other.data[i]);
    return result;
}

template<typename T>
int Garage<T>::getTotalGarages() { return garageCount; }
