#include <QApplication>
#include "descargador.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Descargador ventanaDescargador;
    ventanaDescargador.show();

    return app.exec();
}
