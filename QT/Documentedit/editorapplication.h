#ifndef EDITORAPPLICATION_H
#define EDITORAPPLICATION_H
#include <QList>
#include "Document.h"

class EditorApplication {
public:
    virtual ~EditorApplication() {
        for (auto doc : documents) delete doc;
    }

    // Фабричный метод — паттерн Factory Method
    virtual Document* CreateDocument() = 0;

    void NewDocument() {
        documents.append(CreateDocument());
    }

    void OpenDocument(const QString& path) {
        Document* doc = CreateDocument();
        doc->Open(path);
        documents.append(doc);
    }

    void SaveDocument(int index, const QString& path) {
        if (index < documents.size())
            documents[index]->Save(path);
    }

    void PrintDocument(int index) {
        if (index < documents.size())
            documents[index]->Print();
    }

    void CloseDocument(int index) {
        if (index < documents.size()) {
            documents[index]->Close();
            delete documents[index];
            documents.removeAt(index);
        }
    }

protected:
    QList<Document*> documents;
};
#endif