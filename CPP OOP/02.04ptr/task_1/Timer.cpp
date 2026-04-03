#include "Timer.h"
#include <iostream>

using namespace std;

Timer::Timer() : start(chrono::steady_clock::now()) {
    cout << "Таймер запущен\n";
}

Timer::~Timer() {
    auto elapsed = chrono::steady_clock::now() - start;
    auto ms = chrono::duration_cast<chrono::milliseconds>(elapsed).count();
    cout << "Таймер уничтожен. Прошло: " << ms << " мс\n";
}

std::unique_ptr<Timer> createTimer() {
    return std::make_unique<Timer>();
}
