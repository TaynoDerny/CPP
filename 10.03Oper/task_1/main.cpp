#include <iostream>
#include "Date.cpp"

using namespace std;

int main() {
    int d1, m1, y1, d2, m2, y2, choice, days;
    
    cout << "Введите первую дату (день месяц год): ";
    cin >> d1 >> m1 >> y1;
    Date date1(d1, m1, y1);
    
    cout << "Выберите операцию:\n1 - Разность дат\n2 - Увеличить дату на дни\n";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Введите вторую дату (день месяц год): ";
        cin >> d2 >> m2 >> y2;
        Date date2(d2, m2, y2);
        
        int diff = date2 - date1;
        cout << "Разность: " << diff << " дней" << endl;
    }
    else if (choice == 2) {
        cout << "Введите количество дней: ";
        cin >> days;
        
        Date newDate = date1 + days;
        cout << "Новая дата: ";
        newDate.display();
    }
    
    return 0;
}