#pragma once
#include <chrono>
#include <memory>

class Timer {
    std::chrono::steady_clock::time_point start;
public:
    Timer();
    ~Timer();
};

std::unique_ptr<Timer> createTimer();
