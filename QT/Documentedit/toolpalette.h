#ifndef TOOLPALETTE_H
#define TOOLPALETTE_H

#include "tool.h"
#include <QMap>
#include <QString>

class ToolPalette {
public:
    ToolPalette();
    ~ToolPalette();
    void RegisterTool(const QString& name, Tool* prototype);
    Tool* GetTool(const QString& name);

private:
    QMap<QString, Tool*> prototypes;
};

#endif