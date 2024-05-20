#include <QApplication>
#include <QDebug>
#include <QDir>
#include "admindb.h"
#include "login.h"
#include "ventana.h"
#include "manager.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );
    Manager manager;
    manager.iniciar();
    return a.exec();
}
