#include <QApplication>
#include "acceso.h"
#include "ventana.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear la ventana de acceso
    Acceso acceso;

    // Crear la ventana principal
    Ventana ventana;

    // Establecer conexión para mostrar la ventana principal al iniciar sesión correctamente
    QObject::connect(&acceso, &Acceso::loginSuccess, [&]() {
        ventana.show();
    });

    // Mostrar la ventana de acceso
    acceso.show();

    return app.exec();
}
