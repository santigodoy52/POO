// pintura.cpp
#include "Pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent): QWidget(parent), colorPincel(Qt::black), grosorPincel(2){
}

void Pintura::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (int i = 1; i < puntos.size(); ++i) {
        painter.setPen(QPen(colorPincel, grosorPincel, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(puntos[i - 1], puntos[i]);
    }
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    int delta = event->angleDelta().y();
    if (delta > 0)
        grosorPincel += 2;
    else
        grosorPincel = std::max(2, grosorPincel - 2);
    event->accept();
    update();
}


void Pintura::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        puntos.clear();
        puntos.append(event->pos());
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
        puntos.append(event->pos());
    update();
}

void Pintura::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        limpiarPantalla();
    } else if (event->key() == Qt::Key_R) {
        colorPincel = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        colorPincel = Qt::green;
    } else if (event->key() == Qt::Key_B) {
        colorPincel = Qt::blue;
    } else if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Equal) {
        grosorPincel += 2;
    } else if (event->key() == Qt::Key_Minus) {
        if (grosorPincel > 2)
            grosorPincel -= 2;
    }
}

void Pintura::limpiarPantalla()
{
    puntos.clear();
    update();
}
