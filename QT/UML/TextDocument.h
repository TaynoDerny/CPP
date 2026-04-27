#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H

#include "Document.h"
#include <QTextEdit>
#include <QVBoxLayout>

class TextDocument : public Document {
    Q_OBJECT
public:
    explicit TextDocument(QWidget *parent = nullptr);
    bool openFile(const QString &path) override;
    bool saveFile(const QString &path) override;
    QString currentFilePath() const override { return filePath; }

    QTextEdit* getTextEdit() { return textEdit; } // Для копирования

private:
    QTextEdit *textEdit;
    QString filePath;
};

#endif // TEXTDOCUMENT_H