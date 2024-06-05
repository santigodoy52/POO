#include <QApplication>
#include <QDebug>
#include <QDir>
#include "admindb.h"
#include "login.h"
#include "ventana.h"
#include "admin.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );
    Admin admin;
    admin.iniciar();
    return a.exec();
}
