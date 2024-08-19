#include "Setting.hpp"

#include <QSettings>
#include <QDateTime>

Setting::Setting(QObject *parent)
    : QObject{parent}
{
    QSettings setting("MySoft", "Darkness Forest");

    setting.beginGroup("General");
    qDebug() << ">>>> " << setting.contains("install");


    if(!setting.contains("install"))
        setting.setValue("install", QDateTime::currentDateTime());

    setting.endGroup();

    setting.sync();

    qDebug() << setting.fileName() << setting.value("General/install") << setting.allKeys();

}

