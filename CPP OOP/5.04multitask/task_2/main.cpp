#include "DataHolder.h"

using namespace std;

void modifyData(const DataHolder& dh) {
    DataHolder& mutableDh = const_cast<DataHolder&>(dh);
    int* data = const_cast<int*>(mutableDh.getData());
    data[0] = 999;
}

int main() {
    DataHolder dh;

    cout << "До изменения: ";
    dh.print();

    modifyData(dh);

    cout << "После изменения: ";
    dh.print();

    return 0;
}
