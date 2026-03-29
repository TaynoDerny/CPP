#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <utility>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString firstNumStr = ui->lineEdit->text();
    QString secondNumStr = ui->lineEdit_2->text();
    QString thirdNumStr = ui->lineEdit_3->text();
    bool ok;


    float firstNum = firstNumStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::information(this,"Ошибка", "Введите число!");
        return; }
    float secondNum = secondNumStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::information(this,"Ошибка", "Введите число!");
        return; }
    float thirdNum = thirdNumStr.toFloat(&ok);
    if (!ok) {
        QMessageBox::information(this,"Ошибка", "Введите число!");
    }



    while(firstNum>secondNum || firstNum>thirdNum || secondNum>thirdNum || secondNum<firstNum){
        if (thirdNum<secondNum){
            ui -> lineEdit_2->setText(QString::number(thirdNum));
            ui -> lineEdit_3->setText(QString::number(secondNum));
            std::swap(thirdNum,secondNum);
        }

        if (secondNum<firstNum){
            ui -> lineEdit->setText(QString::number(secondNum));
            ui -> lineEdit_2->setText(QString::number(firstNum));
            std::swap(firstNum,secondNum);
        }
    }
}
