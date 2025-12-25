#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Задание 1: Реверс строки (вариант с алгоритмом)
string reverseWithAlgorithm(const string& str) {
    string result = str;
    reverse(result.begin(), result.end());
    return result;
}

// Задание 1: Реверс строки (вариант с циклом)
string reverseWithLoop(const string& str) {
    string result;
    for (int i = str.length() - 1; i >= 0; --i) {
        result += str[i];
    }
    return result;
}

// Задание 2: Подсчет символов
void countCharacters(const string& str, int& letters, int& digits, int& spaces, int& others) {
    letters = digits = spaces = others = 0;
    
    for (char c : str) {
        if (isalpha(c)) {
            letters++;
        } else if (isdigit(c)) {
            digits++;
        } else if (isspace(c)) {
            spaces++;
        } else {
            others++;
        }
    }
}

// Задание 3: Удаление дубликатов
string removeDuplicates(const string& str) {
    string result;
    bool seen[256] = {false};
    
    for (char c : str) {
        if (!seen[static_cast<unsigned char>(c)]) {
            result += c;
            seen[static_cast<unsigned char>(c)] = true;
        }
    }
    
    return result;
}

// Задание 4: Проверка префикса
bool startsWith(const string& str, const string& prefix) {
    if (prefix.length() > str.length()) {
        return false;
    }
    
    for (size_t i = 0; i < prefix.length(); ++i) {
        if (str[i] != prefix[i]) {
            return false;
        }
    }
    
    return true;
}

// Задание 4: Проверка суффикса
bool endsWith(const string& str, const string& suffix) {
    if (suffix.length() > str.length()) {
        return false;
    }
    
    size_t start = str.length() - suffix.length();
    for (size_t i = 0; i < suffix.length(); ++i) {
        if (str[start + i] != suffix[i]) {
            return false;
        }
    }
    
    return true;
}

// Задание 5: Форматирование имени
string formatName(const string& fullName) {
    string result;
    string word;
    int wordCount = 0;
    string surname;
    
    for (size_t i = 0; i <= fullName.length(); ++i) {
        if (i == fullName.length() || fullName[i] == ' ') {
            if (!word.empty()) {
                if (wordCount == 0) {
                    surname = word;
                    result = surname;
                } else {
                    if (wordCount == 1) {
                        result += " ";
                    }
                    result += word[0];
                    result += ".";
                }
                wordCount++;
                word.clear();
            }
        } else {
            word += fullName[i];
        }
    }
    
    return result;
}

// Задание 6: Форматирование телефонного номера
string formatPhoneNumber(const string& phone) {
    string digits;
    
    // Удаление всех нецифровых символов
    for (char c : phone) {
        if (isdigit(c)) {
            digits += c;
        }
    }
    
    // Проверка длины номера
    if (digits.length() != 10 && digits.length() != 11) {
        return digits; // Возвращение исходной строки для городских номеров
    }
    
    // Обработка 11-значных номеров с первой цифрой 7 или 8
    if (digits.length() == 11 && (digits[0] == '7' || digits[0] == '8')) {
        string mobile = digits.substr(1);
        return "+7 (" + mobile.substr(0, 3) + ") " + 
               mobile.substr(3, 3) + "-" + 
               mobile.substr(6, 2) + "-" + 
               mobile.substr(8, 2);
    }
    // Обработка 10-значных номеров
    else if (digits.length() == 10) {
        return "+7 (" + digits.substr(0, 3) + ") " + 
               digits.substr(3, 3) + "-" + 
               digits.substr(6, 2) + "-" + 
               digits.substr(8, 2);
    }
    
    return digits;
}

// Задание 7: Очистка слова от знаков препинания
string cleanWord(const string& word) {
    string result;
    for (char c : word) {
        if (!ispunct(c)) {
            result += tolower(c);
        }
    }
    return result;
}

// Задание 7: Текстовый анализатор
void analyzeText(const string& text) {
    // Массив для хранения слов
    string words[100];
    int wordCount = 0;
    
    // Массив для хранения уникальных слов и их частот
    string uniqueWords[100];
    int frequencies[100] = {0};
    int uniqueCount = 0;
    
    string currentWord;
    
    // Разбивка текста на слова
    for (size_t i = 0; i <= text.length(); ++i) {
        if (i == text.length() || text[i] == ' ' || text[i] == '.' || text[i] == ',') {
            string cleaned = cleanWord(currentWord);
            if (!cleaned.empty()) {
                words[wordCount] = cleaned;
                wordCount++;
                
                // Поиск слова в массиве уникальных слов
                bool found = false;
                for (int j = 0; j < uniqueCount; j++) {
                    if (uniqueWords[j] == cleaned) {
                        frequencies[j]++;
                        found = true;
                        break;
                    }
                }
                
                // Добавление нового слова в массив уникальных
                if (!found) {
                    uniqueWords[uniqueCount] = cleaned;
                    frequencies[uniqueCount] = 1;
                    uniqueCount++;
                }
                
                currentWord.clear();
            }
        } else {
            currentWord += text[i];
        }
    }
    
    if (wordCount == 0) {
        cout << "Текст не содержит слов." << endl;
        return;
    }
    
    // Поиск самого длинного и самого короткого слова
    string longestWord = words[0];
    string shortestWord = words[0];
    
    for (int i = 1; i < wordCount; i++) {
        if (words[i].length() > longestWord.length()) {
            longestWord = words[i];
        }
        if (words[i].length() < shortestWord.length()) {
            shortestWord = words[i];
        }
    }
    
    // Поиск самого частого слова
    string mostFrequentWord = uniqueWords[0];
    int maxFrequency = frequencies[0];
    
    for (int i = 1; i < uniqueCount; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            mostFrequentWord = uniqueWords[i];
        }
    }
    
    // Сортировка уникальных слов по алфавиту (пузырьковая сортировка)
    for (int i = 0; i < uniqueCount - 1; i++) {
        for (int j = 0; j < uniqueCount - i - 1; j++) {
            if (uniqueWords[j] > uniqueWords[j + 1]) {
                string tempWord = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j + 1];
                uniqueWords[j + 1] = tempWord;
                
                int tempFreq = frequencies[j];
                frequencies[j] = frequencies[j + 1];
                frequencies[j + 1] = tempFreq;
            }
        }
    }
    
    // Вывод результатов анализа
    cout << "Всего слов: " << wordCount << endl;
    cout << "Уникальных слов: " << uniqueCount << endl;
    cout << "Самое длинное слово: \"" << longestWord << "\" (" << longestWord.length() << " букв)" << endl;
    cout << "Самое короткое слово: \"" << shortestWord << "\" (" << shortestWord.length() << " букв)" << endl;
    cout << "Самое частое слово: \"" << mostFrequentWord << "\" (" << maxFrequency << " раза)" << endl;
    
    // Вывод уникальных слов в алфавитном порядке
    cout << "\nУникальные слова в алфавитном порядке:" << endl;
    for (int i = 0; i < uniqueCount; i++) {
        cout << uniqueWords[i] << " ";
    }
    cout << endl;
}

int main() {
    string input;
    
    // заданиe 1
    cout << "Введите строку для реверса: ";
    getline(cin, input);
    cout << "С использованием алгоритма: " << reverseWithAlgorithm(input) << endl;
    cout << "С использованием цикла: " << reverseWithLoop(input) << endl;
    
    // заданиe 2
    cout << "Введите строку для подсчета символов: ";
    getline(cin, input);
    int letters, digits, spaces, others;
    countCharacters(input, letters, digits, spaces, others);
    cout << "букв: " << letters << ", цифр: " << digits << ", пробелов: " << spaces << ", другие: " << others << endl;

    // заданиe 3
    cout << "Введите строку для удаления дубликатов: ";
    getline(cin, input);
    cout << "Результат: " << removeDuplicates(input) << endl;
    
    // заданиe 4
    cout << "Введите имя файла: ";
    getline(cin, input);
    string filename = input;
    
    cout << "Введите префикс для проверки: ";
    getline(cin, input);
    cout << "startswith(\"" << input << "\"): " << boolalpha << startsWith(filename, input) << endl;
    
    cout << "Введите суффикс для проверки: ";
    getline(cin, input);
    cout << "endsWith(\"" << input << "\"): " << boolalpha << endsWith(filename, input) << endl;

    // заданиe 5
    cout << "Введите полное имя: ";
    getline(cin, input);
    string name = input;
    cout << "Форматированное имя: " << formatName(name) << endl;

    // заданиe 6
    cout << "Введите телефонный номер: ";
    getline(cin, input);
    cout << formatPhoneNumber(input) << endl;

    // заданиe 7
    cout << "Введите текст для анализа: ";
    getline(cin, input);
    string text = input;
    
    analyzeText(text);

    return 0;
}