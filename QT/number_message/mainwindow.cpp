#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <cstring>

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
    QString numberStr = ui->lineEdit->text();
    bool ok;
    int number = numberStr.toInt(&ok);
    if(!ok){
        QMessageBox::information(this,"Ошибка","Введите число!");
        return;
    }
    if(number<=-1000&&number>=1000){
        QMessageBox::information(this,"Ошибка","Введите число от -999 до 999");
        return;
    }

    QString plusMinus;
    QString colNum;
    if(number!=0){
        if(number>0){
            plusMinus = "положительное";
        }
        else if(number<0){
            plusMinus = "отрицательное";
        }


        if (number<=9&&number>=-9){
            colNum = "однозначное число";
        }
        else if(number<=99&&number>=-99){
            colNum = "двухзначное число";
        }
        else {
            colNum = "трехзначное число";
        }
        QMessageBox::information(this,plusMinus,colNum);
        return;
    }
    else{
        QMessageBox::information(this,"Нулевое","число");
        return;
    }

}

