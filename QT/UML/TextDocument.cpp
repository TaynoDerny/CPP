#include "TextDocument.h"
#include <QFile>
#include <QTextStream>

TextDocument::TextDocument(QWidget *parent) : Document(parent) {
    textEdit = new QTextEdit(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);
    layout->setContentsMargins(0, 0, 0, 0); // убираем отступы
    setLayout(layout);
}

bool TextDocument::openFile(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    textEdit->setPlainText(QString::fromUtf8(file.readAll()));
    filePath = path;
    setWindowTitle(path);
    return true;
}

bool TextDocument::saveFile(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    QTextStream out(&file);
    out << textEdit->toPlainText();
    filePath = path;
    setWindowTitle(path);
    return true;
}