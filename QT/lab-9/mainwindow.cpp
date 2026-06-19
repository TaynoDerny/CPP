#include "mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создаем центральный виджет и вертикальный слой для него
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    setCentralWidget(centralWidget);

    // Создаем виджеты
    btnOpen = new QPushButton("Открыть файл", this);
    textEdit = new QTextEdit(this);
    lblInfo = new QLabel("Файл не выбран", this);

    // Добавляем их в слой
    layout->addWidget(btnOpen);
    layout->addWidget(textEdit);
    layout->addWidget(lblInfo);

    // ВРУЧНУЮ связываем кнопку со слотом
    connect(btnOpen, &QPushButton::clicked, this, &MainWindow::onOpenFile);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onOpenFile()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите текстовый файл",
                                                    "",
                                                    "Текстовые файлы (*.txt);;Все файлы (*)");
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QTextStream in(&file);
    textEdit->setPlainText(in.readAll());
    file.close();

    QFileInfo fileInfo(filePath);
    QString creationDate = fileInfo.birthTime().toString("dd.MM.yyyy HH:mm:ss");
    if (creationDate.isEmpty()) {
        creationDate = fileInfo.lastModified().toString("dd.MM.yyyy HH:mm:ss");
    }

    QString attrs;
    if (fileInfo.isReadable()) attrs += "Чтение; ";
    if (fileInfo.isWritable()) attrs += "Запись; ";
    if (fileInfo.isHidden()) attrs += "Скрытый; ";
    if (attrs.isEmpty()) attrs = "Обычный файл";

    lblInfo->setText(QString("Имя: %1\nДата создания: %2\nАтрибуты: %3")
                         .arg(fileInfo.fileName(), creationDate, attrs));
}