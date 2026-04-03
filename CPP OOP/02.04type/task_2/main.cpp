#include <iostream>
#include <thread>
#include <vector>
#include "AtomicCounte.cpp"

using namespace std;

int main() {
    AtomicCounter counter(0);
    const int iterations = 100000;

    cout << "Начальное значение: " << counter.get() << "\n";

    vector<thread> threads;

    for (int i = 0; i < 4; ++i)
        threads.emplace_back([&] {
            for (int j = 0; j < iterations; ++j)
                counter.increment();
        });

    for (int i = 0; i < 4; ++i)
        threads.emplace_back([&] {
            for (int j = 0; j < iterations; ++j)
                counter.decrement();
        });

    for (auto& t : threads)
        t.join();

    cout << "Финальное значение: " << counter.get() << " (должно быть 0)\n";
}
