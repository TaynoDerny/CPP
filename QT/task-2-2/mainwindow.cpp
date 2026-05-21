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

    ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    ui->textEdit->setTabStopDistance(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnGenerate_clicked()
{
    int m = ui->lineEditM->text().toInt();
    int n = ui->lineEditN->text().toInt();

    if (m <= 0 || n <= 0) {
        QMessageBox::warning(this, "Ошибка", "Введите корректные размеры!");
        return;
    }

    matrix.clear();
    ui->textEdit->clear();

    for (int i = 0; i < m; i++) {
        QVector<int> row;
        QString rowStr = "";
        for (int j = 0; j < n; j++) {
            int val = rand() % 10 + 1;
            row.append(val);
            rowStr += QString::number(val) + "\t";
        }
        matrix.append(row);
        ui->textEdit->append(rowStr);
    }
}

void MainWindow::on_btnCalculate_clicked()
{
    if (matrix.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Сначала создайте матрицу!");
        return;
    }

    int k = ui->lineEditK->text().toInt();
    int n = matrix[0].size();
    int m = matrix.size();
    int targetK = k - 1;

    if (targetK < 0 || targetK >= n) {
        QMessageBox::critical(this, "Ошибка", "Столбца №" + QString::number(k) + " не существует!");
        return;
    }

    QString resultText;

    if (ui->comboBox->currentIndex() == 0) {
        long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += matrix[i][targetK];
        }
        resultText = "Сумма " + QString::number(k) + "-го столбца: " + QString::number(sum);
    }
    else {
        long long prod = 1;
        for (int i = 0; i < m; i++) {
            prod *= matrix[i][targetK];
        }
        resultText = "Произведение " + QString::number(k) + "-го столбца: " + QString::number(prod);
    }

    QMessageBox::information(this, "Результат расчета", resultText);
}