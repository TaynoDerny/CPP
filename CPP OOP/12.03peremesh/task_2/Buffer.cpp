#include "Buffer.h"
#include <iostream>
using namespace std;

Buffer::Buffer(int size)
    : size_(size), data_(new int[size]{}) {
    cout << "[конструктор] size=" << size_ << "\n";
}

Buffer::Buffer(const Buffer& other)
    : size_(other.size_), data_(new int[other.size_]) {
    for (int i = 0; i < size_; i++) data_[i] = other.data_[i];
    cout << "[копирование] size=" << size_ << "\n";
}

Buffer::Buffer(Buffer&& other) noexcept
    : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
    cout << "[перемещение конструктор] size=" << size_ << "\n";
}

Buffer& Buffer::operator=(const Buffer& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i++) data_[i] = other.data_[i];
        cout << "[копирующее присваивание] size=" << size_ << "\n";
    }
    return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
        cout << "[перемещающее присваивание] size=" << size_ << "\n";
    }
    return *this;
}

Buffer::~Buffer() {
    delete[] data_;
    cout << "[деструктор] size=" << size_ << "\n";
}
