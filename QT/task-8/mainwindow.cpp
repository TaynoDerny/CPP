#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFontDialog>
#include <QInputDialog>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextCharFormat>
#include <QDateTime>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Фиксируем размер окна
    this->setFixedSize(this->width(), this->height());

    // Файл
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onNewDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::onOpenDocument);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::onSaveDocument);
    connect(ui->actionPrint, &QAction::triggered, this, &MainWindow::onPrintDocument);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    // Правка стандартные
    connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);
    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);

    // Правка кастомные
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onDeleteText);
    connect(ui->actionInsertDate, &QAction::triggered, this, &MainWindow::onInsertDate);

    // Вид
    connect(ui->actionFont, &QAction::triggered, this, &MainWindow::onSelectFont);
    connect(ui->actionAlignLeft, &QAction::triggered, this, &MainWindow::onAlignLeft);
    connect(ui->actionAlignCenter, &QAction::triggered, this, &MainWindow::onAlignCenter);
    connect(ui->actionAlignRight, &QAction::triggered, this, &MainWindow::onAlignRight);

    // Найти
    connect(ui->actionFind, &QAction::triggered, this, &MainWindow::onFindWord);
    connect(ui->actionGoToLine, &QAction::triggered, this, &MainWindow::onGoToLine);
    connect(ui->actionReplace, &QAction::triggered, this, &MainWindow::onReplaceWord);

    // Справка
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAboutProgram);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Меню: Файл

void MainWindow::onNewDocument()
{
    ui->textEdit->clear();
}

void MainWindow::onOpenDocument()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filename = dialog.getOpenFileName(NULL, "Open file", "", "");

    if (filename.isEmpty()) return;

    QFile file(filename);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::onSaveDocument()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString filename = dialog.getSaveFileName(NULL, "Save file", "", "");

    if (filename.isEmpty()) return;

    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->toHtml();
        out.flush();
        file.close();
    }
}

void MainWindow::onPrintDocument()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() == QDialog::Accepted) {
        ui->textEdit->print(&printer);
    }
}

//  Меню: Правка

void MainWindow::onDeleteText()
{
    ui->textEdit->textCursor().removeSelectedText();
}

void MainWindow::onInsertDate()
{
    QString currentDate = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    ui->textEdit->insertPlainText(currentDate);
}

//  Меню: Вид

void MainWindow::onSelectFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        QTextCharFormat format;
        format.setFont(font);
        ui->textEdit->textCursor().setCharFormat(format);
    }
}

void MainWindow::onAlignLeft()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::onAlignCenter()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::onAlignRight()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

// Меню: Найти

void MainWindow::onGoToLine()
{
    bool ok;
    int num = QInputDialog::getInt(0, "Перейти", "На строку:", 1, 1,
                                   ui->textEdit->document()->lineCount(), 1, &ok);
    if (ok) {
        QTextBlock block = ui->textEdit->document()->findBlockByLineNumber(num - 1);
        QTextCursor cursor(block);
        ui->textEdit->setTextCursor(cursor);
    }
}

void MainWindow::onFindWord()
{
    bool bOk;
    QString str = QInputDialog::getText(0, "Найти", "Введите текст:", QLineEdit::Normal, "", &bOk);

    if (!bOk || str.isEmpty()) return;

    QTextCursor oldCursor = ui->textEdit->textCursor();
    ui->textEdit->setTextCursor(QTextCursor(ui->textEdit->document()->findBlockByLineNumber(0)));

    bool finded = ui->textEdit->find(str);
    if (!finded) {
        ui->textEdit->setTextCursor(oldCursor);
        QMessageBox::information(this, "Поиск", "Ничего не найдено");
    }
}

void MainWindow::onReplaceWord()
{
    bool bOk1, bOk2;
    QString searchStr = QInputDialog::getText(0, "Замена", "Что заменить:", QLineEdit::Normal, "", &bOk1);
    if (!bOk1 || searchStr.isEmpty()) return;

    QString replaceStr = QInputDialog::getText(0, "Замена", "На что заменить:", QLineEdit::Normal, "", &bOk2);
    if (!bOk2) return;

    ui->textEdit->setTextCursor(QTextCursor(ui->textEdit->document()->findBlockByLineNumber(0)));

    int count = 0;
    while (ui->textEdit->find(searchStr)) {
        ui->textEdit->textCursor().insertText(replaceStr);
        count++;
    }

    QMessageBox::information(this, "Замена", QString("Успешно заменено совпадений: %1").number(count));
}

//  Меню: Справка

void MainWindow::onAboutProgram()
{
    QMessageBox::about(this, "О программе", "Текстовый редактор\nЛабораторная работа №8\nВыполнил: Студент группы 1");
}
