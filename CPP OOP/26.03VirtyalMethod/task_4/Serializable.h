#pragma once
#include <string>
using namespace std;

class Serializable {
public:
    virtual ~Serializable() = default;
    virtual string serialize() const = 0;
};
