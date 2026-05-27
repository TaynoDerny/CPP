#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioAdd->setChecked(true);

    on_btnFill_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateListDisplay()
{
    ui->listWidget->clear();
    for (int val : list) {
        ui->listWidget->addItem(QString::number(val));
    }
}

void MainWindow::on_btnFill_clicked()
{
    list.clear();
    for (int i = 0; i < 10; ++i) {
        list.append(QRandomGenerator::global()->bounded(1, 100));
    }
    updateListDisplay();
}

void MainWindow::on_btnAdd_clicked()
{
    if (!ui->radioAdd->isChecked()) {
        QMessageBox::information(this, "Внимание", "Выберите 'Добавление'");
        return;
    }

    bool ok;
    int val = ui->lineEditInput->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Введите целое число!");
        return;
    }

    list.append(val);
    updateListDisplay();
    ui->lineEditInput->clear();
}

void MainWindow::on_btnRemove_clicked()
{
    if (!ui->radioRemove->isChecked()) {
        QMessageBox::information(this, "Внимание", "Выберите 'Удаление'");
        return;
    }

    if (list.isEmpty()) {
        QMessageBox::information(this, "Внимание", "Список пуст!");
        return;
    }

    list.removeLast();
    updateListDisplay();
}