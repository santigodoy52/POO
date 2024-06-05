#include "admin.h"
#include "login.h"
#include "ventana.h"

Admin::Admin(QObject *parent) : QObject(parent), login(new Login()), ventana(new Ventana())
{
    connect(this->login, SIGNAL(signal_ingresar()), this->ventana, SLOT(show()));
    connect(this->ventana, SIGNAL(signal_volver()), this->login, SLOT(show()));
}

void Admin::iniciar()
{
    this->login->show();
}
