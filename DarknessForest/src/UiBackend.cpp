#include "UiBackend.hpp"
#include <QQmlContext>

UiBackend::UiBackend(QGuiApplication *aGuiApplication,
                     QQmlApplicationEngine *qmlEngine,
                     QObject *parent)
    : mGuiApplication{aGuiApplication},
    mQmlEngine{qmlEngine},
    QObject{parent}
{
    mSetting = new Setting();
    mQmlEngine->rootContext()->setContextProperty("setting", mSetting);
}

void UiBackend::start()
{
    const QUrl url(u"qrc:/DarknessForest/Main.qml"_qs);

    QObject::connect(mQmlEngine, &QQmlApplicationEngine::objectCreationFailed,
        mGuiApplication, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    mQmlEngine->load(url);
}

