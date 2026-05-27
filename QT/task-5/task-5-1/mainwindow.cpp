#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList names = {"Анна", "Иван", "Олег", "Мария", "Игорь"};
    ui->textEdit_log->append("<b>Список учеников и их гостей:</b>");

    for (const QString &host : names) {
        QSet<QString> guests;
        for (const QString &guest : names) {
            if (host != guest && QRandomGenerator::global()->bounded(2) == 1) {
                guests.insert(guest);
            }
        }
        classVisits[host] = guests;

        QStringList list;
        for (const QString &g : guests) {
            list.append(g);
        }
        ui->textEdit_log->append(host + " принимал(а): " + list.join(", "));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_check_clicked()
{
    int totalStudents = classVisits.size();
    int targetVisits = totalStudents - 1;

    QMap<QString, int> visitCounter;

    for (auto it = classVisits.begin(); it != classVisits.end(); ++it) {
        visitCounter[it.key()] = 0;
    }

    // Подсчет визитов
    for (auto it = classVisits.begin(); it != classVisits.end(); ++it) {
        QSet<QString> guests = it.value();
        for (const QString &guest : guests) {
            if (visitCounter.contains(guest)) {
                visitCounter[guest]++;
            }
        }
    }

    // Поиск супер-гостя
    QString superGuest = "";
    for (auto it = visitCounter.begin(); it != visitCounter.end(); ++it) {
        if (it.value() == targetVisits) {
            superGuest = it.key();
            break;
        }
    }

    if (!superGuest.isEmpty()) {
        ui->lineEdit_result->setText("Да, это " + superGuest + ", посетил(а) домов: " + QString::number(targetVisits));
    } else {
        ui->lineEdit_result->setText("Такого человека в классе нет.");
    }
}