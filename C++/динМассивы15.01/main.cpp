#include <iostream>

using namespace std;

// Задание 1
int** rowEnd(int** arr, int rows, int cols) {
    // Создание нового массива 
    int** newArr = new int*[rows + 1];
    
    // Копирование старых строк
    for (int i = 0; i < rows; i++) {
        newArr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    
    // Добавление новой строки 
    newArr[rows] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[rows][j] = 0; 
    }
    
    // Удаление старого массива
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return newArr;
}

// Задание 2
int** RowStart(int** arr, int rows, int cols) {
    // Создание нового массива 
    int** newArr = new int*[rows + 1];
    
    // Добавление новой строки 
    newArr[0] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[0][j] = 0; 
    }
    
    // Копирование старых строк 
    for (int i = 0; i < rows; i++) {
        newArr[i + 1] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i + 1][j] = arr[i][j];
        }
    }
    
    // Удаление старого массива
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return newArr;
}

// Задание 3
int** rowAtPosition(int** arr, int rows, int cols, int position) {
    if (position < 0 || position > rows) {
        cout << "Некорректная позиция!" << endl;
        return arr;
    }
    
    // Создание нового массива 
    int** newArr = new int*[rows + 1];
    
    // Копирование строк 
    for (int i = 0; i < position; i++) {
        newArr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    
    // Добавление новой строки 
    newArr[position] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[position][j] = 0; 
    }
    
    // Копирование строк 
    for (int i = position; i < rows; i++) {
        newArr[i + 1] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i + 1][j] = arr[i][j];
        }
    }
    
    // Удаление старого массива
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return newArr;
}

// Задание 4
int** delRowAtPositior(int** arr, int rows, int cols, int position) {
    if (position < 0 || position >= rows) {
        cout << "Некорректная позиция!" << endl;
        return arr;
    }
    
    if (rows == 1) {
        cout << "Нельзя удалить последнюю строку!" << endl;
        return arr;
    }
    
    // Создание нового массива 
    int** newArr = new int*[rows - 1];
    
    // Копирование строк до удаляемой
    for (int i = 0; i < position; i++) {
        newArr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i][j] = arr[i][j];
        }
    }
    
    // Копирование строк после удаляемой 
    for (int i = position + 1; i < rows; i++) {
        newArr[i - 1] = new int[cols];
        for (int j = 0; j < cols; j++) {
            newArr[i - 1][j] = arr[i][j];
        }
    }
    
    // Удаление старого массива
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return newArr;
}

// функция для вывода массива
void printArray(int** arr, int rows, int cols) {
    cout << "Массив " << rows << "x" << cols << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// функция для создания тестового массива
int** createTestArray(int rows, int cols) {
    int** arr = new int*[rows];
    int counter = 1;
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            arr[i][j] = counter++;
        }
    }
    return arr;
}

int main() {
    int rows;
    int cols;
    cout << "Введите количество строчек для массива: ";
    cin >> rows;
    cout << "Введите количество столбцов для массива: ";
    cin >> cols;
    
    cout << "\n****** Задание 1: Добавление строки в конец ******" << endl;
    int** arr1 = createTestArray(rows, cols);
    printArray(arr1, rows, cols);
    
    arr1 = rowEnd(arr1, rows, cols);
    printArray(arr1, rows + 1, cols);
    
    // Очистка памяти
    for (int i = 0; i < rows + 1; i++) delete[] arr1[i];
    delete[] arr1;
    
    cout << "****** Задание 2: Добавление строки в начало ******" << endl;
    int** arr2 = createTestArray(rows, cols);
    printArray(arr2, rows, cols);
    
    arr2 = RowStart(arr2, rows, cols);
    printArray(arr2, rows + 1, cols);
    
    // Очистка памяти
    for (int i = 0; i < rows + 1; i++) delete[] arr2[i];
    delete[] arr2;
    
    cout << "****** Задание 3: Добавление строки в указанную позицию ******" << endl;
    int position;
    cout << "Введите позицию для добавления строки (0-" << rows << "): ";
    cin >> position;
    
    int** arr3 = createTestArray(rows, cols);
    printArray(arr3, rows, cols);
    
    arr3 = rowAtPosition(arr3, rows, cols, position);
    printArray(arr3, rows + 1, cols);
    
    // Очистка памяти
    for (int i = 0; i < rows + 1; i++) delete[] arr3[i];
    delete[] arr3;
    
    cout << "****** Задание 4: Удаление строки из указанной позиции ******" << endl;
    int delPosition;
    cout << "Введите позицию для удаления строки (0-" << (rows-1) << "): ";
    cin >> delPosition;
    
    int** arr4 = createTestArray(rows, cols);
    printArray(arr4, rows, cols);
    
    arr4 = delRowAtPositior(arr4, rows, cols, delPosition);
    printArray(arr4, rows - 1, cols);
    
    // Очистка памяти
    for (int i = 0; i < rows - 1; i++) delete[] arr4[i];
    delete[] arr4;
    
    return 0;
}