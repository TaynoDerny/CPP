#pragma once
#include <string>

using namespace std;

const int MAX_STUDENTS = 30;   // Максимум студентов в группе
const int MAX_SUBJECTS = 20;   // Максимум предметов

// КЛАСС Student 
class Student {
private:
    string name;                // Имя студента
    int grades[MAX_SUBJECTS];    // Оценки по предметам
    int gradeCount;              // Количество оценок

public:
    Student();
    Student(string n);
    
    string getName() const;
    void addGrade(int grade);
    int getGrade(int index) const;
    int getGradeCount() const;
    
    // Средняя оценка студента
    double getAverageGrade() const;
};

// КЛАСС Subject (Предмет)
class Subject {
private:
    string name;                // Название предмета

public:
    Subject();
    Subject(string n);
    
    string getName() const;
};

// КЛАСС Group (Группа)
class Group {
private:
    string name;                                 // Название группы
    Student students[MAX_STUDENTS];               // Массив студентов
    Subject subjects[MAX_SUBJECTS];               // Массив предметов
    int studentCount;                              // Количество студентов
    int subjectCount;                              // Количество предметов

public:
    Group();
    Group(string n);
    
    string getName() const;
    
    void addStudent(const Student& s);
    void addSubject(const Subject& subj);
    void setStudent(int index, const Student& s);  //метод для обновления студента
    
    Student getStudent(int index) const;
    Subject getSubject(int index) const;
    int getStudentCount() const;
    int getSubjectCount() const;
    
    // Средний балл группы
    double getGroupAverage() const;
    
    // Средние оценки по предметам
    double getSubjectAverage(int subjectIndex) const;
    
    // Максимальная оценка по предмету
    int getMaxGrade(int subjectIndex, string& studentName) const;
    
    // Минимальная оценка по предмету
    int getMinGrade(int subjectIndex, string& studentName) const;
};

