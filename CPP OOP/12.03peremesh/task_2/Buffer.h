#pragma once

class Buffer {
public:
    Buffer(int size);
    Buffer(const Buffer& other);
    Buffer(Buffer&& other) noexcept;
    Buffer& operator=(const Buffer& other);
    Buffer& operator=(Buffer&& other) noexcept;
    ~Buffer();

    int size() const { return size_; }

private:
    int size_;
    int* data_;
};
