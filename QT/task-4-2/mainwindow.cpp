#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

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

void MainWindow::on_pushButton_generate_clicked()
{
    myQueue.clear();
    ui->textEdit->clear();

    for(int i = 0; i < 8; i++) {
        int val = QRandomGenerator::global()->bounded(1, 100);
        myQueue.enqueue(val);
        ui->textEdit->append(QString::number(val));
    }
}

void MainWindow::on_pushButton_calculate_clicked()
{
    if (myQueue.isEmpty()) return;

    QString output = "";

    QQueue<int> diffQueue;

    for(int i = 0; i < myQueue.size() - 1; i++) {
        int val1 = myQueue[i];
        int val2 = myQueue[i+1];
        int diff = qAbs(val1 - val2);

        diffQueue.enqueue(diff);

        output += QString("|%1 - %2| = %3\n").arg(val1).arg(val2).arg(diff);
    }

    QMessageBox::information(this, "Результат", output);
}