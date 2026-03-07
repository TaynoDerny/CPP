#include "Worker.h"
#include <iostream>
using namespace std;

Worker::Worker(string last_name, string first_name, string patronymic)
    : last_name(last_name), first_name(first_name), patronymic(patronymic),
      job_title("Не известно"), year_of_work(0), salary(0) {}

Worker::Worker(string last_name, string first_name, string patronymic,
               string job_title, int year_of_work, int salary)
    : last_name(last_name), first_name(first_name), patronymic(patronymic),
      job_title(job_title), year_of_work(year_of_work), salary(salary) {}

// explicit конструктор – только должность, остальное по умолчанию
Worker::Worker(string job_title)
    : last_name(""), first_name(""), patronymic(""),
      job_title(job_title), year_of_work(0), salary(0) {}

void Worker::setLast_name(string last_name) { this->last_name = last_name; }
void Worker::setFirst_name(string first_name) { this->first_name = first_name; }
void Worker::setPatronymic(string patronymic) { this->patronymic = patronymic; }
void Worker::setJob_title(string job_title) { this->job_title = job_title; }
void Worker::setYear_of_work(int year_of_work) { this->year_of_work = year_of_work; }
void Worker::setSalary(int salary) { this->salary = salary; }

string Worker::getLast_name() const { return last_name; }
string Worker::getFirst_name() const { return first_name; }
string Worker::getPatronymic() const { return patronymic; }
string Worker::getJob_title() const { return job_title; }
int Worker::getYear_of_work() const { return year_of_work; }
int Worker::getSalary() const { return salary; }  

