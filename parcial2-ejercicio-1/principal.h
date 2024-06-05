#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QPainter>
#include "rectangulo.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    void setDatosLinea(int x, int y, int ancho, int alto);
    explicit Principal(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~Principal();

private:
    Ui::Principal *ui;
     QVector<Rectangulo> rectangulos;
    int x;
    int y;
    int ancho;
    int alto;
};

#endif // PRINCIPAL_H
