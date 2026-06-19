#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QRegularExpression>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *layout = new QVBoxLayout(central);

    textEdit = new QTextEdit(this);
    textEdit->setPlaceholderText("Введите текст с числами 1-9...");
    button = new QPushButton("Выполнить замену", this);

    layout->addWidget(textEdit);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::onReplaceButtonClicked);
}

void MainWindow::onReplaceButtonClicked()
{
    QString text = textEdit->toPlainText();
    QString result = text;

    QMap<QString, QString> numberMap;
    numberMap["1"] = "один";
    numberMap["2"] = "два";
    numberMap["3"] = "три";
    numberMap["4"] = "четыре";
    numberMap["5"] = "пять";
    numberMap["6"] = "шесть";
    numberMap["7"] = "семь";
    numberMap["8"] = "восемь";
    numberMap["9"] = "девять";

    QRegularExpression rx("\\b([1-9])\\b");
    QRegularExpressionMatchIterator it = rx.globalMatch(result);

    int offset = 0;
    while (it.hasNext())
    {
        QRegularExpressionMatch match = it.next();
        QString digit = match.captured(1);
        QString replacement = numberMap.value(digit);

        // 因为替换后的文字长度可能和数字不一样，所以要记录偏移量 offset
        int startPos = match.capturedStart(0) + offset;
        int length = match.capturedLength(0);

        result.replace(startPos, length, replacement);
        offset += replacement.length() - length;
    }

    textEdit->setPlainText(result);
}