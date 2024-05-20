
#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class LoginWidget;
class VentanaWidget;

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);
    void iniciar();
private:
    LoginWidget* login;
    VentanaWidget* ventana;
};

#endif // MANAGER_H
