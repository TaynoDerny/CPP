#ifndef MATRIXGUI_H
#define MATRIXGUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class matrixgui;
}
QT_END_NAMESPACE

class matrixgui : public QMainWindow
{
    Q_OBJECT

public:
    explicit matrixgui(QWidget *parent = nullptr);
    ~matrixgui() override;

private slots:
    void on_pushButton_clicked();

private:
    Ui::matrixgui *ui;
    QVector <QVector <int> > matrix;
    int strCount;
};
#endif // MATRIXGUI_H
