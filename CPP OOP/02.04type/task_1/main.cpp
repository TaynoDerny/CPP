#include <iostream>
#include <chrono>
#include <thread>
#include "ThreadGuard.cpp"

using namespace std;

int main() {
    ThreadGuard t1(thread([] {
        cout << "Поток 1: запущен\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Поток 1: завершён (после задержки 500мс)\n";
    }));

    ThreadGuard t2(thread([] {
        cout << "Поток 2: запущен и сразу завершён\n";
    }));

    cout << "Главный поток: ожидаем завершения потоков...\n";
}
