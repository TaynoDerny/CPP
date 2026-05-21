#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include "linetool.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Инициализация редактора
    textEditor = new TextEditor();

    // Инициализация палитры
    palette = new ToolPalette();
    palette->RegisterTool("Линия", new LineTool());

    // Подключаем кнопки к слотам
    connect(ui->btnNewDoc, &QPushButton::clicked,
            this, &MainWindow::onNewTextDocument);
    connect(ui->btnCloneTool, &QPushButton::clicked,
            this, &MainWindow::onCloneTool);
}

MainWindow::~MainWindow() {
    delete ui;
    delete textEditor;
    delete palette;
}

void MainWindow::onNewTextDocument() {
    textEditor->NewDocument();
    QMessageBox::information(this, "Документ", "Текстовый документ создан!");
}

void MainWindow::onCloneTool() {
    Tool* tool = palette->GetTool("Линия");
    if (tool) {
        QMessageBox::information(this, "Инструмент",
                                 "Склонирован инструмент: " + tool->GetName());
        delete tool;
    }
}