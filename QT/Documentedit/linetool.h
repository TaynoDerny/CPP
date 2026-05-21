#ifndef LINETOOL_H
#define LINETOOL_H

#include "tool.h"

class LineTool : public Tool {
public:
    Tool* Clone() override;
    QString GetName() const override;
};

#endif