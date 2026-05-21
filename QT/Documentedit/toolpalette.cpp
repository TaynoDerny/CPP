#include "toolpalette.h"

ToolPalette::ToolPalette() {}
ToolPalette::~ToolPalette() {
    for (auto t : prototypes) delete t;
}

void ToolPalette::RegisterTool(const QString& name, Tool* prototype) {
    prototypes[name] = prototype;
}

Tool* ToolPalette::GetTool(const QString& name) {
    if (prototypes.contains(name))
        return prototypes[name]->Clone();
    return nullptr;
}