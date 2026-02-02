#include "employee.h"
#include <iostream>

using namespace std;

int main() {
    loadFromFile();
    
    while (true) {
        cout << "\n=== Система Сотрудники ===\n";
        cout << "1. Добавить\n";
        cout << "2. Показать всех\n";
        cout << "3. Поиск по возрасту\n";
        cout << "4. Поиск по букве\n";
        cout << "5. Удалить\n";
        cout << "6. Редактировать\n";
        cout << "7. Сохранить\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: showAll(); break;
            case 3: searchByAge(); break;
            case 4: searchByLetter(); break;
            case 5: deleteEmployee(); break;
            case 6: editEmployee(); break;
            case 7: saveToFile(); break;
            case 0: 
                saveToFile();
                cout << "Сохранено. Выход.\n";
                return 0;
            default: cout << "Ошибка!\n";
        }
    }
}