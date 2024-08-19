
#ifndef SETTING_HPP
#define SETTING_HPP


#include <QObject>


class Setting : public QObject
{
    Q_OBJECT
public:
    explicit Setting(QObject *parent = nullptr);

signals:

};

#endif // SETTING_HPP
