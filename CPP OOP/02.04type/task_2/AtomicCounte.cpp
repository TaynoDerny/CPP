#include "AtomicCounte.h"

AtomicCounter::AtomicCounter(int initial) : value(initial) {}

void AtomicCounter::increment() {
    std::lock_guard<std::mutex> lock(mtx);
    ++value;
}

void AtomicCounter::decrement() {
    std::lock_guard<std::mutex> lock(mtx);
    --value;
}

int AtomicCounter::get() {
    std::lock_guard<std::mutex> lock(mtx);
    return value;
}
