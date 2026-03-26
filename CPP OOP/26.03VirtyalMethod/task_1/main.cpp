#include <iostream>
#include <vector>
#include "Animal.cpp"
#include "Cat.cpp"
#include "Dog.cpp"
#include "Horse.cpp"
#include "Cow.cpp"


using namespace std;

int main(){
    vector<Animal*> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());




    for (Animal* animal : animals){
        animal->speak();
    }

    for (Animal* animal : animals){
        delete animal;
    }

    return 0;
}