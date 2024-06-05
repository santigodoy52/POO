#include "principal.h"
#include "ui_principal.h"
#include "admindb.h"

Principal::Principal(QWidget *parent) : QWidget(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);
    resize(300, 300);

       AdminDB& adminDB = AdminDB::getInstance();

       if (adminDB.conectar("D:/Usuario Lab/Documentos/parcial2-ejercicio-1/rectangles.sqlite")) {
           qDebug() << "Conexion exitosa";
           adminDB.leerLineas();
             rectangulos = adminDB.leerRectangulos();
            for (const Rectangulo& rectangulo : rectangulos) {
                    x = rectangulo.getX();
                    y = rectangulo.getY();
                    ancho = rectangulo.getAncho();
                    alto = rectangulo.getAlto();
            }
       } else {
           qDebug() << "Conexion NO exitosa";
       }

}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine)); // Establece el color y el grosor de la línea

    // Dibujar todos los rectángulos almacenados en las coordenadas
    for (const Rectangulo& rectangulo : rectangulos) {
        painter.drawRect(rectangulo.getX(), rectangulo.getY(), rectangulo.getAncho(), rectangulo.getAlto());
    }
}

void Principal::setDatosLinea(int X, int Y, int Ancho, int Alto) {
    x = X;
    y = Y;
    ancho = Ancho;
    alto = Alto;
    update(); // Señala que el widget necesita ser repintado
}
