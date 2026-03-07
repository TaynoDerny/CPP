#include "Worker.cpp"  
#include <iostream>
#include <string>

using namespace std;

// Функция для вывода работника
void printWorker(const Worker& w, int number) {
    cout << "--- Работник №" << number << " ---\n";
    cout << "Фамилия: " << w.getLast_name() << "\n";
    cout << "Имя: " << w.getFirst_name() << "\n";
    cout << "Отчество: " << w.getPatronymic() << "\n";
    cout << "Должность: " << w.getJob_title() << "\n";
    cout << "Стаж (лет): " << w.getYear_of_work() << "\n";
    cout << "Зарплата: " << w.getSalary() << "\n";
    cout << "------------------------\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    // Создаём массив работников (размер 6)
    const int SIZE = 6;
    Worker workers[SIZE] = {
        Worker("Иванов", "Иван", "Иванович", "Инженер", 5, 70000),
        Worker("Петров", "Петр", "Петрович", "Менеджер", 3, 65000),
        Worker("Сидоров", "Сидор", "Сидорович", "Инженер", 8, 80000),
        Worker("Козлов", "Алексей", "Алексеевич", "Директор", 12, 120000),
        Worker("Михайлов", "Михаил", "Михайлович", "Менеджер", 2, 55000),
        Worker("Бухгалтер")  // explicit конструктор
    };
    // Заполним остальные поля для последнего работника (индекс 5)
    workers[5].setLast_name("Смирнова");
    workers[5].setFirst_name("Елена");
    workers[5].setPatronymic("Викторовна");
    workers[5].setYear_of_work(10);
    workers[5].setSalary(90000);

    // Демонстрация explicit: раскомментируйте следующую строку, чтобы увидеть ошибку компиляции
    // Worker w = "Программист"; // Ошибка: нельзя неявно преобразовывать

    // Вывод всех работников
    cout << "\n=== СПИСОК ВСЕХ РАБОТНИКОВ ===\n";
    for (int i = 0; i < SIZE; ++i) {
        printWorker(workers[i], i + 1);
    }

    // 1. Список работников со стажем больше заданного
    cout << "\nВведите минимальный стаж (лет) для поиска: ";
    int minExp;
    cin >> minExp;
    cin.ignore();

    cout << "\n--- Работники со стажем более " << minExp << " лет ---\n";
    bool foundExp = false;
    for (int i = 0; i < SIZE; ++i) {
        if (workers[i].getYear_of_work() > minExp) {
            printWorker(workers[i], i + 1);
            foundExp = true;
        }
    }
    if (!foundExp) cout << "Таких работников нет.\n";

    // 2. Список работников с зарплатой больше заданной
    cout << "\nВведите минимальную зарплату для поиска: ";
    int minSalary;
    cin >> minSalary;
    cin.ignore();

    cout << "\n--- Работники с зарплатой более " << minSalary << " ---\n";
    bool foundSalary = false;
    for (int i = 0; i < SIZE; ++i) {
        if (workers[i].getSalary() > minSalary) {
            printWorker(workers[i], i + 1);
            foundSalary = true;
        }
    }
    if (!foundSalary) cout << "Таких работников нет.\n";

    // 3. Список работников заданной должности
    cout << "\nВведите должность для поиска: ";
    string position;
    getline(cin, position);

    cout << "\n--- Работники с должностью \"" << position << "\" ---\n";
    bool foundPos = false;
    for (int i = 0; i < SIZE; ++i) {
        if (workers[i].getJob_title() == position) {
            printWorker(workers[i], i + 1);
            foundPos = true;
        }
    }
    if (!foundPos) cout << "Таких работников нет.\n";

    return 0;
}