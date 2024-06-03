#include "principal.h"
#include "ui_principal.h"
#include "admindb.h"

Principal::Principal(QWidget *parent) : QWidget(parent), ui(new Ui::Principal)
{
    ui->setupUi(this);

       AdminDB adminDB;
       Linea linea(0,0,0,0);

       if (adminDB.conectar("D:/Usuario Lab/Documentos/simulacro-parcial2-ejercicio-a/db.sqlite")) {
           qDebug() << "Conexion exitosa";
           adminDB.leerLineas();
           linea = adminDB.leerLinea();
       } else {
           qDebug() << "Conexion NO exitosa";
       }

       // Establece las coordenadas de la línea
       m_xInicial = linea.getXInicial();
       m_yInicial = linea.getYInicial();
       m_xFinal = linea.getYFinal();
       m_yFinal = linea.getYFinal();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine)); // Establece el color y el grosor de la línea

    // Dibuja la línea usando las coordenadas almacenadas
    painter.drawLine(m_xInicial, m_yInicial, m_xFinal, m_yFinal);
}

void Principal::setDatosLinea(int xInicial, int yInicial, int xFinal, int yFinal) {
    m_xInicial = xInicial;
    m_yInicial = yInicial;
    m_xFinal = xFinal;
    m_yFinal = yFinal;
    update(); // Señala que el widget necesita ser repintado
}
