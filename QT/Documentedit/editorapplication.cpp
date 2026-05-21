#include "editorapplication.h"
#include <QDebug>

EditorApplication::~EditorApplication() {}

void EditorApplication::NewDocument() {
    Document* doc = CreateDocument();
    qDebug() << "Создан документ:" << doc->GetTitle();
    delete doc;
}