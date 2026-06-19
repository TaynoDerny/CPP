#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class ClockWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generateNumbers();

private:
    QTextEdit *txtNumbers;
    ClockWidget *clockWidget;
};

#endif // MAINWINDOW_H