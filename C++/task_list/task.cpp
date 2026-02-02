#include "task.h"


Task tasks[max_tasks];
int task_count = 0;

long long calculate_minutes(string day_str, string month_str, string hour_str, string minutes_str) {
    long long day = stoi(day_str);
    long long month = stoi(month_str);
    long long hour = stoi(hour_str);
    long long minutes = stoi(minutes_str);
    return ((month - 1) * 30 + day) * 1440 + (hour * 60) + minutes;
}

void print_task(Task task) {
    cout << "\n\n=== Задача №" << task.id << " ===" << endl;
    cout << "Название: " << task.name << endl;
    if (task.priority == 1) cout << "Приоритет: Высокий" << endl;
    else if (task.priority == 2) cout << "Приоритет: Средний" << endl;
    else cout << "Приоритет: Низкий" << endl;
    
    cout << "Описание: " << task.description << endl;
    cout << "Дата исполнения: " << task.date.number << "." << task.date.month << " Время: " << task.time.hour << ":" << task.time.minutes << endl;
    cout << "================" << endl;
}

void create_task() {
    if (task_count < max_tasks) {
        tasks[task_count].id = task_count + 1;

        cout << "Название: ";
        cin.ignore();
        getline(cin, tasks[task_count].name);

        cout << "Приоритет (1-Высокий, 2-Средний, 3-Низкий): ";
        cin >> tasks[task_count].priority;

        cout << "Описание: ";
        cin.ignore();
        getline(cin, tasks[task_count].description);

        cout << "Дата (день месяц): ";
        cin >> tasks[task_count].date.number >> tasks[task_count].date.month;

        cout << "Время (час мин): ";
        cin >> tasks[task_count].time.hour >> tasks[task_count].time.minutes;

        task_count++;
        cout << "Задача добавлена!" << endl;
    } else {
        cout << "Массив переполнен!" << endl;
    }
}

void edit_task() {
    if (task_count == 0) {
        cout << "Список пуст!" << endl;
        return;
    }

    int id_to_edit;
    cout << "Введите ID задачи для редактирования: ";
    cin >> id_to_edit;

    int index = -1;
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id_to_edit) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Что изменить?\n1. Название\n2. Приоритет\n3. Описание\n4. Дату\n5. Время" << endl;
        int edit_choice;
        cin >> edit_choice;
        cin.ignore(); 

        switch (edit_choice) {
            case 1:
                cout << "Новое название: ";
                getline(cin, tasks[index].name);
                break;
            case 2:
                cout << "Новый приоритет (1-3): ";
                cin >> tasks[index].priority;
                break;
            case 3:
                cout << "Новое описание: ";
                getline(cin, tasks[index].description);
                break;
            case 4:
                cout << "Новая дата (день месяц): ";
                cin >> tasks[index].date.number >> tasks[index].date.month;
                break;
            case 5:
                cout << "Новое время (час мин): ";
                cin >> tasks[index].time.hour >> tasks[index].time.minutes;
                break;
            default:
                cout << "Неверный пункт!" << endl;
                break;
        }
    } else {
        cout << "Задача не найдена!" << endl;
    }
}

void find_task() {
    if (task_count == 0) {
        cout << "Искать нечего, список пуст!" << endl;
        return;
    }

    int search_choice;
    cout << "Искать по:\n1. Названию\n2. Приоритету\n3. Описанию" << endl;
    cin >> search_choice;
    cin.ignore();

    string query;
    int query_int;
    bool found = false;


    if (search_choice == 2) {
        cout << "Введите число приоритета: ";
        cin >> query_int;
    } else {
        cout << "Введите текст для поиска: ";
        getline(cin, query);
    }

    for (int i = 0; i < task_count; i++) {
        bool match = false;
        
        switch (search_choice) {
            case 1:
                if (tasks[i].name.find(query) != string::npos) match = true;
                break;
            case 2:
                if (tasks[i].priority == query_int) match = true;
                break;
            case 3:
                if (tasks[i].description.find(query) != string::npos) match = true;
                break;
        }

        if (match) {
            print_task(tasks[i]);
            found = true;
        }
    }

    if (!found) cout << "Ничего не найдено!" << endl;
}

void delete_task() {
    int id_to_find, index_to_delete = -1;
    cout << "Введите ID для удаления: ";
    cin >> id_to_find;

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id_to_find) { index_to_delete = i; break; }
    }

    if (index_to_delete != -1) {
        for (int i = index_to_delete; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        cout << "Удалено!" << endl;
    } else cout << "Не найдено!" << endl;
}

void show_task_list() {
    if (task_count == 0) {
        cout << "Список задач пуст!" << endl;
        return;
    }

    // Автоматическое текущее время 
    time_t now = time(0);
    tm *local_time = localtime(&now);

    string current_day = to_string(local_time->tm_mday);
    string current_month = to_string(1 + local_time->tm_mon); // +1 так как месяцы с 0
    string current_hour = to_string(local_time->tm_hour);
    string current_min = to_string(local_time->tm_min);

    // минуты 
    long long current_total_minutes = calculate_minutes(current_day, current_month, current_hour, current_min);

    cout << "\nСегодня: " << current_day << "." << current_month << " " << current_hour << ":" << current_min << endl;

    //  Фильтр по времени 
    int period_choice;
    cout << "Показать задачи на:\n1. Сегодня\n2. Неделю\n3. Месяц\nВыбор: ";
    cin >> period_choice;

    long long minutes_limit = 0;
    const int MINUTES_IN_DAY = 1440;

    if (period_choice == 1) minutes_limit = current_total_minutes + MINUTES_IN_DAY;
    else if (period_choice == 2) minutes_limit = current_total_minutes + (7 * MINUTES_IN_DAY);
    else if (period_choice == 3) minutes_limit = current_total_minutes + (30 * MINUTES_IN_DAY);


 //  Отбор задач во временный список 
    Task temp_list[max_tasks];
    int temp_count = 0;

    for (int i = 0; i < task_count; i++) {
        long long task_time = calculate_minutes(
            tasks[i].date.number, tasks[i].date.month, 
            tasks[i].time.hour, tasks[i].time.minutes
        );

        bool passes_filter = false;

        if (period_choice == 1) {
            if (tasks[i].date.number == current_day && tasks[i].date.month == current_month) {
                passes_filter = true;
            }
        } else {
            if (task_time >= current_total_minutes && task_time <= minutes_limit) {
                passes_filter = true;
            }
        }

        if (passes_filter) {
            temp_list[temp_count] = tasks[i];
            temp_count++;
        }
    }

    // Сортировка
    int sort_choice;
    cout << "Сортировать по:\n1. Времени (сначала ближайшие)\n2. Приоритету (сначала важные)\nВыбор: ";
    cin >> sort_choice;

    for (int i = 0; i < temp_count - 1; i++) {
        for (int j = 0; j < temp_count - i - 1; j++) {
            bool need_swap = false;
            
            long long time1 = calculate_minutes(temp_list[j].date.number, temp_list[j].date.month, temp_list[j].time.hour, temp_list[j].time.minutes);
            long long time2 = calculate_minutes(temp_list[j+1].date.number, temp_list[j+1].date.month, temp_list[j+1].time.hour, temp_list[j+1].time.minutes);

            if (sort_choice == 1) {
                // По времени: если первая задача позже второй -> меняем
                if (time1 > time2) need_swap = true;
            } else {
                // По приоритету: если приоритет больше (цифра 3 хуже 1) -> меняем
                if (temp_list[j].priority > temp_list[j+1].priority) need_swap = true;
                // Если приоритеты равны, то кто раньше по времени -> тот выше
                else if (temp_list[j].priority == temp_list[j+1].priority && time1 > time2) need_swap = true;
            }

            if (need_swap) {
                Task buffer = temp_list[j];
                temp_list[j] = temp_list[j+1];
                temp_list[j+1] = buffer;
            }
        }
    }

    // Вывод 
    


    cout << "\n--- СПИСОК ЗАДАЧ ---" << endl;
    for (int i = 0; i < temp_count; i++) {
        print_task(temp_list[i]);
    }
    if (temp_count == 0) {
        cout << "\nЗадач на выбранный период не найдено." << endl;
    } else {
        cout << "\nПоказано задач: " << temp_count << endl;
    }
}

void save_to_file() {
    if (!fs::exists("data")) {
        fs::create_directory("data");
    }

    // открываем файл
    ofstream file("data/tasks.txt");


    if (!file.is_open()) {
        cout << "Ошибка: не удалось сохранить задачи!" << endl;
        return;
    }

    for (int i = 0; i < task_count; i++) {
        file << tasks[i].id << endl;
        file << tasks[i].name << endl;
        file << tasks[i].priority << endl;
        file << tasks[i].description << endl;
        file << tasks[i].date.number << " " << tasks[i].date.month << endl;
        file << tasks[i].time.hour << " " << tasks[i].time.minutes << endl;
    }

    file.close();
    cout << "Изменения сохранены." << endl;
}

void load_from_file() {
    ifstream file("data/tasks.txt");

    if (!file.is_open()) {
        return;
    }

    task_count = 0;
    while (file >> tasks[task_count].id) {
        file.ignore();
        getline(file, tasks[task_count].name);
        file >> tasks[task_count].priority;
        file.ignore();
        getline(file, tasks[task_count].description);
        file >> tasks[task_count].date.number >> tasks[task_count].date.month;
        file >> tasks[task_count].time.hour >> tasks[task_count].time.minutes;
        
        task_count++;
        if (task_count >= max_tasks) break;
    }

    file.close();
    cout << "Задачи успешно загружены! (Всего: " << task_count << ")" << endl;
}