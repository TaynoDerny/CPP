#ifndef TOOL_H
#define TOOL_H

#include <QString>

class Tool {
public:
    virtual ~Tool();
    virtual Tool* Clone() = 0;
    virtual QString GetName() const = 0;
};

#endif