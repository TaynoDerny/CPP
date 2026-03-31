#include <QCoreApplication>
#include<QTextStream>

int main()
{
    QVector< QVector<int> > matrix;
    srand(time(0));
    for (int i = 1; i <= 3; i++) {
        QVector<int> line;
        for (int j =1; j <= 3; j++) {
            line.append(rand() % 100 + 100); }
        matrix.append(line);}
    QTextStream stream(stdout);
    for (int i = 0; i < matrix.length(); i++) {
        QString str = "";
        for (int j = 0; j < matrix[i].length(); j++) {
            str += QString::number(matrix[i][j])+ " "; }
        stream << str << "\n";
        stream.flush(); }
    int max = matrix[0][0];
    for (int i = 0; i < matrix.length(); i++) {
        for (int j = 0; j < matrix[i].length(); j++) {
            if (matrix[i][j] > max) {max = matrix[i][j];} } }
    stream << "Максимальный элемент:" << max << "\n";
    stream.flush();
}
