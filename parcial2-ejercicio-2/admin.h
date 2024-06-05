
#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Login;
class Ventana;

class Admin : public QObject
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);
    void iniciar();
private:
    Login* login;
    Ventana* ventana;
};

#endif // MANAGER_H
