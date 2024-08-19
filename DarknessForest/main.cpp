#include <QQmlApplicationEngine>
#include <QGuiApplication>

#include "src/UiBackend.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication *app = new QGuiApplication(argc, argv);

    QCoreApplication::setApplicationName("Darkness Forest");
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();

    UiBackend backend(app, engine);

    backend.start();

    return app->exec();
}
