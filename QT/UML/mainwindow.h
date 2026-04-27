#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TextDocument.h"
#include "GraphicDocument.h"
#include <QMdiSubWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionNewText_triggered();

    void on_actionOpenText_triggered();

    void on_actionOpenImage_triggered();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionCopy_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
