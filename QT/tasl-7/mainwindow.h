#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

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
    void onDigitPressed();
    void onMathButtonPressed();
    void onEqualButtonPressed();
    void onClearButtonPressed();
    void onDotButtonPressed();
    void onSignButtonPressed();

    // Задание 1 группы
    void onCosPressed();
    void onLgPressed();
    void onSqrPressed();
    void onSqrtPressed();

    // Работа с памятью
    void onMSPressed();
    void onMRPressed();
    void onMCPressed();
    void onMPlusPressed();
    void onMMinusPressed();

private:
    Ui::MainWindow *ui;
    QStack<QString> stack;
    double memory;

    void calculate(QString sgn);
};

#endif // MAINWINDOW_H
