#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QWidget>

class MainWindow;
class QCloseEvent;

class OrderWindow : public QWidget
{
    Q_OBJECT
public:
    explicit OrderWindow(MainWindow *mainWin);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void finishOrder();

private:
    MainWindow *mainWindow;
};

#endif // ORDERWINDOW_H