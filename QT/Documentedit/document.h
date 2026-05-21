#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QString>

class Document {
public:
    virtual ~Document() {}
    virtual void Save(const QString& path) = 0;
    virtual void Open(const QString& path) = 0;
    virtual void Print() = 0;
    virtual void Close() = 0;
    QString GetTitle() const { return title; }
protected:
    QString title = "Без названия";
};
#endif