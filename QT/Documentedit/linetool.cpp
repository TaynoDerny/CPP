#include "linetool.h"

Tool* LineTool::Clone() { return new LineTool(); }
QString LineTool::GetName() const { return "Линия"; }