#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MediaWindow w;
    w.show();

    return a.exec();
}
