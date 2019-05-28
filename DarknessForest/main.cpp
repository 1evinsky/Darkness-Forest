#include <QApplication>
#include <QDir>

#include "logic/mainsettings.h"

int main(int argc, char *argv[])
{
    auto appDirPath = QDir::currentPath();
    auto pathToIniFile = appDirPath + "/settings/MainSetting.ini";

    MainSettings app(argc, argv, pathToIniFile);

    return app.exec();
}
