#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_btnFill_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    ui->textEditList1->clear();
    ui->textEditList2->clear();

    QString str1;
    QList<int>::iterator it1 = list1.begin();
    while (it1 != list1.end()) {
        str1 += QString::number(*it1) + " ";
        ++it1;
    }
    ui->textEditList1->setPlainText(str1);

    QString str2;
    QList<int>::iterator it2 = list2.begin();
    while (it2 != list2.end()) {
        str2 += QString::number(*it2) + " ";
        ++it2;
    }
    ui->textEditList2->setPlainText(str2);
}

void MainWindow::on_btnFill_clicked()
{
    list1.clear();
    list2.clear();

    for (int i = 0; i < 10; ++i) {
        list1.append(QRandomGenerator::global()->bounded(1, 100));
    }
    updateDisplay();
}

void MainWindow::on_btnCopy_clicked()
{
    list2.clear();
    QList<int>::iterator it = list1.begin();
    while (it != list1.end()) {
        list2.append(*it);
        ++it;
    }
    updateDisplay();
}