#include "mainwindow.h"
#include "catalogwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), catalog(nullptr)
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);
    setCentralWidget(central);
    setWindowTitle("Интернет-магазин");
    resize(500, 400);

    QPushButton *btn = new QPushButton("Каталог товаров", this);
    btn->setMinimumSize(300, 150);
    btn->setStyleSheet("font-size: 20px; background-color: #e0f7fa; border: 2px solid #006064;");
    layout->addWidget(btn, 0, Qt::AlignCenter);

    catalog = new CatalogWindow(this);

    connect(btn, &QPushButton::clicked, this, &MainWindow::openCatalog);
}

MainWindow::~MainWindow() {}

void MainWindow::openCatalog()
{
    catalog->show();
    this->hide();
}