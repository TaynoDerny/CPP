#include <iostream>

using namespace std;
// Задача 1.1
int sum(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int mul(int a,int b){
    return a*b;
}
int div_(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
}


// Задача 1.2

int compareStrings(const char* a, const char* b) {
    int i = 0;
    while (a[i]!='\0'){
        i++;
    }
    int j = 0;
    while (b[j]!='\0'){
        j++;
    }
    if (i>j){
        return -1;
    }
    else if (j>i){
        return 1;
    }
    else return 0;

    
}



void bubbleSort(int arr[], int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


bool ascending(int a, int b) {
    return a > b;
}
bool descending(int a, int b) {
    return a < b;
}
// Задача 3.1
void openFile() { cout << "Открываю файл..." << endl; }
void saveFile() { cout << "Сохраняю файл..." << endl; }
void exitProg() { cout << "Выхожу из программы..." << endl; }
// Задача 5.1
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}


// Задача 5.2
double multiplyByPi(int x) {
    return x * 3.14159;
}


double (*funcOld())(int) {
    return multiplyByPi;
}


auto funcNew() -> double (*)(int) {
    return multiplyByPi;
}

using MathFunc = double (*)(int);

MathFunc funcUsing() {
    return multiplyByPi;
}

int main(){
    // Задача 1.1
    int (*operation)(int, int);
    int num_1_1,num_1_2;
    char op;

    cout <<"Введите первое число:"<<endl;
    cin >> num_1_1;
    cout << "Введите операцию (+,-,*,/):"<<endl;
    cin>>op;
    cout << "Введите второе число:"<<endl;
    cin >> num_1_2;

    switch(op) {
        case '+':
            operation = sum;
            break;
        case '-':
            operation = sub;
            break;
        case '*':
            operation = mul;
            break;
        case '/':
            operation = div_;
            break;
        default:
            cout << "Неизвестная операция!" << endl;
            return 1;
    }

    int result = operation(num_1_1,num_1_2);
    cout << "Результат: "<<num_1_1<<" "<<op<<" "<<num_1_2<<" = "<<result<<endl;

    
    // Задача 1.2
    int (*compareFunc)(const char*, const char*); 

    const int size = 100;
    char str1[size];
    char str2[size];
    compareFunc = compareStrings;
    
    cin.ignore(1000, '\n');  // очистка буфера
    cout << "Введите первую строку: "<<endl;
    cin.getline(str1, size);
    
    cout << "Введите вторую строку: "<<endl;
    cin.getline(str2, size);

    int result_2 = compareFunc(str1,str2);
    if (result_2<0){
        cout <<str1<<" > "<<str2<<endl;
    }
    else if (result_2>0){
        cout <<str1<<" < "<<str2<<endl;
    }
    else cout <<str1<<" = "<<str2<<endl;


    // Задача 2.1
    int sizeUser;
    // Создание массива
    cout << "Введите размер массива:"<<endl;
    cin >> sizeUser;
    int* arr = new int[sizeUser];
    for (int i = 0; i < sizeUser; i++)
    {
        cout << "Введите "<<i<<" элемент массива:"<<endl;
        cin >> arr[i];
    }
    // Вывод исходного массива
    cout <<endl<<"Исходный массив:"<< endl;
    printarray(arr,sizeUser);
    cout <<endl;

    cout << "Выберите сортировку:\nПо возрастанию - 1\nПо убыванию - 2"<<endl;
    int choice;
    cin>>choice;
    

    // Указатель на функцию-компаратор
    bool (*comparator)(int, int) = nullptr;
    
    // Выбор компаратора
    if (choice == 1) {
        comparator = ascending;
        cout << "\nСортировка по возрастанию..." << endl;
    } else if (choice == 2) {
        comparator = descending;
        cout << "\nСортировка по убыванию..." << endl;
    } else {
        cout << "Неверный выбор!" << endl;
        delete[] arr;
        return 1;
    }
    
    // Сортировка массива
    bubbleSort(arr, sizeUser, comparator);
    
    // Вывод результата
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < sizeUser; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    
    // Задача 3.1
    cin.ignore(1000, '\n');  // очистка буфера перед меню
    
    void (*actions[3])() = {openFile, saveFile, exitProg};
    
    int choice2;  // изменено с choicee на choice2 (но если хочешь choicee - оставь choicee)
    
    while (true) {
        cout << "\nМеню:\n1. Открыть файл\n2. Сохранить файл\n3. Выход\nВыбор: ";
        cin >> choice2;
        
        if (choice2 < 1 || choice2 > 3) {
            cout << "Ошибка!" << endl;
            cin.clear();  // сброс флага ошибки
            cin.ignore(1000, '\n');  // очистка буфера
            continue;
        }
        
        actions[choice2 - 1]();
        
        if (choice2 == 3) break;
    }
    
    // Задача 4.2
    int a = 5;
    double b = 3.14;

    decltype(a * b) c1;

    c1 = a * b;
    cout << "\ndecltype: c1 = " << c1 << endl;

    auto c2 = a * b;  
    cout << "auto: c2 = " << c2 << endl;
    


    //Задача  5.1

    // 1. Сложение int и double
    // decltype(a + b) определяет тип выражения 5 + 3.14
    // int + double = double
    cout << "\n5 + 3.14 = " << add(5, 3.14) << endl;
    
    // 2. Сложение char и int  
    // char + int = int (char приводится к int)
    cout << "'A' + 5 = " << add('A', 5) << " (символ: " << char(add('A', 5)) << ")" << endl;
    
    // 3. Сложение unsigned и int
    unsigned u = 10;
    int i = -5;
    cout << "10u + (-5) = " << add(u, i) << endl;
    
    // Задача 5.2

    cout << "\nОбычный способ: " << funcOld()(5) << endl;
    cout << "С хвостовым типом: " << funcNew()(5) << endl;
    cout << "С using: " << funcUsing()(5) << endl;
    


    return 0;
}