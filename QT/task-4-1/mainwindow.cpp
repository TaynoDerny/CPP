#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCreateStack_clicked()
{
    myStack.clear();
    ui->textEdit->clear();

    for(int i = 0; i < 10; i++) {
        int val = (rand() % 31) - 10;
        myStack.push(val);
        ui->textEdit->append(QString::number(val)); // Вывод в поле
    }
}

// сумма
void MainWindow::on_btnCalcStack_clicked()
{
    if (myStack.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Стек пуст! Сначала создайте его.");
        return;
    }

    int sumPos = 0;

    for(int i = 0; i < myStack.count(); i++) {
        int current = myStack.at(i);
        if (current > 0) {
            sumPos += current;
        }
    }

    QMessageBox::information(this, "Результат","Сумма положительных чисел в стеке: " + QString::number(sumPos));
}