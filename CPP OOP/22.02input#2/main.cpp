#include "phonebook.cpp"

using namespace std;

void showMenu() {
    cout << "\n========== ТЕЛЕФОННАЯ КНИГА ==========" << endl;
    cout << "1. Добавить абонента" << endl;
    cout << "2. Удалить абонента" << endl;
    cout << "3. Поиск по ФИО" << endl;
    cout << "4. Показать всех абонентов" << endl;
    cout << "5. Сохранить в файл" << endl;
    cout << "6. Загрузить из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "=======================================" << endl;
    cout << "Выберите действие: ";
}

int main() {
    PhoneBook phoneBook;
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                phoneBook.addAbonent();
                break;
            case 2:
                phoneBook.removeAbonent();
                break;
            case 3:
                phoneBook.searchByFullName();
                break;
            case 4:
                phoneBook.displayAll();
                break;
            case 5:
                phoneBook.saveToFile();
                break;
            case 6:
                phoneBook.loadFromFile();
                break;
            case 0:
                cout << "Программа завершена. До свидания!" << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
        }
    } while (choice != 0);
    
    return 0;
}