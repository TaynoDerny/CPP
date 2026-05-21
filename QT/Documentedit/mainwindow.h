#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "texteditor.h"
#include "toolpalette.h"

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
    void onNewTextDocument();
    void onCloneTool();

private:
    Ui::MainWindow *ui;
    TextEditor* textEditor;
    ToolPalette* palette;
};

#endif