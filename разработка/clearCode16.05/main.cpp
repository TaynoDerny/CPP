#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Task {
public:
    std::string description;
    int priority;
    bool isCompleted;

    Task(const std::string& desc, int prio, bool completed = false)
        : description(desc), priority(prio), isCompleted(completed) {}
};

std::vector<Task> readTasks(int count) {
    std::vector<Task> tasks;
    tasks.reserve(count);

    for (int i = 0; i < count; ++i) {
        std::string desc;
        int prio;

        std::cout << "Task desc: ";
        std::getline(std::cin >> std::ws, desc);

        std::cout << "Priority (1-5): ";
        while (!(std::cin >> prio) || prio < 1 || prio > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid priority. Enter 1-5: ";
        }

        tasks.emplace_back(desc, prio);
    }
    return tasks;
}

void sortTasksByPriority(std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(),
              [](const Task& a, const Task& b) {
                  return a.priority > b.priority;
              });
}

void printTopTasks(const std::vector<Task>& tasks, int topN) {
    if (tasks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }

    int count = std::min(topN, static_cast<int>(tasks.size()));
    std::cout << "Top " << count << " tasks:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << tasks[i].description << " (priority " << tasks[i].priority << ")\n";
    }
}

int main() {
    int taskCount;
    std::cout << "Number of tasks: ";
    std::cin >> taskCount;

    if (taskCount < 0) {
        std::cout << "Invalid count.\n";
        return 1;
    }

    auto tasks = readTasks(taskCount);
    sortTasksByPriority(tasks);
    printTopTasks(tasks, 3);

    return 0;
}

/*
Ответы на вопросы
Имена

Структура t → Task

Поля: d → description, p → priority, c → isCompleted

Функция s → sortTasksByPriority

Переменные: cnt → taskCount, ts → tasks, tmp → temp

Нарушение SRP
Вся логика (ввод, сортировка, вывод) в одной функции main. Надо разделить на отдельные функции: ввод, сортировка, вывод топ-задач.

Дублирование
Циклы вывода for дублируются, ручная сортировка повторяет операцию обмена.

Улучшение структуры
Выделить класс TaskManager или функции:

vector<Task> readTasks(int count)

void sortTasks(vector<Task>& tasks)

void printTopTasks(const vector<Task>& tasks, int topN)

Ошибки ввода

Приоритет вне 1–5: программа не проверяет, сортировка отработает, но логика неверна.

Описание >199 символов: переполнение буфера char d[200] (небезопасно).

using namespace std; и char d[200]

using namespace std; загрязняет пространство имён, конфликты.

Фиксированный буфер опасен переполнением; лучше std::string.

Алгоритм STL
std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){ return a.priority > b.priority; });

Утечки памяти
Есть: new t[cnt] без delete[] при раннем выходе или исключении. Решение – std::vector<Task> (автоматическое управление).

Поведение при cnt == 0 или 1

При 0 – массив нулевого размера, вывод ничего не покажет (цикл не выполнится).

При 1 – сортировка не нужна, вывод корректно покажет одну задачу.

Проверка сортировки
Написать модульный тест с известным порядком приоритетов, или вывести отсортированный список и сравнить вручную.



*/