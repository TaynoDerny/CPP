#include "student.h"
#include <cmath>

using namespace std;

// ========== Student ====
Student::Student() : name(""), gradeCount(0) {}

Student::Student(string n) : name(n), gradeCount(0) {}

string Student::getName() const {
    return name;
}

void Student::addGrade(int grade) {
    if (gradeCount < MAX_SUBJECTS) {
        grades[gradeCount] = grade;
        gradeCount++;
    }
}

int Student::getGrade(int index) const {
    if (index >= 0 && index < gradeCount) {
        return grades[index];
    }
    return 0;
}

int Student::getGradeCount() const {
    return gradeCount;
}

// Средняя оценка студента
double Student::getAverageGrade() const {
    if (gradeCount == 0) return 0;
    
    double sum = 0;
    for (int i = 0; i < gradeCount; i++) {
        sum += grades[i];
    }
    return sum / gradeCount;
}

// ======= Subject ========
Subject::Subject() : name("") {}

Subject::Subject(string n) : name(n) {}

string Subject::getName() const {
    return name;
}

// === Group ==========
Group::Group() : name(""), studentCount(0), subjectCount(0) {}

Group::Group(string n) : name(n), studentCount(0), subjectCount(0) {}

string Group::getName() const {
    return name;
}

void Group::addStudent(const Student& s) {
    if (studentCount < MAX_STUDENTS) {
        students[studentCount] = s;
        studentCount++;
    }
}

void Group::addSubject(const Subject& subj) {
    if (subjectCount < MAX_SUBJECTS) {
        subjects[subjectCount] = subj;
        subjectCount++;
    }
}

void Group::setStudent(int index, const Student& s) {
    if (index >= 0 && index < studentCount) {
        students[index] = s;
    }
}

Student Group::getStudent(int index) const {
    if (index >= 0 && index < studentCount) {
        return students[index];
    }
    return Student();
}

Subject Group::getSubject(int index) const {
    if (index >= 0 && index < subjectCount) {
        return subjects[index];
    }
    return Subject();
}

int Group::getStudentCount() const {
    return studentCount;
}

int Group::getSubjectCount() const {
    return subjectCount;
}

// Средний балл группы
double Group::getGroupAverage() const {
    if (studentCount == 0) return 0;
    
    double sum = 0;
    for (int i = 0; i < studentCount; i++) {
        sum += students[i].getAverageGrade();
    }
    return sum / studentCount;
}

// Средняя оценка по предмету
double Group::getSubjectAverage(int subjectIndex) const {
    if (studentCount == 0) return 0;
    
    double sum = 0;
    int count = 0;
    
    for (int i = 0; i < studentCount; i++) {
        if (subjectIndex < students[i].getGradeCount()) {
            sum += students[i].getGrade(subjectIndex);
            count++;
        }
    }
    
    return (count > 0) ? sum / count : 0;
}

// Максимальная оценка по предмету
int Group::getMaxGrade(int subjectIndex, string& studentName) const {
    int maxGrade = -1;
    studentName = "";
    
    for (int i = 0; i < studentCount; i++) {
        if (subjectIndex < students[i].getGradeCount()) {
            int grade = students[i].getGrade(subjectIndex);
            if (grade > maxGrade) {
                maxGrade = grade;
                studentName = students[i].getName();
            }
        }
    }
    
    return maxGrade;
}

// Минимальная оценка по предмету
int Group::getMinGrade(int subjectIndex, string& studentName) const {
    int minGrade = 101; // Больше максимальной оценки
    studentName = "";
    
    for (int i = 0; i < studentCount; i++) {
        if (subjectIndex < students[i].getGradeCount()) {
            int grade = students[i].getGrade(subjectIndex);
            if (grade < minGrade) {
                minGrade = grade;
                studentName = students[i].getName();
            }
        }
    }
    
    return minGrade;
}