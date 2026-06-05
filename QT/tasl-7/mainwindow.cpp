#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h> /
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memory = 0.0;

    // цифры
    connect(ui->pushButton_0, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onDigitPressed);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onDigitPressed);

    //  базовые операции
    connect(ui->pushButton_Add, &QPushButton::clicked, this, &MainWindow::onMathButtonPressed);
    connect(ui->pushButton_Sub, &QPushButton::clicked, this, &MainWindow::onMathButtonPressed);
    connect(ui->pushButton_Mul, &QPushButton::clicked, this, &MainWindow::onMathButtonPressed);
    connect(ui->pushButton_Div, &QPushButton::clicked, this, &MainWindow::onMathButtonPressed);
    connect(ui->pushButton_Equal, &QPushButton::clicked, this, &MainWindow::onEqualButtonPressed);

    // Вспомогательные кнопки
    connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::onClearButtonPressed);
    connect(ui->pushButton_Dot, &QPushButton::clicked, this, &MainWindow::onDotButtonPressed);
    connect(ui->pushButton_Sign, &QPushButton::clicked, this, &MainWindow::onSignButtonPressed);

    // Функции 1 группы
    connect(ui->pushButton_Cos, &QPushButton::clicked, this, &MainWindow::onCosPressed);
    connect(ui->pushButton_Lg, &QPushButton::clicked, this, &MainWindow::onLgPressed);
    connect(ui->pushButton_Sqr, &QPushButton::clicked, this, &MainWindow::onSqrPressed);
    connect(ui->pushButton_Sqrt, &QPushButton::clicked, this, &MainWindow::onSqrtPressed);

    // Память
    connect(ui->pushButton_MS, &QPushButton::clicked, this, &MainWindow::onMSPressed);
    connect(ui->pushButton_MR, &QPushButton::clicked, this, &MainWindow::onMRPressed);
    connect(ui->pushButton_MC, &QPushButton::clicked, this, &MainWindow::onMCPressed);
    connect(ui->pushButton_MPlus, &QPushButton::clicked, this, &MainWindow::onMPlusPressed);
    connect(ui->pushButton_MMinus, &QPushButton::clicked, this, &MainWindow::onMMinusPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDigitPressed()
{
    QPushButton *button = (QPushButton*)sender();
    ui->lineEdit->insert(button->text());
}

void MainWindow::onMathButtonPressed()
{
    QPushButton *button = (QPushButton*)sender();
    calculate(button->text());
}

void MainWindow::onEqualButtonPressed()
{
    calculate("=");
}

void MainWindow::calculate(QString sgn)
{
    if (ui->lineEdit->text().isEmpty() && stack.isEmpty()) return;

    if (!ui->lineEdit->text().isEmpty()) {
        stack.push(ui->lineEdit->text());
    }

    if (stack.length() >= 3) {
        double val2 = stack.pop().toDouble();
        QString op = stack.pop();
        double val1 = stack.pop().toDouble();
        double result = 0.0;

        if (op == "+") result = val1 + val2;
        else if (op == "-") result = val1 - val2;
        else if (op == "*") result = val1 * val2;
        else if (op == "/") {
            if (val2 == 0) {
                ui->lineEdit->setText("Деление на 0 ");
                stack.clear();
                return;
            }
            result = val1 / val2;
        }
        stack.push(QString::number(result));
    }

    if (sgn != "=") {
        stack.push(sgn);
        ui->lineEdit_2->setText(stack.toList().join(" "));
        ui->lineEdit->clear();
    } else {
        ui->lineEdit->setText(stack.pop());
        ui->lineEdit_2->clear();
    }
}

void MainWindow::onClearButtonPressed()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    stack.clear();
}

void MainWindow::onDotButtonPressed()
{
    QString text = ui->lineEdit->text();
    if (text.isEmpty() || text.at(text.length() - 1) == '-' || text.indexOf('.') != -1) return;
    ui->lineEdit->setText(text + ".");
}

void MainWindow::onSignButtonPressed()
{
    QString text = ui->lineEdit->text();
    if (text.length() == 0 || text.at(0) != '-') {
        ui->lineEdit->setText("-" + text);
    } else {
        text.remove(0, 1);
        ui->lineEdit->setText(text);
    }
}


void MainWindow::onCosPressed()
{
    if (ui->lineEdit->text().isEmpty()) return;
    double val = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(qCos(val)));
}

void MainWindow::onLgPressed()
{
    if (ui->lineEdit->text().isEmpty()) return;
    double val = ui->lineEdit->text().toDouble();
    if (val > 0) {
        ui->lineEdit->setText(QString::number(log10(val)));
    } else {
        ui->lineEdit->setText("Ошибка");
    }
}

void MainWindow::onSqrPressed()
{
    if (ui->lineEdit->text().isEmpty()) return;
    double val = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(val * val));
}

void MainWindow::onSqrtPressed()
{
    if (ui->lineEdit->text().isEmpty()) return;
    double val = ui->lineEdit->text().toDouble();
    if (val >= 0) {
        ui->lineEdit->setText(QString::number(qSqrt(val)));
    } else {
        ui->lineEdit->setText("Ошибка");
    }
}

// память

void MainWindow::onMSPressed()
{
    memory = ui->lineEdit->text().toDouble();
}

void MainWindow::onMRPressed()
{
    ui->lineEdit->setText(QString::number(memory));
}

void MainWindow::onMCPressed()
{
    memory = 0.0;
}

void MainWindow::onMPlusPressed()
{
    memory += ui->lineEdit->text().toDouble();
}

void MainWindow::onMMinusPressed()
{
    memory -= ui->lineEdit->text().toDouble();
}
