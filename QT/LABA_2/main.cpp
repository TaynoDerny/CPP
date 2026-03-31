#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QVector>
#include <QString>
#include <QDebug>
#include <QList>

int main()
{
    qDebug() << "Введите пять целых чисел: ";
    //Класс QTextStream используется для чтения и записи текста
    QTextStream in(stdin); // указываем клавиатуру устройством ввода
    QVector<int> vec2;
    for (int i = 0; i < 5; i++) {
        int num = (in.readLine()).toInt(); // считываем строку и
        //преобразовываем её в целое
        vec2.append(num); } // добавляем элементы в конец массива
    qDebug() << vec2;
    int sum2=0;
    for (int i=0; i<vec2.size(); i++ ) {
        if (vec2[i] > 0) {sum2 += vec2[i]; } }
    qDebug() << "Сумма положительных чисел = " << sum2;
    return 0;
}
