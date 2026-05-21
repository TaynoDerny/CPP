#ifndef EDITORAPPLICATION_H
#define EDITORAPPLICATION_H

#include "document.h"
#include <QString>

class EditorApplication {
public:
    EditorApplication();
    virtual ~EditorApplication();

    // Фабричный метод — вот он, ключевой!
    virtual Document* CreateDocument() = 0;

    void NewDocument();
    void OpenDocument(const QString& filePath);
};

#endif