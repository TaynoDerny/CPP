#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;         // Указатель на выделенную память
    int capacity;    // Размер выделенной памяти (GetSize)
    int count;       // Текущее количество элементов
    int growParam;   // Шаг увеличения памяти

    // Вспомогательный метод для выделения новой памяти и копирования
    void Reallocate(int newCapacity) {
        if (newCapacity < 0) newCapacity = 0;

        T* newData = nullptr;
        if (newCapacity > 0) {
            newData = new T[newCapacity];
            int elementsToCopy = (count < newCapacity) ? count : newCapacity;
            for (int i = 0; i < elementsToCopy; ++i) {
                newData[i] = data[i];
            }
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
        if (count > capacity) {
            count = capacity;
        }
    }

public:
    // Конструктор по умолчанию
    Array() : data(nullptr), capacity(0), count(0), growParam(1) {}

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Конструктор копирования
    Array(const Array& other) : data(nullptr), capacity(0), count(0), growParam(other.growParam) {
        *this = other; 
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            count = other.count;
            growParam = other.growParam;

            if (capacity > 0) {
                data = new T[capacity];
                for (int i = 0; i < count; ++i) {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Получение размера массива 
    int GetSize() const {
        return capacity;
    }

    // Установка размера
    void SetSize(int size, int grow = 1) {
        growParam = (grow > 0) ? grow : 1;
        Reallocate(size);
    }

    // Получение последнего допустимого индекса
    int GetUpperBound() const {
        return count - 1;
    }

    // Проверка на пустоту
    bool IsEmpty() const {
        return count == 0;
    }

    // Удалить лишнюю память
    void FreeExtra() {
        if (capacity > count) {
            Reallocate(count);
        }
    }

    // Очистить массив
    void RemoveAll() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        count = 0;
    }

    // Получение элемента по индексу
    T GetAt(int index) const {
        if (index < 0 || index >= count) throw std::out_of_range("Индекс вне диапазона");
        return data[index];
    }

    // Установка элемента по индексу
    void SetAt(int index, const T& value) {
        if (index < 0 || index >= count) throw std::out_of_range("Индекс вне диапазона");
        data[index] = value;
    }

    // Перегрузка оператора [] (чтение и запись)
    T& operator[](int index) {
        if (index < 0 || index >= count) throw std::out_of_range("Индекс вне диапазона");
        return data[index];
    }

    // Добавление элемента в конец
    void Add(const T& value) {
        if (count >= capacity) {
            // Увеличиваем массив на значение growParam
            Reallocate(capacity + growParam);
        }
        data[count++] = value;
    }

    // Сложение двух массивов
    void Append(const Array& other) {
        for (int i = 0; i < other.count; ++i) {
            Add(other.data[i]);
        }
    }

    // Получение указателя на данные
    T* GetData() const {
        return data;
    }

    // Вставка элемента в позицию
    void InsertAt(int index, const T& value) {
        if (index < 0 || index > count) throw std::out_of_range("Недопустимый индекс для вставки");

        if (count >= capacity) {
            Reallocate(capacity + growParam);
        }

        // Сдвигаем элементы вправо
        for (int i = count; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        count++;
    }

    // Удаление элемента из позиции
    void RemoveAt(int index) {
        if (index < 0 || index >= count) throw std::out_of_range("Индекс вне диапазона");

        // Сдвигаем элементы влево
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
    }
};