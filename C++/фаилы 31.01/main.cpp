#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// Функция заданиe 1
int countWordsStartingWith(const char* filename, char startChar) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }
    
    int count = 0;
    bool inWord = false;
    bool wordStart = false;
    int c;
    
    while ((c = fgetc(file)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9') || (c >= 'А' && c <= 'я')) {
            if (!inWord) {
                inWord = true;
                wordStart = true;
                if (c == startChar) {
                    count++;
                }
            } else if (wordStart) {
                wordStart = false;
            }
        } else {
            inWord = false;
            wordStart = false;
        }
    }
    
    fclose(file);
    return count;
}

// заданиe 2
void replaceZeroOne(const char* inputFile, const char* outputFile) {
    FILE* inFile = fopen(inputFile, "r");
    FILE* outFile = fopen(outputFile, "w");
    
    if (!inFile || !outFile) {
        cout << "Ошибка открытия файлов!" << endl;
        if (inFile) fclose(inFile);
        if (outFile) fclose(outFile);
        return;
    }
    
    int c;
    while ((c = fgetc(inFile)) != EOF) {
        if (c == '0') fputc('1', outFile);
        else if (c == '1') fputc('0', outFile);
        else fputc(c, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
    
    cout << "Замена выполнена успешно!" << endl;
    cout << "Результат записан в файл: " << outputFile << endl;
}

// заданиe 4
long long countCharacters(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }
    
    fseek(file, 0, SEEK_END);
    long long size = ftell(file);
    fclose(file);
    return size;
}

// заданиe 5
int countLines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }
    
    int lineCount = 0;
    int c;
    int lastChar = '\n';
    
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') lineCount++;
        lastChar = c;
    }
    
    if (lastChar != '\n' && lastChar != EOF) lineCount++;
    
    fclose(file);
    return lineCount;
}

// Главное меню
void showMenu() {
    cout << "\n=== МЕНЮ ВЫБОРА ЗАДАНИЯ ===" << endl;
    cout << "1. Подсчет слов, начинающихся с заданного символа" << endl;
    cout << "2. Замена 0 на 1 и 1 на 0 в файле" << endl;
    cout << "3. Запись массива строк в файл" << endl;
    cout << "4. Подсчет количества символов в файле" << endl;
    cout << "5. Подсчет количества строк в файле" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите задание: ";
}

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1: {
                char filename[256];
                char searchChar;
                
                cout << "Введите имя файла: ";
                cin.getline(filename, 256);
                cout << "Введите символ для поиска: ";
                cin >> searchChar;
                
                int result = countWordsStartingWith(filename, searchChar);
                if (result >= 0) {
                    cout << "Результат: " << result << " слов" << endl;
                }
                break;
            }
            
            case 2: {
                char inputFile[256], outputFile[256];
                
                cout << "Введите имя исходного файла: ";
                cin.getline(inputFile, 256);
                cout << "Введите имя выходного файла: ";
                cin.getline(outputFile, 256);
                
                replaceZeroOne(inputFile, outputFile);
                break;
            }
            
            case 3: {
                int n;
                cout << "Введите количество строк: ";
                cin >> n;
                cin.ignore();
                
                char filename[256];
                cout << "Введите имя файла для записи: ";
                cin.getline(filename, 256);
                
                FILE* file = fopen(filename, "w");
                if (!file) {
                    cout << "Ошибка открытия файла!" << endl;
                    break;
                }
                
                cout << "Введите строки:" << endl;
                for (int i = 0; i < n; i++) {
                    string str;
                    cout << "Строка " << (i + 1) << ": ";
                    getline(cin, str);
                    fprintf(file, "%s\n", str.c_str());
                }
                
                fclose(file);
                cout << "Массив записан в файл!" << endl;
                break;
            }
            
            case 4: {
                char filename[256];
                cout << "Введите имя файла: ";
                cin.getline(filename, 256);
                
                long long chars = countCharacters(filename);
                if (chars >= 0) {
                    cout << "Количество символов: " << chars << endl;
                }
                break;
            }
            
            case 5: {
                char filename[256];
                cout << "Введите имя файла: ";
                cin.getline(filename, 256);
                
                int lines = countLines(filename);
                if (lines >= 0) {
                    cout << "Количество строк: " << lines << endl;
                }
                break;
            }
            
            case 0:
                cout << "Выход из программы..." << endl;
                break;
                
            default:
                cout << "Неверный выбор!" << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}