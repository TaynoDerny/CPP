#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
    int z;
public:
    int GetX();
    int GetY();
    int GetZ();

    void SetX(int X);
    void SetY(int Y);
    void SetZ(int Z);

    void PrintPoint();
    
    bool SaveToFile(const string& filename);
    bool LoadFromFile(const string& filename);
};

