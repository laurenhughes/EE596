#include <QtWidgets/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
    qputenv("QT_SCALE_FACTOR", "0.75"); // use a suitable scaling factor

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
