#include "mainsettings.h"

MainSettings::MainSettings(int &argc, char **argv, const QString &pathToIniFile)
    : QApplication(argc, argv)
{
    mSettings = new QSettings(pathToIniFile, QSettings::IniFormat, this);
}

MainSettings *MainSettings::theApp()
{
    return static_cast<MainSettings*>(qApp);
}

QSettings *MainSettings::settings()
{
    return mSettings;
}

