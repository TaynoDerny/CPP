#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CatalogWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openCatalog();

private:
    CatalogWindow *catalog;
};

#endif // MAINWINDOW_H