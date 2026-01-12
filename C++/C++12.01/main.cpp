#include <iostream>
#include <string>
using namespace std;

int main() {
    

    
    // Задача 1.1
    cout << "Задача 1.1:" << endl;
    int num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    
    // Задача 1.2
    cout << "\nЗадача 1.2:" << endl;
    double celsius;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> celsius;
    double fahrenheit = celsius * 9.0 / 5.0 + 32;
    cout << celsius << "C = " << fahrenheit << "F" << endl;
    

    
    // Задача 2.1
    cout << "\nЗадача 2.1:" << endl;
    int number;
    cout << "Введите число: ";
    cin >> number;
    if (number % 2 == 0) {
        cout << number << " - четное число." << endl;
    } else {
        cout << number << " - нечетное число." << endl;
    }
    
    // Задача 2.2
    cout << "\nЗадача 2.2:" << endl;
    int year;
    cout << "Введите год: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " - високосный год." << endl;
    } else {
        cout << year << " - не високосный год." << endl;
    }
    

    
    // Задача 3.1
    cout << "\nЗадача 3.1:" << endl;
    int N;
    cout << "Введите N: ";
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << "Сумма чисел от 1 до " << N << " равна " << sum << "." << endl;
    
    // Задача 3.2
    cout << "\nЗадача 3.2:" << endl;
    int multiplier;
    cout << "Введите число для таблицы умножения: ";
    cin >> multiplier;
    for (int i = 1; i <= 10; i++) {
        cout << multiplier << " x " << i << " = " << multiplier * i << endl;
    }

    
    // Задача 4.1
    cout << "\nЗадача 4.1:" << endl;
    const int size1 = 10;
    int arr1[size1];
    cout << "Введите " << size1 << " целых чисел: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    int min = arr1[0];
    for (int i = 1; i < size1; i++) {
        if (arr1[i] < min) {
            min = arr1[i];
        }
    }
    cout << "Минимальный элемент: " << min << endl;
    
    // Задача 4.2
    cout << "\nЗадача 4.2:" << endl;
    const int rows = 3, cols = 3;
    int matrix[rows][cols];
    cout << "Введите " << rows * cols << " чисел для матрицы 3x3: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Сумма строки " << i + 1 << ": " << rowSum << endl;
    }
    

    
    // Задача 5.1
    cout << "\nЗадача 5.1:" << endl;
    auto maxFunc = [](int a, int b) -> int {
        return (a > b) ? a : b;
    };
    int a1, b1;
    cout << "Введите два целых числа: ";
    cin >> a1 >> b1;
    cout << "Наибольшее число: " << maxFunc(a1, b1) << endl;
    
    // Задача 5.2
    cout << "\nЗадача 5.2:" << endl;
    auto isPrime = [](int n) -> bool {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    };
    int primeNum;
    cout << "Введите число для проверки: ";
    cin >> primeNum;
    if (isPrime(primeNum)) {
        cout << primeNum << " - простое число." << endl;
    } else {
        cout << primeNum << " - не простое число." << endl;
    }

    
    // Задача 6.1
    cout << "\nЗадача 6.1:" << endl;
    int x = 10, y = 20;
    cout << "До: a = " << x << ", b = " << y << endl;
    int *px = &x, *py = &y;
    int temp = *px;
    *px = *py;
    *py = temp;
    cout << "После: a = " << x << ", b = " << y << endl;
    
    // Задача 6.2
    cout << "\nЗадача 6.2:" << endl;
    const int size2 = 5;
    int arr2[size2] = {1, 2, 3, 4, 5};
    int *ptr = arr2;
    int sumPtr = 0;
    for (int i = 0; i < size2; i++) {
        sumPtr += *(ptr + i);
    }
    cout << "Сумма элементов: " << sumPtr << endl;
    

    
    // Задача 7.1
    cout << "\nЗадача 7.1:" << endl;
    cin.ignore(); 
    string str1;
    cout << "Введите строку: ";
    getline(cin, str1);
    int length = 0;
    const char *cstr = str1.c_str();
    while (cstr[length] != '\0') {
        length++;
    }
    cout << "Длина строки \"" << str1 << "\" равна " << length << " символам." << endl;
    
    // Задача 7.2
    cout << "\nЗадача 7.2:" << endl;
    string str2;
    cout << "Введите строку: ";
    getline(cin, str2);
    int vowelCount = 0;
    for (char ch : str2) {
        char lower = tolower(ch);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' || 
            lower == 'а' || lower == 'е' || lower == 'и' || lower == 'о' || lower == 'у' || 
            lower == 'э' || lower == 'ы' || lower == 'ю' || lower == 'я') {
            vowelCount++;
        }
    }
    cout << "Количество гласных: " << vowelCount << endl;
    
  
    return 0;
}