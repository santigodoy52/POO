#include "button.h"
#include <QPainter>

Boton::Boton(QWidget *parent) : QWidget(parent), color(Azul) {}

void Boton::colorear(Color nuevoColor) {
    color = nuevoColor;
    update(); // Se solicita un repintado del widget
}

void Boton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Configurar el color según la enumeración
    QColor botonColor;
    switch (color) {
        case Azul:
            botonColor = Qt::blue;
            break;
        case Verde:
            botonColor = Qt::green;
            break;
        case Magenta:
            botonColor = Qt::magenta;
            break;
    }

    // Dibujar el botón con el color seleccionado
    painter.fillRect(rect(), botonColor);
}
