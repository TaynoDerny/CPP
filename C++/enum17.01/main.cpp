#include <iostream>
#include <string>


using namespace std;
/// Задача 1
enum ErrorCode {
    SUCCESS,
    FILE_NOT_FOUND,
    ACCESS_DENIED,
    OUT_OF_MEMORY
};
// Задача 2
enum Day {
    MONDAY = 1 ,    // понедельник (1)
    TUESDAY,   // вторник (2)
    WEDNESDAY, // среда (3)
    THURSDAY,  // четверг (4)
    FRIDAY,    // пятница (5)
    SATURDAY,  // суббота (6)
    SUNDAY     // воскресенье (7)
};
// Задача 3
enum trafficLight {
    RED,
    YELLOW,
    GREEN
}; 
// Задача 5
enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};
// Задача 8
enum SortOrder {
    ASCENDING,
    DESCENDING
};
// Задача 1
void task1(int num_file){
    switch (num_file) {
        case SUCCESS:
            cout << "Успешно" << endl;
            break;
        case FILE_NOT_FOUND:
            cout << "Файл не найден" << endl;
            break;
        case ACCESS_DENIED:
            cout << "Доступ запрещен" << endl;
            break;
        case OUT_OF_MEMORY:
            cout << "Недостаточно памяти" << endl;
            break;
    }
}
// Задача 2
void task2(int dayWeek){
    switch (dayWeek)
        {
        case MONDAY:
            cout << "Понедельник"<<endl;
            cout << "Рабочий день"<<endl;
            break;
        case TUESDAY:
            cout << "Вторник"<<endl;
            cout << "Рабочий день"<<endl;
            break;
        case WEDNESDAY:
            cout << "Среда"<<endl;
            cout << "Рабочий день"<<endl;
            break;
        case THURSDAY:
            cout << "Четверг"<<endl;
            cout << "Рабочий день"<<endl;
            break;
        case FRIDAY:
            cout << "Пятница"<<endl;
            cout << "Рабочий день"<<endl;
            break;
        case SATURDAY:
            cout << "Суббота"<<endl;
            cout << "Выходной день"<<endl;
            break;
        case SUNDAY:
            cout << "Понедельник"<<endl;
            cout << "Выходной день"<<endl;
            break;
        default:
            cout << "ОШИБКА - Введите от 1 до 7"<<endl;
            break;
    }
}
// Задача 3
void task3(){
    for (int i = 0; i < 2; i++)
    {
        switch (i)
        {
        case RED:
            cout<<"Красный"<<endl;
            break;
        case YELLOW:
            cout << "Желтый"<<endl;
        case GREEN:
            cout << "Зеленный"<<endl;
            break;
        default:
            break;
        }
    }
}
// Задача 5
string getLevel(LogLevel level) {
    switch (level) {
        case DEBUG:    return "DEBUG";
        case INFO:     return "INFO";
        case WARNING:  return "WARNING";
        case ERROR:    return "ERROR";
        case CRITICAL: return "CRITICAL";
        default:       return "UNKNOWN";
    }
}
string getTime() {
    // Простая имитация времени
    static int counter = 0;
    counter++;
    return "10:00:" + to_string(counter)+"0";
}
void logMessage(LogLevel level, string message){
    string time = getTime();
    string levelName = getLevel(level);

    cout << "[" << time << "] [" << levelName << "] " << message << endl;
    
}
void task5() {
    logMessage(INFO, "Приложение запущено");
    logMessage(DEBUG, "Загрузка настроек");
    logMessage(WARNING, "Память на исходе");
    logMessage(ERROR, "Не удалось открыть файл");
    logMessage(CRITICAL, "Критическая ошибка системы");
    
    cout << endl;
}
    

// Задача 8
void bubbleSort(int arr[], int size, SortOrder order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool shouldSwap = false;
            
            if (order == ASCENDING) {
                shouldSwap = arr[j] > arr[j + 1];
            } else {
                shouldSwap = arr[j] < arr[j + 1];
            }
            
            if (shouldSwap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// вывод массива 
void printArray(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;
}

void task8() {
    cout << " Режимы сортировки данных " << endl;
    
    int numbers[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int size = 9;
    
    cout << "Исходный массив: ";
    printArray(numbers, size);
    
    // копии для сортировки
    int ascending[9];
    int descending[9];
    
    for (int i = 0; i < size; i++) {
        ascending[i] = numbers[i];
        descending[i] = numbers[i];
    }
    
    bubbleSort(ascending, size, ASCENDING);
    cout << "По возрастанию:  ";
    printArray(ascending, size);
    
    bubbleSort(descending, size, DESCENDING);
    cout << "По убыванию:     ";
    printArray(descending, size);
    
    cout << endl;
}
int main(){
    
    int file_open;
    cout << "Выберите фаил который хотите открыть:\ntext.txt - 0\nfrica.docx - 1\nadmin.bat - 2\ntable.exc - 3"<<endl;
    cin >> file_open;
    task1(file_open);
    cout<<endl;

    int dayWeek;
    cout << "Введите день недели от 1 до 7:"<<endl;
    cin >> dayWeek;
    task2(dayWeek);
    cout <<endl;

    task3();
    cout <<endl;

    task5();
    cout <<endl;
    
    task8();

    return 0;
}
