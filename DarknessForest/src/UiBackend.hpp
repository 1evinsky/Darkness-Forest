#pragma once

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/Setting.hpp"

class UiBackend : public QObject
{
    Q_OBJECT
public:
    explicit UiBackend(QGuiApplication *aGuiApplication,
                       QQmlApplicationEngine *qmlEngine,
                       QObject *parent = nullptr);

    void start();

signals:

private:
    QGuiApplication *mGuiApplication = nullptr;
    QQmlApplicationEngine *mQmlEngine = nullptr;
    Setting *mSetting = nullptr;
};

