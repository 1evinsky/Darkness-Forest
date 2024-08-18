
#ifndef UIBACKEND_HPP
#define UIBACKEND_HPP


#include <QObject>


class UiBackend : public QObject
{
    Q_OBJECT
public:
    explicit UiBackend(QObject *parent = nullptr);

signals:

};

#endif // UIBACKEND_HPP
