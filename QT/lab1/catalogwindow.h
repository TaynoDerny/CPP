#ifndef CATALOGWINDOW_H
#define CATALOGWINDOW_H

#include <QWidget>

class MainWindow;
class OrderWindow;
class QCloseEvent;

class CatalogWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CatalogWindow(MainWindow *mainWin);
    ~CatalogWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void openOrder();

private:
    MainWindow *mainWindow;
    OrderWindow *order;
};

#endif // CATALOGWINDOW_H