#include "Student.h"

void Student::SetSurname(string Surname){
surname = Surname;
    
}
void Student::SetName(string Name){
name = Name;

}
void Student::SetPatronymic(string Patronymic){
patronymic = Patronymic;

}
void Student::SetBirthday(string Birthday){
birthday = Birthday;
    
}
void Student::SetPhone_number(string Phone_number){
phone_number = Phone_number;
    
}
void Student::SetCity(string City){
city = City;
    
}
void Student::SetCountry(string Country){
country = Country;
    
}
void Student::SetName_college(string Name_college){
name_college = Name_college;
    
}
void Student::SetCity_college(string City_college){
city_college = City_college;
    
}
void Student::SetNumber_group(string Number_group){
number_group = Number_group;
    
}




string Student::GetSurname(){
return surname;
}
string Student::GetName(){
return name;
}
string Student::GetPatronymic(){
return patronymic;
}
string Student::GetBirthday(){
return birthday;
}
string Student::GetPhone_number(){
return phone_number;
}
string Student::GetCity(){
return city;
}
string Student::GetCountry(){
return country;
}
string Student::GetName_college(){
return name_college;
}
string Student::GetCity_college(){
return city_college;
}
string Student::GetNumber_group(){
return number_group;
}

void Student::PrintStudent() {
    cout << "ФИО: " << surname << " " << name << " " << patronymic << endl;
    cout << "Дата рождения: " << birthday << endl;
    cout << "Телефон: " << phone_number << endl;
    cout << "Город: " << city<< endl;
    cout << "Страна: " << country<< endl;
    cout << "Колледж: " << name_college<< endl;
    cout << "Город колледжа: " << city_college<< endl;
    cout << "Номер группы: " << number_group << endl;
}