#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    // Файл
    void onNewDocument();
    void onOpenDocument();
    void onSaveDocument();
    void onPrintDocument();

    // Правка
    void onInsertDate();
    void onDeleteText();

    // Вид
    void onSelectFont();
    void onAlignLeft();
    void onAlignCenter();
    void onAlignRight();

    // Найти
    void onGoToLine();
    void onFindWord();
    void onReplaceWord();

    // Справка
    void onAboutProgram();

private:
    Ui::MainWindow *ui;
    QString _copytext;
};

#endif // MAINWINDOW_H
