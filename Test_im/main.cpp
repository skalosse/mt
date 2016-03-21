#include "maintest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maintest w;
    w.show();

    return a.exec();
}
