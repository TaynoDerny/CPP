#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void onReplaceButtonClicked();
private:
    QTextEdit *textEdit;
    QPushButton *button;
};

#endif // MAINWINDOW_H