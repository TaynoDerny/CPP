#include <iostream>
#include "Timer.cpp"

using namespace std;

int main() {
    cout << "Входим в область видимости\n";
    {
        auto timer = createTimer();
        cout << "Внутри области видимости\n";
    } // timer автоматически удаляется здесь
    cout << "Вышли из области видимости\n";
    return 0;
}
