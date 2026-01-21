#include <iostream>

using namespace std;

void planner_route(int dist, int countSt, int fuelDist, int stations[]) {
    cout << "Расстояние от Петербурга до Москвы " << dist << " км." << endl;
    cout << "Количество заправок на пути " << countSt << endl;
    cout << "Бака машины хватит на " << fuelDist << " км." << endl << endl;
    
    int pos = 0;              // текущая позиция
    int lastSt = 0;           // последняя доступная заправка
    int stopCount = 0;        // счетчик заправок
    int stopNums[100];        // номера заправок для заправки
    int stopIdx = 0;
    
    cout << "Начало пути!!" << endl << endl;
    
    int i = 0;
    while (i < countSt) {
        if (stations[i] - pos <= fuelDist) {
            lastSt = stations[i];
            i++;
        } 
        else {

            if (lastSt > pos) {
                pos = lastSt;
                stopCount++;
                stopNums[stopIdx++] = i;  
                cout << "Остановка на заправке на " << pos << " километре" << endl;
                cout << "Заправляем полный бак..." << endl;
            } 
            else {
                cout << endl << "Машина не доедет! Не хватает бензина до заправки" << endl;
                return;
            }
        }
    }
    
    if (dist - pos <= fuelDist) {
        cout << endl << "Вы доехали до Москвы!!" << endl;
        cout << "Минимальное количество заправок: " << stopCount << endl;
    } 
    else {
        
        if (lastSt > pos) {
            pos = lastSt;
            stopCount++;
            stopNums[stopIdx++] = countSt - 1;  
            cout << "Остановка на заправке на " << pos << " километре" << endl;
            cout << "Заправляем полный бак..." << endl;
        }
        
        if (dist - pos <= fuelDist) {
            cout << endl << "Вы доехали до Москвы!!" << endl;
            cout << "Минимальное количество заправок: " << stopCount << endl;
        } 
        else {
            cout << endl << "Вы не доехали до Москвы!" << endl;
            cout << "Бензин закончился на " << pos + fuelDist << " километре" << endl;
            return;
        }
    }
    
    // выводим номера заправок
    if (stopCount > 0) {
        cout << "Номера заправок, на которых нужно заправиться (начиная с 1): ";
        for (int j = 0; j < stopIdx; j++) {
            cout << stopNums[j] + 1 << " ";
        }
        cout << endl;
    }
}
//Задача 2
void sortMeetings(int start[], int end[], int index[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (end[j] > end[j + 1]) {
                
                int tempEnd = end[j];
                end[j] = end[j + 1];
                end[j + 1] = tempEnd;
                
                int tempStart = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tempStart;
                
                int tempIndex = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tempIndex;
            }
        }
    }
}

int main() {
    int dist;
    int countSt;
    int fuelDist;
    
    cout << "Введите расстояние, которое может проехать машина на одном баке: ";
    cin >> fuelDist;
    
    cout << "Введите расстояние пути от Петербурга до Москвы: ";
    cin >> dist;
    
    cout << "Введите количество заправочных станций (не учитывая начальный и конечный город): ";
    cin >> countSt;
    
    int stations[countSt];
    
    for (int i = 0; i < countSt; i++) {
        cout << "Введите на каком километре пути расположена " << i+1 << " заправка: ";
        cin >> stations[i];
        
        if (stations[i] >= dist || stations[i] <= 0) {
            cout << "Ошибка - Вы ввели не корректное значение" << endl;
            return 1;
        }
    }
    
    for (int i = 1; i < countSt; i++) {
        if (stations[i] <= stations[i-1]) {
            cout << "Ошибка: станции должны быть в порядке возрастания!" << endl;
            return 1;
        }
    }
    
    planner_route(dist, countSt, fuelDist, stations);

    //Задача 2
    int n;
    cout << "Введите количество приглашений на заседания: ";
    cin >> n;
    

    int start[n];  // время начала заседаний
    int end[n];    // время окончания заседаний
    int index[n];  // исходные номера заседаний
    
    // Ввод данных о заседаниях
    for (int i = 0; i < n; i++) {
        cout << "Введите начало и конец " << i + 1 << "-го заседания: ";
        cin >> start[i] >> end[i];
        index[i] = i + 1; 
        
        if (start[i] >= end[i]) {
            cout << "Ошибка: начало заседания должно быть раньше конца!" << endl;
            return 1;
        }
    }
    
    // Сортировка заседания по времени окончания
    sortMeetings(start, end, index, n);
    
  
    int selectedCount = 0;  // количество выбранных заседаний
    int selectedIndices[n]; // номера выбранных заседаний 
    int lastEndTime = -1;   // время окончания последнего выбранного заседания
    
    cout << "\nОтсортированные заседания (по времени окончания):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Заседание " << index[i] << ": " 
             << start[i] << " - " << end[i] << endl;
    }
    
    cout << "\nПроцесс выбора заседаний:" << endl;
    
    for (int i = 0; i < n; i++) {
        if (start[i] >= lastEndTime) {
            selectedIndices[selectedCount] = index[i];
            selectedCount++;
            lastEndTime = end[i];
            
            cout << "Выбрано заседание №" << index[i] 
                 << " (" << start[i] << " - " << end[i] << ")" << endl;
        }
    }
    
    // Вывод результатов
    cout << "\nРЕЗУЛЬТАТЫ:" << endl;
    cout << "Максимальное количество заседаний, которые можно посетить: " << selectedCount << endl;
    
    if (selectedCount > 0) {
        cout << "Номера выбранных заседаний (в исходном порядке): ";
        for (int i = 0; i < selectedCount; i++) {
            cout << selectedIndices[i];
            if (i < selectedCount - 1) cout << ", ";
        }
        cout << endl;
        
        // Сортировка выбранных номеров для вывода
        for (int i = 0; i < selectedCount - 1; i++) {
            for (int j = 0; j < selectedCount - i - 1; j++) {
                if (selectedIndices[j] > selectedIndices[j + 1]) {
                    int temp = selectedIndices[j];
                    selectedIndices[j] = selectedIndices[j + 1];
                    selectedIndices[j + 1] = temp;
                }
            }
        }
        
        cout << "Номера выбранных заседаний : ";
        for (int i = 0; i < selectedCount; i++) {
            cout << selectedIndices[i];
            if (i < selectedCount - 1) cout << ", ";
        }
        cout << endl;
    }
    








    
    return 0;
}