#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include <QString>


class Document : public QWidget {
    Q_OBJECT
public:
    explicit Document(QWidget *parent = nullptr) : QWidget(parent) {}
    virtual ~Document() {}

    virtual bool openFile(const QString &path) = 0;
    virtual bool saveFile(const QString &path) = 0;
    virtual QString currentFilePath() const = 0;
};

#endif // DOCUMENT_H