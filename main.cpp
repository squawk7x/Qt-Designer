#include "watch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Watch w;
    w.show();
    return a.exec();
}
