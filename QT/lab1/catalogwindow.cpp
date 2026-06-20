#include "catalogwindow.h"
#include "mainwindow.h"
#include "orderwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCloseEvent>

CatalogWindow::CatalogWindow(MainWindow *mainWin)
    : QWidget(nullptr, Qt::Window), // Создаем как отдельное независимое окно
    mainWindow(mainWin)
{
    setWindowTitle("Каталог товаров");
    resize(600, 550);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(15);

    // Название и цена
    QLabel *titleLabel = new QLabel("Осенняя куртка");
    titleLabel->setStyleSheet("font-size: 22px; font-weight: bold; color: white;");
    layout->addWidget(titleLabel);

    QLabel *priceLabel = new QLabel("Цена: 2500 руб.");
    priceLabel->setStyleSheet("font-size: 16px; color: #a0a0a0;");
    layout->addWidget(priceLabel);

    // Картинка-заглушка (по центру)
    layout->addStretch();
    QLabel *image = new QLabel("ФОТОГРАФИЯ ТОВАРА");
    image->setFixedSize(300, 300);
    image->setStyleSheet("background-color: #555; border: 1px solid #777; color: white; font-weight: bold; font-size: 20px;");
    image->setAlignment(Qt::AlignCenter);
    layout->addWidget(image, 0, Qt::AlignCenter);
    layout->addStretch();

    // Кнопка "Заказать"
    QHBoxLayout *btnLayout = new QHBoxLayout();
    QPushButton *btnOrder = new QPushButton("Заказать", this);
    btnOrder->setFixedSize(150, 50);
    btnOrder->setStyleSheet("font-size: 16px; background-color: #2196f3; color: white; border: none; border-radius: 5px;");
    btnLayout->addStretch();
    btnLayout->addWidget(btnOrder);
    layout->addLayout(btnLayout);

    order = new OrderWindow(mainWindow); // Убрали this из конструктора!

    connect(btnOrder, &QPushButton::clicked, this, &CatalogWindow::openOrder);
}

CatalogWindow::~CatalogWindow() {}

void CatalogWindow::openOrder()
{
    order->show();
    this->hide();
}

void CatalogWindow::closeEvent(QCloseEvent *event)
{
    mainWindow->show();
    event->accept();
}