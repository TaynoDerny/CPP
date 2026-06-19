#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QTextEdit;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOpenFile(); // Слот для кнопки

private:
    QPushButton *btnOpen;
    QTextEdit *textEdit;
    QLabel *lblInfo;
};

#endif // MAINWINDOW_H