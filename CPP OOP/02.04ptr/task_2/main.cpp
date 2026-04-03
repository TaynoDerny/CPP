#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names = {"Ян", "Анна", "Максим", "Ли", "Александр", "Иван", "Ольга"};

    // Сортировка по длине
    sort(names.begin(), names.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });

    // Удаление имён короче 4 символов
    names.erase(remove_if(names.begin(), names.end(), [](const string& name) {
        return name.size() < 4;
    }), names.end());

    // Преобразование в верхний регистр
    for_each(names.begin(), names.end(), [](string& name) {
        transform(name.begin(), name.end(), name.begin(), ::toupper);
    });

    // Вывод результата
    for_each(names.begin(), names.end(), [](const string& name) {
        cout << name << "\n";
    });

    return 0;
}
