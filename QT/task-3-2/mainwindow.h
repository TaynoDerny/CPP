#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFill_clicked();
    void on_btnCopy_clicked();

private:
    Ui::MainWindow *ui;
    QList<int> list1;
    QList<int> list2;

    void updateDisplay();
};

#endif // MAINWINDOW_H