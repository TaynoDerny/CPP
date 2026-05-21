#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "editorapplication.h"

class TextEditor : public EditorApplication {
public:
    Document* CreateDocument() override;
};

#endif