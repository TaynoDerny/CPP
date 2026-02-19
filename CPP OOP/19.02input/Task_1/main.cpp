#include <iostream>
#include "Student.cpp"
using namespace std;
int main() {
    setlocale(LC_ALL, "Ru"); 
    
    
    Student student1;
    

    student1.SetSurname("Иванов");
    student1.SetName("Иван");
    student1.SetPatronymic("Иванович");
    student1.SetBirthday("15.05.2000");
    student1.SetPhone_number("+7 (999) 123-45-67");
    student1.SetCity("Москва");
    student1.SetCountry("Россия");
    student1.SetName_college("Московский политехнический колледж");
    student1.SetCity_college("Москва");
    student1.SetNumber_group("ИТ-201");
    

    Student student2;
    

    student2.SetSurname("Петрова");
    student2.SetName("Анна");
    student2.SetPatronymic("Сергеевна");
    student2.SetBirthday("23.11.2001");
    student2.SetPhone_number("+7 (999) 987-65-43");
    student2.SetCity("Санкт-Петербург");
    student2.SetCountry("Россия");
    student2.SetName_college("Санкт-Петербургский технический колледж");
    student2.SetCity_college("Санкт-Петербург");
    student2.SetNumber_group("ПР-202");

    cout<<"===№1 Студент==="<<endl;
    student1.PrintStudent();
    cout<<"===№2 Студент==="<<endl;
    student2.PrintStudent();
    
    

    
    return 0;
}