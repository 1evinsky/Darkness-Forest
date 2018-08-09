#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWidget display;
    display.show();
    //test
    return app.exec();
}
