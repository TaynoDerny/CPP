#include "editorapplication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    editorapplication w;
    w.show();
    return QCoreApplication::exec();
}
