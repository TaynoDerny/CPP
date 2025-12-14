#include <iostream>
using namespace std;

// Рекурсивная функция для перемещения дисков
void moveDisks(int n, char A, char C, char B) {
    // Если диск один 
    if (n == 1) {
        cout << "Диск 1: " << A << " -> " << C << endl;
        return;
    }
    
    // Верхние диски: A -> B (используя C как помощь)
    moveDisks(n - 1, A, B, C);
    
    // Самый большой диск: A -> C
    cout << "Диск " << n << ": " << A << " -> " << C << endl;
    
    // Диски с B: B -> C (используя A как помощь)
    moveDisks(n - 1, B, C, A);
}

int main() {
    int disks;
    cout << "ХАНОЙСКАЯ БАШНЯ" << endl;
    cout << "Сколько дисков? (от 1 до 8): ";
    cin >> disks;
    
    if (disks < 1) {
        cout << "Должен быть хотя бы 1 диск" << endl;
        return 1;
    }
    
    cout << endl << "Как перемещать:" << endl<<endl;
    
    // A - начальный стержень, C - конечный, B - вспомогательный
    moveDisks(disks, 'A', 'C', 'B');
    
    cout << endl << "Все диски перемещены." << endl;
    
    return 0;
}
