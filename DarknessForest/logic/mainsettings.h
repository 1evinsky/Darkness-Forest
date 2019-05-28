#pragma once
#include <QApplication>
#include <QSettings>

class MainSettings : public QApplication
{
    Q_OBJECT
public:
    MainSettings(int& argc, char** argv, const QString& pathToIniFile);

    static MainSettings* theApp();

    QSettings* settings();

private:
    QSettings *mSettings = nullptr;
};

