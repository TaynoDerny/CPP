#include "matrixgui.h"
#include "ui_matrixgui.h"

matrixgui::matrixgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::matrixgui)
{
    ui->setupUi(this);



    for (int i = 0; i < 5; i++) {
        QVector<int> vec;
        for (int j = 0; j <= i; j++) {
            vec.append(i*j); }
        matrix.append(vec); }
    strCount = 5;
    ui->textEdit->clear();
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += QString::number(matrix[i][j])+" | "; }
        ui->textEdit->append(str);}
}

matrixgui::~matrixgui()
{
    delete ui;
}

void matrixgui::on_pushButton_clicked()
{
    QVector<int> line;
    for (int j = 0; j <= strCount; j++) { // заполнение вектора значениями
        line.append(strCount*j); }
    matrix.append(line);
    // добавление в матрицу вектора
    strCount++;
    if (strCount > 10) {
        //если количество строк >10 стираем матрицу
        matrix.clear();
        strCount = 0; }
    // количество строк устанавливаем в 0
    ui->textEdit->setText("strCount: " + QString::number(strCount));
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += " "+QString::number(matrix[i][j])+" | "; }
        ui->textEdit->append(str); } // вывод в textEdit
}

