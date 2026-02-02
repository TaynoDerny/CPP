#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#include <filesystem> 
namespace fs = std::filesystem; 
using namespace std;


const int max_tasks = 100;

struct Date {
    string number;
    string month;
};

struct Time {
    string hour;
    string minutes;
};

struct Task {
    int id;
    string name;
    int priority;
    string description;
    Date date;
    Time time;
};


extern Task tasks[max_tasks];
extern int task_count;


long long calculate_minutes(string day_str, string month_str, string hour_str, string minutes_str);
void print_task(Task task);
void create_task();
void edit_task();
void find_task();
void delete_task();
void show_task_list();

void save_to_file();
void load_from_file();