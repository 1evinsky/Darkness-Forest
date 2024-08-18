
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QCoreApplication::setApplicationName("Darkness Forest");
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");

    QSettings setting("MySoft", "Darkness Forest");

    setting.beginGroup("General");
    qDebug() << ">>>> " << setting.contains("install");


    if(!setting.contains("install"))
        setting.setValue("install", QDateTime::currentDateTime());

    setting.endGroup();

    setting.sync();

    qDebug() << setting.fileName() << setting.value("General/install") << setting.allKeys();

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/DarknessForest/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
