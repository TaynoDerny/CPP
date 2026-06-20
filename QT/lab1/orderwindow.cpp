#include "orderwindow.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCloseEvent>

OrderWindow::OrderWindow(MainWindow *mainWin)
    : QWidget(nullptr, Qt::Window), // Создаем как отдельное независимое окно
    mainWindow(mainWin)
{
    setWindowTitle("Оформление заказа");
    resize(450, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(15);
    layout->setAlignment(Qt::AlignCenter);

    // Информация о заказе
    QLabel *titleLabel = new QLabel("Оформление заказа");
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: white;");
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QLabel *descLabel = new QLabel("Товар: Осенняя куртка\nСтоимость: 2500 руб.");
    descLabel->setStyleSheet("font-size: 16px; color: #ccc;");
    descLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(descLabel);

    layout->addStretch();

    // Кнопка подтверждения
    QHBoxLayout *btnLayout = new QHBoxLayout();
    QPushButton *btnFinish = new QPushButton("Оформить заказ", this);
    btnFinish->setFixedSize(180, 50);
    btnFinish->setStyleSheet("font-size: 16px; background-color: #4caf50; color: white; border: none; border-radius: 5px;");
    btnLayout->addStretch();
    btnLayout->addWidget(btnFinish);
    btnLayout->addStretch();
    layout->addLayout(btnLayout);

    connect(btnFinish, &QPushButton::clicked, this, &OrderWindow::finishOrder);
}

void OrderWindow::finishOrder()
{
    mainWindow->show();
    this->close();
}

void OrderWindow::closeEvent(QCloseEvent *event)
{
    mainWindow->show();
    event->accept();
}