
#include "task.h"
int main() {
    int menu_choice;
    load_from_file();
    do {
        cout << "\n--- МЕНЮ ---\n1. Список задач\n2. Добавить задачу\n3. Редактировать задачу\n4. Найти задачу\n5. Удалить задачу\n0. Выход\nВыбор: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 1: show_task_list();break;
            case 2: create_task(); break;
            case 3: edit_task(); break;
            case 4: find_task(); break;
            case 5: delete_task(); break;
        }
        if (menu_choice != 0) save_to_file();
    } while (menu_choice != 0);
    return 0;
}