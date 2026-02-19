#include <iostream>
#include <fstream>
#include <string>
#include "Point.cpp"
using namespace std;


int main() {
    setlocale(LC_ALL, "Ru");
    
    Point point;
    string filename;
    int choice;
    int x, y, z;
    
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Ввести координаты" << endl;
        cout << "2. Показать координаты" << endl;
        cout << "3. Сохранить в файл" << endl;
        cout << "4. Загрузить из файла" << endl;
        cout << "5. Выход" << endl;
        cout << "Выбери: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Введи X: ";
                cin >> x;
                cout << "Введи Y: ";
                cin >> y;
                cout << "Введи Z: ";
                cin >> z;
                
                point.SetX(x);
                point.SetY(y);
                point.SetZ(z);
                cout << "Координаты сохранены!" << endl;
                break;
                
            case 2:
                point.PrintPoint();
                break;
                
            case 3:
                cout << "Введи имя файла для сохранения: ";
                cin >> filename;
                point.SaveToFile(filename);
                break;
                
            case 4:
                cout << "Введи имя файла для загрузки: ";
                cin >> filename;
                point.LoadFromFile(filename);
                break;
                
            case 5:
                cout << "Пока!" << endl;
                break;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
        
    } while(choice != 5);
    
    return 0;
}