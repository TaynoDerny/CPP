#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <cmath>

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

void MainWindow::on_pushButton_process_clicked()
{
    ui->textEdit_source->clear();
    ui->textEdit_results->clear();

    // Выбираем файл через стандартное окно
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть файл f", "", "Текстовые файлы (*.txt);;Все файлы (*.*)");
    if (filePath.isEmpty()) return;

    QFile myFile(filePath);

    if (!myFile.exists()) {
        QMessageBox::warning(this, "Ошибка", "Файл не найден");
        return;
    }

    if (!myFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    QTextStream stream(&myFile);
    QString fileContent = stream.readAll();
    myFile.close();

    ui->textEdit_source->setText(fileContent);

    // Разбиваем текст на числа
    QStringList tokens = fileContent.split(" ", Qt::SkipEmptyParts);
    if (tokens.isEmpty()) {
        // Если через пробел не разбилось, пробуем по переносу строки
        tokens = fileContent.split("\n", Qt::SkipEmptyParts);
    }

    if (tokens.isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Файл пуст!");
        return;
    }


    double max_component = -999999999.0;
    double min_even_indexed = 999999999.0;
    double max_abs_odd_indexed = -1.0;
    double first_component = 0.0;
    double last_component = 0.0;

    bool hasEven = false;
    bool hasOdd = false;
    int validCount = 0;

    for (int i = 0; i < tokens.length(); i++) {
        QString cleanToken = tokens[i].trimmed();
        if (cleanToken.isEmpty()) continue;

        bool ok;
        double val = cleanToken.toDouble(&ok);
        if (!ok) continue;

        validCount++;
        int number = validCount; // Порядковый номер

        if (number == 1) {
            first_component = val;
        }
        last_component = val;

        // а) Наибольший компонент
        if (val > max_component) {
            max_component = val;
        }

        // б) Наименьший с четным номером
        if (number % 2 == 0) {
            hasEven = true;
            if (val < min_even_indexed) {
                min_even_indexed = val;
            }
        }

        // в) Наибольший модуль с нечетным номером
        if (number % 2 != 0) {
            hasOdd = true;
            double absVal = std::abs(val);
            if (absVal > max_abs_odd_indexed) {
                max_abs_odd_indexed = absVal;
            }
        }
    }

    if (validCount == 0) {
        QMessageBox::warning(this, "Ошибка", "В файле нет корректных чисел");
        return;
    }

    ui->textEdit_results->append("а) Наибольший компонент: " + QString::number(max_component));

    if (hasEven) {
        ui->textEdit_results->append("б) Наименьший с четным номером: " + QString::number(min_even_indexed));
    } else {
        ui->textEdit_results->append("б) Наименьший с четным номером: нет четных позиций");
    }

    if (hasOdd) {
        ui->textEdit_results->append("в) Наибольший модуль с нечетным номером: " + QString::number(max_abs_odd_indexed));
    } else {
        ui->textEdit_results->append("в) Наибольший модуль с нечетным номером: нет нечетных позиций");
    }

    double diff = first_component - last_component;
    ui->textEdit_results->append("г) Разность первого и последнего (" + QString::number(first_component) + " - " +QString::number(last_component) + "): " + QString::number(diff));
}