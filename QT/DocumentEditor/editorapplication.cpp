#include "editorapplication.h"
#include <QDebug>

EditorApplication::EditorApplication() {}
EditorApplication::~EditorApplication() {}

void EditorApplication::NewDocument() {
    Document* doc = CreateDocument();  // вызывает фабричный метод
    doc->SetTitle("Новый документ");
    qDebug() << "Создан документ:" << doc->GetTitle();
}

void EditorApplication::OpenDocument(const QString& filePath) {
    Document* doc = CreateDocument();  // вызывает фабричный метод
    doc->Open(filePath);
    qDebug() << "Открыт документ:" << doc->GetTitle();
}