#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include "student.cpp"

using namespace std;

// Функция для вывода чисел
void printDouble(double value) {
    int intPart = static_cast<int>(value);
    int fracPart = static_cast<int>((value - intPart) * 100 + 0.5);
    
    cout << intPart << ".";
    if (fracPart < 10) {
        cout << "0";
    }
    cout << fracPart;
}

// Чтение списка студентов из файла
int readStudentsFromFile(const string& filename, Student students[], int maxStudents) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return 0;
    }
    
    int count = 0;
    string name;
    
    while (getline(file, name) && count < maxStudents) {
        if (!name.empty()) {
            students[count] = Student(name);
            count++;
        }
    }
    
    file.close();
    cout << "Прочитано студентов: " << count << endl;
    return count;
}

// Чтение списка предметов из файла
int readSubjectsFromFile(const string& filename, Subject subjects[], int maxSubjects) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return 0;
    }
    
    int count = 0;
    string name;
    
    while (getline(file, name) && count < maxSubjects) {
        if (!name.empty()) {
            subjects[count] = Subject(name);
            count++;
        }
    }
    
    file.close();
    cout << "Прочитано предметов: " << count << endl;
    return count;
}

// Чтение таблицы оценок из файла
void loadGrades(Group& group, const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return;
    }
    
    int studentCount = group.getStudentCount();
    int subjectCount = group.getSubjectCount();
    
    // Для каждого студента читаем оценки и добавляем их
    for (int i = 0; i < studentCount; i++) {
        Student currentStudent = group.getStudent(i);
        
        for (int j = 0; j < subjectCount; j++) {
            int grade;
            file >> grade;
            currentStudent.addGrade(grade);
        }
        
        // Обновляем студента в группе
        group.setStudent(i, currentStudent);
    }
    
    file.close();
    cout << "Оценки загружены" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    string studentsFile, subjectsFile, gradesFile;
    string groupName;
    
    cout << "=== ПРОГРАММА 'ГРУППА СТУДЕНТОВ' ===" << endl;
    cout << endl;
    
    // Ввод названия группы
    cout << "Введите название группы: ";
    getline(cin, groupName);
    
    // Ввод имен файлов
    cout << "Введите имя файла со списком студентов: ";
    getline(cin, studentsFile);
    
    cout << "Введите имя файла со списком предметов: ";
    getline(cin, subjectsFile);
    
    cout << "Введите имя файла с таблицей оценок: ";
    getline(cin, gradesFile);
    
    cout << endl;
    
    // Создаем группу
    Group group(groupName);
    
    // Читаем студентов
    Student students[MAX_STUDENTS];
    int studentCount = readStudentsFromFile(studentsFile, students, MAX_STUDENTS);
    for (int i = 0; i < studentCount; i++) {
        group.addStudent(students[i]);
    }
    
    // Читаем предметы
    Subject subjects[MAX_SUBJECTS];
    int subjectCount = readSubjectsFromFile(subjectsFile, subjects, MAX_SUBJECTS);
    for (int i = 0; i < subjectCount; i++) {
        group.addSubject(subjects[i]);
    }
    
    // Читаем оценки
    loadGrades(group, gradesFile);
    
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "Группа: " << group.getName() << endl;
    cout << endl;
    
  
    cout << "ТАБЛИЦА ОЦЕНОК:" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    // Шапка таблицы
    cout << "Студент";
    for (int i = 0; i < 20; i++) cout << " ";
    
    for (int j = 0; j < group.getSubjectCount(); j++) {
        string subjName = group.getSubject(j).getName();
        cout << " | ";
        if (subjName.length() > 8) {
            cout << subjName.substr(0, 8);
        } else {
            cout << subjName;
            for (size_t k = subjName.length(); k < 8; k++) cout << " ";
        }
    }
    cout << " | Средняя" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    // Строки студентов
    for (int i = 0; i < group.getStudentCount(); i++) {
        Student s = group.getStudent(i);
        
        // Вывод имени с выравниванием
        cout << s.getName();
        for (int k = s.getName().length(); k < 24; k++) cout << " ";
        
        // Вывод оценок
        for (int j = 0; j < group.getSubjectCount(); j++) {
            if (j < s.getGradeCount()) {
                cout << " |    " << s.getGrade(j) << "    ";
            } else {
                cout << " |    -    ";
            }
        }
        
        // Вывод средней оценки
        cout << " |  ";
        printDouble(s.getAverageGrade());
        cout << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
    

    cout << "СРЕДНИЕ ОЦЕНКИ ПО ПРЕДМЕТАМ:" << endl;
    for (int j = 0; j < group.getSubjectCount(); j++) {
        cout << group.getSubject(j).getName() << ": ";
        printDouble(group.getSubjectAverage(j));
        cout << endl;
    }
    cout << endl;
    

    cout << "СРЕДНИЙ БАЛЛ ГРУППЫ: ";
    printDouble(group.getGroupAverage());
    cout << endl;
    cout << endl;
    

    cout << "МАКСИМАЛЬНЫЕ И МИНИМАЛЬНЫЕ ОЦЕНКИ ПО ПРЕДМЕТАМ:" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    for (int j = 0; j < group.getSubjectCount(); j++) {
        string maxStudent, minStudent;
        int maxGrade = group.getMaxGrade(j, maxStudent);
        int minGrade = group.getMinGrade(j, minStudent);
        
        cout << group.getSubject(j).getName() << ":" << endl;
        cout << "  Максимум: " << maxGrade << " (" << maxStudent << ")" << endl;
        cout << "  Минимум: " << minGrade << " (" << minStudent << ")" << endl;
        cout << endl;
    }
    
    return 0;
}