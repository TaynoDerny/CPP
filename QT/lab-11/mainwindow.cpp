#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("ЛР №11: Движение шарика");

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *layout = new QVBoxLayout(central);

    glWidget = new GLWidget(this);

    layout->addWidget(glWidget);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, glWidget, &GLWidget::moveBall);
    timer->start(30); // Обновление кадра каждые 30 миллисекунд
}

MainWindow::~MainWindow()
{

}