#include "ShapeArea.cpp"
#include <iostream>
using namespace std;

int main() {
    int choice;
    
    do {
        cout << "\n========== КАЛЬКУЛЯТОР ПЛОЩАДИ ==========\n";
        cout << "1. Треугольник (по трем сторонам)\n";
        cout << "2. Треугольник (по основанию и высоте)\n";
        cout << "3. Треугольник (по двум сторонам и углу)\n";
        cout << "4. Прямоугольник\n";
        cout << "5. Квадрат\n";
        cout << "6. Ромб (по диагоналям)\n";
        cout << "7. Ромб (по стороне и высоте)\n";
        cout << "8. Ромб (по стороне и углу)\n";
        cout << "9. Показать статистику\n";
        cout << "0. Выход\n";
        cout << "========================================\n";
        cout << "Выберите действие: ";
        cin >> choice;
        
        double a, b, c, result;
        
        switch(choice) {
            case 1:
                cout << "\nВведите три стороны треугольника: ";
                cin >> a >> b >> c;
                if(a + b > c && a + c > b && b + c > a) {
                    result = ShapeArea::triangleHeron(a, b, c);
                    cout << "Площадь треугольника = " << result << endl;
                } else {
                    cout << "Треугольник не существует!\n";
                }
                break;
                
            case 2:
                cout << "\nВведите основание и высоту: ";
                cin >> a >> b;
                result = ShapeArea::triangleBaseHeight(a, b);
                cout << "Площадь треугольника = " << result << endl;
                break;
                
            case 3:
                cout << "\nВведите две стороны и угол (в градусах): ";
                cin >> a >> b >> c;
                result = ShapeArea::triangleTwoSidesAngle(a, b, c);
                cout << "Площадь треугольника = " << result << endl;
                break;
                
            case 4:
                cout << "\nВведите длину и ширину: ";
                cin >> a >> b;
                result = ShapeArea::rectangle(a, b);
                cout << "Площадь прямоугольника = " << result << endl;
                break;
                
            case 5:
                cout << "\nВведите сторону квадрата: ";
                cin >> a;
                result = ShapeArea::square(a);
                cout << "Площадь квадрата = " << result << endl;
                break;
                
            case 6:
                cout << "\nВведите диагонали ромба: ";
                cin >> a >> b;
                result = ShapeArea::rhombusDiagonals(a, b);
                cout << "Площадь ромба = " << result << endl;
                break;
                
            case 7:
                cout << "\nВведите сторону и высоту ромба: ";
                cin >> a >> b;
                result = ShapeArea::rhombusSideHeight(a, b);
                cout << "Площадь ромба = " << result << endl;
                break;
                
            case 8:
                cout << "\nВведите сторону и угол ромба (в градусах): ";
                cin >> a >> b;
                result = ShapeArea::rhombusSideAngle(a, b);
                cout << "Площадь ромба = " << result << endl;
                break;
                
            case 9:
                cout << "\nВсего вычислений: " << ShapeArea::getCount() << endl;
                cout << "Хотите сбросить счетчик? (1 - да, 0 - нет): ";
                cin >> a;
                if(a == 1) {
                    ShapeArea::resetCount();
                    cout << "Счетчик сброшен!\n";
                }
                break;
                
            case 0:
                cout << "\nВсего вычислений за сессию: " << ShapeArea::getCount() << endl;
                cout << "До свидания!\n";
                break;
                
            default:
                cout << "\nНеверный выбор! Попробуйте снова.\n";
        }
        
        if(choice != 0 && choice != 9) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
        
    } while(choice != 0);
    
    return 0;
}