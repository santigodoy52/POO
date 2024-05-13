#include <QApplication>
#include <QDebug>
#include <QDir>
#include "ventana.h"
#include "button.h"

int main( int argc, char** argv )  {
    QApplication a( argc, argv );
    //Ventana ventana;
    //ventana.show();
    Boton *boton = new Boton;
    // Especificar el color del botón
    boton->colorear(Boton::Verde);

    boton->show();
    return a.exec();
}
