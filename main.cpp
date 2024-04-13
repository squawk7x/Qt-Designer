#include "watch.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // qDebug() << "hola mundo";
    // qInfo() << "Hello World";
    // qWarning() << "Warning";
    // qCritical() << "Critical";
    // qFatal() << "Fatal";
    Watch w;
    w.show();
    return a.exec();
}
