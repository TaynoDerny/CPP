#include "Point.h"


int Point::GetX(){
    return x;
}
int Point::GetY(){
    return y;
}
   
int Point::GetZ(){
    return z;
}
   

void Point::SetX(int X){
    x = X;
}
void Point::SetY(int Y){
    y=Y;
}
void Point::SetZ(int Z){
    z=Z;
}
void Point::PrintPoint(){
    cout <<"Координаты точки: "<<endl;
    cout<<"X: "<<x<<endl;
    cout<<"Y: "<<y<<endl;
    cout<<"Z: "<<z<<endl;
}


bool Point::SaveToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return false;
    }
        
    file << x << " " << y << " " << z;
    file.close();
    cout << "Точка сохранена в файл " << filename << endl;
    return true;
}

bool Point::LoadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return false;
    }
        
    file >> x >> y >> z;
    file.close();
    cout << "Точка загружена из файла " << filename << endl;
    return true;
}