#include <QCoreApplication>
#include <QVector>
#include <QString>
#include <QList>
#include <QDebug>
#include <QTextStream>
#include <QString>

int main()
{
    srand(time(0));

    QTextStream in(stdin);
    QTextStream out(stdout);


    out << "Введите число: \n";
    out.flush();
    int N = in.readLine().toInt();

    QVector<int> vec1(N);
    for (int var = 0; var < N; ++var) {
        vec1[var] = rand() % 100;
    }

    out << "\nВектор заполнен:\n";
    for (int i = 0; i < N; ++i) {
        out << vec1[i] << ", ";
    }
    out << "\n\nЭлементы в обратном порядке\n";
    for (int i = N-1; i>=0; --i) {
        out << vec1[i] << ", ";
    }
    out << "\n";




}
