#include "time.cpp"

using namespace std;

int main() {
    Time t1(10, 30, 45);
    Time t2(8, 15, 30);
    Time t3;

    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;

    cout << "\nИспользование addSecond():" << endl;
    t1.addSecond();
    cout << "t1 после addSecond(): " << t1 << endl;

    cout << "\nПрефиксный инкремент ++t1:" << endl;
    ++t1;
    cout << "t1 = " << t1 << endl;

    cout << "\nПостфиксный инкремент t1++:" << endl;
    Time t4 = t1++;
    cout << "t4 (старое значение) = " << t4 << endl;
    cout << "t1 (новое значение) = " << t1 << endl;

    cout << "\nДекремент --t2:" << endl;
    --t2;
    cout << "t2 = " << t2 << endl;

    cout << "\nСравнения:" << endl;
    cout << "t1 == t2: " << (t1 == t2) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;
    cout << "t1 > t2: " << (t1 > t2) << endl;
    cout << "t1 < t2: " << (t1 < t2) << endl;

    cout << "\nОператор присваивания:" << endl;
    t3 = t1;
    cout << "t3 = " << t3 << endl;

    cout << "\nОператор +=:" << endl;
    t3 += 75;
    cout << "t3 += 75 секунд: " << t3 << endl;

    cout << "\nОператор -=:" << endl;
    t3 -= 30;
    cout << "t3 -= 30 секунд: " << t3 << endl;

    cout << "\nОператор () (общее количество секунд):" << endl;
    cout << "t1 в секундах: " << t1() << endl;

    cout << "\nВведите время (часы минуты секунды): ";
    cin >> t3;
    cout << "Вы ввели: " << t3 << endl;

    return 0;
}
