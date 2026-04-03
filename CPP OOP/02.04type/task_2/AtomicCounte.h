#pragma once
#include <mutex>

class AtomicCounter {
    int value;
    std::mutex mtx;
public:
    explicit AtomicCounter(int initial = 0);
    void increment();
    void decrement();
    int get();
};
