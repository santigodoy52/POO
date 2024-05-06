#include <QApplication>
#include <QDebug>
#include <QDir>
#include "adminDB.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );

    qDebug() << QDir::currentPath();

    AdminDB adminDB;
    if (adminDB.conectar( "D:/Usuario Lab/Documentos/POO/db.sqlite" ) )
    {
        qDebug() << "Conexion exitosa";
        adminDB.mostrarUsuarios();

        QString nombre = "cgomez";
        QString password = "1234";

        if (adminDB.validarUsuario(nombre, password)) {
            qDebug() << "Usuario válido.";
        } else {
            qDebug() << "Usuario inválido.";
        }
    }
    else
        qDebug() << "Conexion NO exitosa";

return 0;
}
