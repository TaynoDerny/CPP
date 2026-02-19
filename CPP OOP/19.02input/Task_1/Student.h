#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student{
    string surname;
    string name;
    string patronymic;

    string birthday;
    string phone_number;
    string city;
    string country;
    string name_college;
    string city_college;
    string number_group;

public:


    void SetSurname(string Surname);
    void SetName(string Name);
    void SetPatronymic(string Patronymic);
    void SetBirthday(string Birthday);
    void SetPhone_number(string Phone_number);
    void SetCity(string City);
    void SetCountry(string Country);
    void SetName_college(string Name_college);
    void SetCity_college(string City_college);
    void SetNumber_group(string Number_group);




    string GetSurname();
    string GetName();
    string GetPatronymic();

    string GetBirthday();
    string GetPhone_number();
    string GetCity();
    string GetCountry();
    string GetName_college();
    string GetCity_college();
    string GetNumber_group();
    void PrintStudent();


};

