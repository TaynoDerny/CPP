#include "DataHolder.h"

DataHolder::DataHolder() {
    for (int i = 0; i < 5; i++)
        data[i] = i + 1; // {1, 2, 3, 4, 5}
}

const int* DataHolder::getData() const {
    return data;
}

void DataHolder::print() const {
    for (int i = 0; i < 5; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}
